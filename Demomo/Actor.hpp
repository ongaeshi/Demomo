#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Actor
{
public:
    Actor(const Emoji& aEmoji);

    Texture& texture() { return mTexture; }

private:
    Texture mTexture;
};

}

