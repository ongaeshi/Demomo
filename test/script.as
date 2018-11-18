void Main()
{
    Window::Resize(854, 480);
    Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));

    const Font font(60);
    const Font fontS(20);

	const Texture actorLeft(Emoji("🐈"), TextureDesc::Mipped);
    const Texture actorRight(Emoji("🐣"), TextureDesc::Mipped);

    while (System::Update())
    {
		font("Hello, Siv3D!🐣").drawAt(427, 200, Palette::Black);

        Rect rect(120, 340, 654, 130);

        fontS("Hello, Siv3D!🐣\nこんにちは、私がSiv3Dだよ！").draw(rect, Palette::Black);
        
        rect.draw(ColorF(0.5, 0.2));
        rect.drawFrame(0, 2, Palette::Gray);
		//font(Cursor::Pos()).draw(20, 500, ColorF(0.6));

        auto s = 120;
        auto x1 = 0;
        auto x2 = 700 + 20;
        auto y = 480 - s - 10;
        actorLeft.resized(s).mirrored().draw(x1, y);
        actorRight.resized(s).draw(x2, y);

		//Circle(Cursor::Pos(), 60).draw(ColorF(1, 0, 0, 0.5));
    }
}
