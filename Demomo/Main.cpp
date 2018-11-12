
# include <Siv3D.hpp> // OpenSiv3D v0.3.0

void Main()
{
    Window::Resize(1280, 720);
	Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));

    const Font font(60);
    const Font fontS(20);

	const Texture actorLeft(Emoji(U"🐈"), TextureDesc::Mipped);
    const Texture actorRight(Emoji(U"🐣"), TextureDesc::Mipped);

	while (System::Update())
	{
		font(U"Hello, Siv3D!🐣").drawAt(Window::Center(), Palette::Black);

        Rect rect(200, 500, 500, 80);

        fontS(U"Hello, Siv3D!🐣\nこんにちは、私がSiv3Dだよ！").draw(rect, Palette::Black);
        rect.draw(ColorF(0.5, 0.2));
        rect.drawFrame(0, 2, Palette::Gray);
        

		//font(Cursor::Pos()).draw(20, 500, ColorF(0.6));

        actorLeft.resized(80).mirrored().draw(20, 500);
        actorRight.resized(80).draw(700, 500);

		//Circle(Cursor::Pos(), 60).draw(ColorF(1, 0, 0, 0.5));
	}
}
