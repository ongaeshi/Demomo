#include "Actor.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Actor::Actor(const TOMLValue& aDesc)
: mTexture(Emoji(aDesc[U"emoji"].getString()), TextureDesc::Mipped)
, mIsLeft(aDesc[U"pos"].getString() == U"left")
{
}

}

