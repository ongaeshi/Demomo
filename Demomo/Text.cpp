#include "Text.hpp"

#include "Script.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Text::Text(const Script& aScript, const TOMLValue& aDesc)
: mActor(aScript.actor(aDesc[U"actor"].getString()))
, mText(aDesc[U"text"].getString())
{
}

}
