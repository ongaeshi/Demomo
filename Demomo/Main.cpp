#include <Siv3D.hpp>
#include "Player.hpp"

void Main()
{
    demomo::Player player(U"../../test/script.toml");

    const TOMLReader& reader = player.script().reader();
    const Font& font = player.script().font();
    const Font& fontS = player.script().fontS();

    Window::Resize(854, 480);
	Graphics::SetBackground(ColorF(0, 0, 0));

	int index = -1;

	Array<TOMLValue> texts;
	TOMLValue scene = reader[U"Scene"].tableArrayView()[0];

	if (scene.hasMember(U"backgroundColor")) {
		Graphics::SetBackground(scene[U"backgroundColor"].get<ColorF>());
	}

	auto& actorLeft = player.script().actor(scene[U"init_left"].getString());
	auto& actorRight = player.script().actor(scene[U"init_right"].getString());

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

		if (index >= 0) {
            auto& actor = player.script().actor(texts[index][U"actor"].getString());

			if (actor.isLeft()) {
				Rect rect(160, 326, 564, 134);
				Shape2D::RectBalloon(rect, Vec2(110, Window::Height() - 90)).drawFrame(2, Palette::White);
				fontS(texts[index][U"text"].getString()).draw(rect.stretched(-6), Palette::White);

				actorLeft = actor;

			} else {
				Rect rect(130, 326, 564, 134);
				Shape2D::RectBalloon(rect, Vec2(Window::Width() - 110, Window::Height() - 90)).drawFrame(2, Palette::White);
				fontS(texts[index][U"text"].getString()).draw(rect.stretched(-6), Palette::White);

				actorRight = actor;
			}
		}

        actorLeft.texture().resized(120).drawAt(70, Window::Height() - 70);
        actorRight.texture().resized(120).drawAt(Window::Width() - 70, Window::Height() - 70);
	}
}
