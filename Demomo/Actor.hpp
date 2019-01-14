#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Actor
{
public:
    Actor(const TOMLValue& aDesc);

    String name() const { return mName;  }
    const Texture& texture() const { return mTexture; }
    bool isLeft() const { return mIsLeft; }

private:
    String mName;
    Texture mTexture;
    bool mIsLeft;
};

}

