#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Player
{
public:
    Player(const FilePath& aPath);
    void tryReload();
    void update();
};

}


