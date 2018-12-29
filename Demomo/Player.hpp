#pragma once

#include <Siv3D.hpp>
#include "Script.hpp"

namespace demomo {

//-----------------------------------------------------------------------------
class Player
{
public:
    Player(const FilePath& aPath);
    TOMLReader& reader() { return mScript.reader(); }
    void tryReload();
    void update();

private:
    Script mScript;
};

}

