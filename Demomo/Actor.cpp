#include "Actor.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Actor::Actor(const Emoji& aEmoji)
: mTexture(aEmoji, TextureDesc::Mipped)
{
}

}

