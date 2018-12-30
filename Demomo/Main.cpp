#include <Siv3D.hpp>
#include "Player.hpp"

void Main()
{
    demomo::Player player(U"../../test/script.toml");

	while (System::Update())
	{
        player.tryReload();
        player.update();
	}
}
