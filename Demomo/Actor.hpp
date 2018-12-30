#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Actor
{
public:
    Actor(const TOMLValue& aDesc);

    const Texture& texture() const { return mTexture; }
    bool isLeft() const { return mIsLeft; }

private:
    Texture mTexture;
    bool mIsLeft;
};

}

