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

	Array<Texture> actorArray;
	actorArray << Texture(Emoji(reader[U"Actor.ken.emoji"].getString()), TextureDesc::Mipped);
	actorArray << Texture(Emoji(reader[U"Actor.ken_o.emoji"].getString()), TextureDesc::Mipped);
	actorArray << Texture(Emoji(reader[U"Actor.sum.emoji"].getString()), TextureDesc::Mipped);

	HashTable<String, int> actors;
	actors.emplace(U"ken", 0);
	actors.emplace(U"ken_o", 1);
	actors.emplace(U"sum", 2);

	int actorLeft = actors[U"ken"];
	int actorRight = actors[U"sum"];

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
		} else if (clickedRect.rightClicked()) {
			index--;
		}

		auto actorName = texts[index][U"actor"].getString();
		bool isLeft = reader[U"Actor." + actorName + U".pos"].getString() == U"left";

		if (isLeft) {
			Rect rect(160, 326, 564, 134);
			Shape2D::RectBalloon(rect, Vec2(110, Window::Height() - 90)).drawFrame(2, Palette::White);
			fontS(texts[index][U"text"].getString()).draw(rect.stretched(-6), Palette::White);

			actorLeft = actors[actorName];

		} else {
			Rect rect(130, 326, 564, 134);
			Shape2D::RectBalloon(rect, Vec2(Window::Width() - 110, Window::Height() - 90)).drawFrame(2, Palette::White);
			fontS(texts[index][U"text"].getString()).draw(rect.stretched(-6), Palette::White);

			actorRight = actors[actorName];
		}

		actorArray[actorLeft].resized(120).drawAt(70, Window::Height() - 70);
		actorArray[actorRight].resized(120).drawAt(Window::Width() - 70, Window::Height() - 70);
	}
}
