#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Actor
{
public:
    Actor(const TOMLValue& aDesc);

    Texture& texture() { return mTexture; }
    bool isLeft() const { return mIsLeft; }

private:
    Texture mTexture;
    bool mIsLeft;
};

}

