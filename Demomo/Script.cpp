#include "Script.hpp"

namespace demomo {

//-----------------------------------------------------------------------------
Script::Script(const FilePath& aPath)
: mReader(aPath)
, mFont(60)
, mFontS(20)
{
    for (const auto& actor : mReader[U"Actor"].tableArrayView()) {
        mActors << Actor(Emoji(actor[U"emoji"].getString()));
        //actors.emplace(actor[U"name"].getString(), i);
        //i++;
    }
}

}
