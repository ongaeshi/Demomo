#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Script
{
public:
    Script(const FilePath& aPath);

    TOMLReader& reader() { return mReader; }
    const Font& font() const { return mFont; }
    const Font& fontS() const { return mFontS; }

private:
    TOMLReader mReader;
    const Font mFont;
    const Font mFontS;
};

}


