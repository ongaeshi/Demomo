#include "Script.hpp"

namespace demomo {

//-----------------------------------------------------------------------------
Script::Script(const FilePath& aPath)
: mReader(aPath)
, mFont(60)
, mFontS(20)
{
}

}
