#include "Player.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Player::Player(const FilePath& aPath)
: mScript(aPath)
, mSceneIndex(0)
, mTextIndex(-1)
, mActorLeft(&script().actor(scene().initLeft()))
, mActorRight(&script().actor(scene().initRight()))
{
    Window::Resize(854, 480);
    Graphics::SetBackground(scene().backgroundColor());
}

//-----------------------------------------------------------------------------
void Player::tryReload()
{
}

//-----------------------------------------------------------------------------
void Player::update()
{
    script().font()(scene().title()).drawAt(
        Window::Width() / 2,
        (Window::Height() - 140) / 2,
        Palette::White
    );

    Rect clickedRect(0, 326, Window::Width(), 140);

    if (clickedRect.leftClicked()) {
        mTextIndex++;
    } else if (clickedRect.rightClicked()) {
        mTextIndex--;
    }

    if (mTextIndex >= 0) {
        const auto& text = scene().texts()[mTextIndex];

        if (text.actor().isLeft()) {
            Rect rect(160, 326, 564, 134);
            Shape2D::RectBalloon(rect, Vec2(110, Window::Height() - 90)).drawFrame(2, Palette::White);
            script().fontS()(text.text()).draw(rect.stretched(-6), Palette::White);

            mActorLeft = &text.actor();

        } else {
            Rect rect(130, 326, 564, 134);
            Shape2D::RectBalloon(rect, Vec2(Window::Width() - 110, Window::Height() - 90)).drawFrame(2, Palette::White);
            script().fontS()(text.text()).draw(rect.stretched(-6), Palette::White);

            mActorRight = &text.actor();
        }
    }

    mActorLeft->texture().resized(120).drawAt(70, Window::Height() - 70);
    mActorRight->texture().resized(120).drawAt(Window::Width() - 70, Window::Height() - 70);
}

}

