#include <Siv3D.hpp> // OpenSiv3D v0.3.0

void Main()
{
	const TOMLReader reader(U"../../test/script.toml");

	Window::Resize(854, 480);
	//Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
	//Graphics::SetBackground(Color(255, 255, 255));
	Graphics::SetBackground(Color(0, 0, 0));

	const Font font(60);
	const Font fontS(20);

	HashTable<String, Texture> actors;
	actors.emplace(U"ken", Texture(Emoji(reader[U"Actor.ken.emoji"].getString()), TextureDesc::Mipped));
	actors.emplace(U"ken_o", Texture(Emoji(reader[U"Actor.ken_o.emoji"].getString()), TextureDesc::Mipped));
	actors.emplace(U"sum", Texture(Emoji(reader[U"Actor.sum.emoji"].getString()), TextureDesc::Mipped));

	int index = 0;

	Array<TOMLValue> texts;
	TOMLValue scene = reader[U"Scene"].tableArrayView()[0];
	for (const auto& value : scene[U"Text"].tableArrayView())
	{
		texts.push_back(value);
	}

	while (System::Update())
	{
		font(scene[U"title"].getString()).drawAt(
			Window::Width() / 2,
			(Window::Height() - 140) / 2,
			Palette::White
		);

		Rect clickedRect(0, 326, Window::Width(), 140);

		if (clickedRect.leftClicked()) {
			index++;
		}
		else if (clickedRect.rightClicked()) {
			index--;
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
		actors[U"ken"].resized(s).mirrored().drawAt(70, Window::Height() - 70);
		actors[U"sum"].resized(s).drawAt(Window::Width() - 70, Window::Height() - 70);
	}
}
