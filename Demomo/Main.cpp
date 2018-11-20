#include <Siv3D.hpp> // OpenSiv3D v0.3.0

void Main()
{
	const TOMLReader reader(U"../../test/script.toml");

	//Print << reader[U"Actor.ken.emoji"].getString();
	//Print << reader[U"Actor.sum.emoji"].getString();

	Window::Resize(854, 480);
	//Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
	//Graphics::SetBackground(Color(255, 255, 255));
	Graphics::SetBackground(Color(0, 0, 0));

	const Font font(60);
	const Font fontS(20);

	const Texture actorLeft(Emoji(reader[U"Actor.ken.emoji"].getString()), TextureDesc::Mipped);
	const Texture actorRight(Emoji(reader[U"Actor.sum.emoji"].getString()), TextureDesc::Mipped);

	int index = 0;

	Array<TOMLValue> texts;
	for (const auto& value : reader[U"text"].tableArrayView())
	{
		texts.push_back(value);
	}

	while (System::Update())
	{
		font(reader[U"Scene.title"].getString()).drawAt(
			Window::Width() / 2,
			(Window::Height() - 140) / 2,
			Palette::White
		);

		Rect rect(0, 326, Window::Width(), 140);

		if (rect.leftClicked()) {
			index++;
		}

		auto actorName = texts[index][U"actor"].getString();
		bool isLeft = reader[U"Actor." + actorName + U".pos"].getString() == U"left";

		if (isLeft) {
			Rect rect(160, 326, 564, 134);

			Shape2D::RectBalloon(rect, Vec2(110, Window::Height() - 90)).drawFrame(2, Palette::White);

			fontS(texts[index][U"text"].getString()).draw(rect.stretched(-6), Palette::White);

		}
		else {
			Rect rect(130, 326, 564, 134);

			Shape2D::RectBalloon(rect, Vec2(Window::Width() - 110, Window::Height() - 90)).drawFrame(2, Palette::White);

			fontS(texts[index][U"text"].getString()).draw(rect.stretched(-6), Palette::White);
		}

		auto s = 120;
		auto x1 = 0;
		auto x2 = 700 + 20;
		auto y = 480 - s - 10;
		actorLeft.resized(s).mirrored().drawAt(70, Window::Height() - 70);
		actorRight.resized(s).drawAt(Window::Width() - 70, Window::Height() - 70);
	}
}
