#include "Player.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Player::Player(const FilePath& aPath)
: mScript(new Script(aPath))
, mSceneIndex(0)
, mTextIndex(-1)
, mIsSpeech(false)
, mIsWaitSpeechEnd(-1)
{
    if (!script().isOpened()) {
        Print(U"Load failed.");
        return;
    }

    reset();

    mActorLeft = scene().initLeft();
    mActorRight = scene().initRight();
}

//-----------------------------------------------------------------------------
void Player::reset()
{
    Window::Resize(854, 480);
    Graphics::SetBackground(script().setting().backgroundColor());
    TextToSpeech::SetSpeed(script().setting().speechSpeed());
}

//-----------------------------------------------------------------------------
void Player::setTextIndexToFirst()
{
    if (scene().texts().count() > 0) {
        mTextIndex = 0;
    } else {
        mTextIndex = -1;
    }
}

//-----------------------------------------------------------------------------
void Player::setTextIndexToLast()
{
    mTextIndex = static_cast<int>(scene().texts().count()) - 1; // MEMO: -1 is a correct value
}

//-----------------------------------------------------------------------------
bool Player::nextTrigger(const Rect& aRect) const
{
    return aRect.leftClicked() || KeyRight.down() || KeySpace.down();
}

//-----------------------------------------------------------------------------
bool Player::prevTrigger(const Rect& aRect) const
{
    return aRect.rightClicked() || KeyLeft.down();
}

//-----------------------------------------------------------------------------
void Player::tryReload()
{
    if (script().hasChanged()) {
        auto* ptr = new Script(script().path());

        if (ptr->isOpened()) {
            ClearPrint();
            mScript.reset(ptr);
            reset();

            if (mSceneIndex > static_cast<int>(script().scenes().count()) - 1) {
                mSceneIndex = script().scenes().count() - 1;
                setTextIndexToFirst();
            } else {
                if (mTextIndex > static_cast<int>(scene().texts().count()) - 1) {
                   setTextIndexToLast();
                }
            }

            
        } else {
            Print(U"Reload failed.");
            delete ptr;
        }
    }
}

//-----------------------------------------------------------------------------
void Player::update()
{
    if (!script().isOpened()) {
        return;
    }

    if (scene().hasTexture()) {
        scene().texture().drawAt(
            Window::Width() / 2,
            (Window::Height() - 154) / 2
            );
    }

    if (scene().hasTitle()) {
        script().font()(scene().title()).drawAt(
            Window::Width() / 2,
            (Window::Height() - 154) / 2,
            script().setting().fontColor()
            );
    }

    Rect clickedRect(0, 0, Window::Width(), Window::Height());
    // Rect clickedRect(0, 326, Window::Width(), 140);

    if (mIsWaitSpeechEnd > 0) {
        --mIsWaitSpeechEnd;
    }

    if (mIsWaitSpeechEnd == 0 && !TextToSpeech::IsSpeaking() ||
        nextTrigger(clickedRect)) {
        mIsWaitSpeechEnd = -1;

        if (mTextIndex < static_cast<int>(scene().texts().count()) - 1) {
            mTextIndex++;

            if (script().setting().textToSpeech()) {
                mIsSpeech = true;
            }

        } else {
            if (mSceneIndex < static_cast<int>(script().scenes().count()) - 1) {
                mSceneIndex++;
                setTextIndexToFirst();

                if (script().setting().textToSpeech()) {
                    mIsSpeech = true;
                }

                if (scene().hasInitLeft()) {
                    mActorLeft = scene().initLeft();
                }

                if (scene().hasInitRight()) {
                    mActorRight = scene().initRight();
                }
            }
        }
    } else if (prevTrigger(clickedRect)) {
        if (mTextIndex > 0) { // Can't go back to -1
            mTextIndex--;
        } else if (mSceneIndex > 0) {
            mSceneIndex--;
            setTextIndexToLast();
        }
    }

    if (mTextIndex >= 0) {
        const auto& text = scene().texts()[mTextIndex];

        if (text.actor().isLeft()) {
            Rect rect(160, 326, 564, 134);
            Shape2D::RectBalloon(rect, Vec2(110, Window::Height() - 90)).drawFrame(2, script().setting().fontColor());
            script().fontS()(text.text()).draw(rect.stretched(-6), script().setting().fontColor());

            mActorLeft = text.actor().name();

            speech(text);

        } else {
            Rect rect(130, 326, 564, 134);
            Shape2D::RectBalloon(rect, Vec2(Window::Width() - 110, Window::Height() - 90)).drawFrame(2, script().setting().fontColor());
            script().fontS()(text.text()).draw(rect.stretched(-6), script().setting().fontColor());

            mActorRight = text.actor().name();

            speech(text);
        }
    }

    script().actor(mActorLeft).texture().resized(120).drawAt(70, Window::Height() - 70);
    script().actor(mActorRight).texture().resized(120).drawAt(Window::Width() - 70, Window::Height() - 70);
}

//-----------------------------------------------------------------------------
void Player::speech(const Text& aText)
{
    if (mIsSpeech) {
        TextToSpeech::Speak(aText.text());
        mIsSpeech = false;
        if (script().setting().autoPlay()) {
            mIsWaitSpeechEnd = 5;
        }
    }
}

}

