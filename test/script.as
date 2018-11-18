void Main()
{
    Window::Resize(854, 480);
    //Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
    //Graphics::SetBackground(Color(255, 255, 255));
    Graphics::SetBackground(Color(0, 0, 0));

    const Font font(60);
    const Font fontS(20);

	const Texture actorLeft(Emoji("🐈"), TextureDesc::Mipped);
    const Texture actorRight(Emoji("🐒"), TextureDesc::Mipped);

    while (System::Update())
    {
		font("Hello, Siv3D!🐣").drawAt(
            Window::Width() / 2,
            (Window::Height() - 140) / 2,
            Palette::White
            );

        Rect rect(140, 326, 574, 134);

        auto s = 120;
        auto x1 = 0;
        auto x2 = 700 + 20;
        auto y = 480 - s - 10;
        actorLeft.resized(s).mirrored().drawAt(70, Window::Height() - 70);
        actorRight.resized(s).drawAt(Window::Width() - 70, Window::Height() - 70);

        rect.draw(ColorF(0));
        rect.drawFrame(0, 4, Palette::White);

        fontS("Hello, Siv3D!🐣\nこんにちは、私がSiv3Dだよ！\nあああああああああああああああああしあしああしあああああああああああああああいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい").draw(rect, Palette::White);
        
		//font(Cursor::Pos()).draw(20, 500, ColorF(0.6));

		//Circle(Cursor::Pos(), 60).draw(ColorF(1, 0, 0, 0.5));
    }
}
