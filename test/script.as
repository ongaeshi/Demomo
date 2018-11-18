void Main()
{
    Window::Resize(854, 480);
    //Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
    //Graphics::SetBackground(Color(255, 255, 255));
    Graphics::SetBackground(Color(0, 0, 0));

    const Font font(60);
    const Font fontS(20);

	const Texture actorLeft(Emoji("🐈"), TextureDesc::Mipped);
    const Texture actorRight(Emoji("🐈"), TextureDesc::Mipped);

    bool isLeft = true;

    while (System::Update())
    {
		font("Hello, Siv3D!🐣").drawAt(
            Window::Width() / 2,
            (Window::Height() - 140) / 2,
            Palette::White
            );

        Rect rect(0, 326, Window::Width(), 140);

        if (rect.leftClicked()) {
            isLeft = !isLeft;
        }

        if (isLeft) {
            Rect rect(160, 326, 564, 134);

            Shape2D::RectBalloon(rect, Vec2(110, Window::Height() - 90)).drawFrame(2, Palette::White);

            fontS("Hello, Siv3D!🐣\nこんにちは、私がSiv3Dだよ！\nあああああああああああああああああしあしああしあああああああああああああああいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい").draw(rect, Palette::White);

        } else {
            Rect rect(130, 326, 564, 134);

            Shape2D::RectBalloon(rect, Vec2(Window::Width() - 110,  Window::Height() - 90)).drawFrame(2, Palette::White);

            fontS("こんにちは！こんにちは！").draw(rect, Palette::White);
        }

        auto s = 120;
        auto x1 = 0;
        auto x2 = 700 + 20;
        auto y = 480 - s - 10;
        actorLeft.resized(s).mirrored().drawAt(70, Window::Height() - 70);
        actorRight.resized(s).drawAt(Window::Width() - 70, Window::Height() - 70);
    }
}
