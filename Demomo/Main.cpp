#include <Siv3D.hpp> // OpenSiv3D v0.3.0

void Main()
{
	const TOMLReader reader(U"../../test/test.toml");

	Print << reader[U"Window.fullscreen"].get<bool>();
	Print << reader[U"Window.backgroundColor"].get<ColorF>();
	Print << reader[U"GUI.Config.Button.label"].getString();

	Window::Resize(854, 480);
	//Graphics::SetBackground(ColorF(0.8, 0.9, 1.0));
	//Graphics::SetBackground(Color(255, 255, 255));
	Graphics::SetBackground(Color(0, 0, 0));

	const Font font(60);
	const Font fontS(20);

	const Texture actorLeft(Emoji(U"🐈"), TextureDesc::Mipped);
	const Texture actorRight(Emoji(U"🐒"), TextureDesc::Mipped);

	bool isLeft = true;
	int index = 0;

	Array<String> texts;
	texts.push_back(U"えたいの知れない不吉な塊が\n私の心を始終圧おさえつけていた。");
	texts.push_back(U"焦躁しょうそうと言おうか、嫌悪と言おうか――酒を飲んだあとに宿酔ふつかよいがあるように、酒を毎日飲んでいると宿酔に相当した時期がやって来る。それが来たのだ。");
	texts.push_back(U"これはちょっといけなかった。");
	texts.push_back(U"結果した肺尖はいせんカタルや神経衰弱がいけないのではない。また背を焼くような借金などがいけないのではない。いけないのはその不吉な塊だ。");
	texts.push_back(U"以前私を喜ばせたどんな美しい音楽も、どんな美しい詩の一節も辛抱がならなくなった。蓄音器を聴かせてもらいにわざわざ出かけて行っても、最初の二三小節で不意に立ち上がってしまいたくなる。");
	texts.push_back(U"何かが私を居堪いたたまらずさせるのだ。それで始終私は街から街を浮浪し続けていた。");
	texts.push_back(U"何故なぜだかその頃私は見すぼらしくて美しいものに強くひきつけられたのを覚えている。風景にしても壊れかかった街だとか、その街にしてもよそよそしい表通りよりもどこか親しみのある、");
	texts.push_back(U"汚い洗濯物が干してあったりがらくたが転がしてあったりむさくるしい部屋が覗のぞいていたりする裏通りが好きであった。");
	texts.push_back(U"雨や風が蝕むしばんでやがて土に帰ってしまう、と言ったような趣きのある街で、土塀どべいが崩れていたり家並が傾きかかっていたり――");
	texts.push_back(U"勢いのいいのは植物だけで、時とするとびっくりさせるような向日葵ひまわりがあったりカンナが咲いていたりする。");
	texts.push_back(U"続きは\n\nhttps://www.aozora.gr.jp/cards/000074/files/424_19826.html");
	texts.push_back(U"OpenSiv3Dを使って\n会話デモを簡単に作れるツールを\n開発しています");

	while (System::Update())
	{
		font(U"檸檬\n梶井基次郎").drawAt(
			Window::Width() / 2,
			(Window::Height() - 140) / 2,
			Palette::White
		);

		Rect rect(0, 326, Window::Width(), 140);

		if (rect.leftClicked()) {
			isLeft = !isLeft;
			index++;
		}

		if (isLeft) {
			Rect rect(160, 326, 564, 134);

			Shape2D::RectBalloon(rect, Vec2(110, Window::Height() - 90)).drawFrame(2, Palette::White);

			fontS(texts[index]).draw(rect.stretched(-6), Palette::White);

		}
		else {
			Rect rect(130, 326, 564, 134);

			Shape2D::RectBalloon(rect, Vec2(Window::Width() - 110, Window::Height() - 90)).drawFrame(2, Palette::White);

			fontS(texts[index]).draw(rect.stretched(-6), Palette::White);
		}

		auto s = 120;
		auto x1 = 0;
		auto x2 = 700 + 20;
		auto y = 480 - s - 10;
		actorLeft.resized(s).mirrored().drawAt(70, Window::Height() - 70);
		actorRight.resized(s).drawAt(Window::Width() - 70, Window::Height() - 70);
	}
}
