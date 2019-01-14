#include "Player.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Player::Player(const FilePath& aPath)
: mScript(new Script(aPath))
, mSceneIndex(0)
, mTextIndex(-1)
, mActorLeft(&script().actor(scene().initLeft()))
, mActorRight(&script().actor(scene().initRight()))
, mIsSpeech(false)
, mIsWaitSpeechEnd(-1)
{
    Window::Resize(854, 480);
    Graphics::SetBackground(script().setting().backgroundColor());
    TextToSpeech::SetSpeed(script().setting().speechSpeed());
}

//-----------------------------------------------------------------------------
void Player::tryReload()
{
    if (script().hasChanged()) {
        auto* old = mScript;
        mScript = new Script(script().path());
        delete old;
    }
}

//-----------------------------------------------------------------------------
void Player::update()
{
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

    Rect clickedRect(0, 326, Window::Width(), 140);

    if (mIsWaitSpeechEnd > 0) {
        --mIsWaitSpeechEnd;
    }

    if (mIsWaitSpeechEnd == 0 && !TextToSpeech::IsSpeaking() ||
        clickedRect.leftClicked()) {
        mIsWaitSpeechEnd = -1;

        if (mTextIndex < static_cast<int>(scene().texts().count()) - 1) {
            mTextIndex++;

            if (script().setting().textToSpeech()) {
                mIsSpeech = true;
            }

        } else {
            if (mSceneIndex < static_cast<int>(script().scenes().count()) - 1) {
                mSceneIndex++;

                if (scene().texts().count() > 0) {
                    mTextIndex = 0;
                } else {
                    mTextIndex = -1;
                }

                if (script().setting().textToSpeech()) {
                    mIsSpeech = true;
                }

                if (scene().hasInitLeft()) {
                    mActorLeft = &script().actor(scene().initLeft());
                }

                if (scene().hasInitRight()) {
                    mActorRight = &script().actor(scene().initRight());
                }
            }
        }
    } else if (clickedRect.rightClicked()) {
        if (mTextIndex > 0) { // Can't go back to -1
            mTextIndex--;
        }
    }

    if (mTextIndex >= 0) {
        const auto& text = scene().texts()[mTextIndex];

        if (text.actor().isLeft()) {
            Rect rect(160, 326, 564, 134);
            Shape2D::RectBalloon(rect, Vec2(110, Window::Height() - 90)).drawFrame(2, script().setting().fontColor());
            script().fontS()(text.text()).draw(rect.stretched(-6), script().setting().fontColor());

            mActorLeft = &text.actor();

            speech(text);

        } else {
            Rect rect(130, 326, 564, 134);
            Shape2D::RectBalloon(rect, Vec2(Window::Width() - 110, Window::Height() - 90)).drawFrame(2, script().setting().fontColor());
            script().fontS()(text.text()).draw(rect.stretched(-6), script().setting().fontColor());

            mActorRight = &text.actor();

            speech(text);
        }
    }

    mActorLeft->texture().resized(120).drawAt(70, Window::Height() - 70);
    mActorRight->texture().resized(120).drawAt(Window::Width() - 70, Window::Height() - 70);
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

