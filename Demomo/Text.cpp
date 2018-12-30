#include "Text.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Text::Text(const TOMLValue& aDesc)
: mActor(nullptr)
, mText(aDesc[U"text"].getString())
{
}

}

