#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Script
{
public:
    Script(const FilePath& aPath);
    TOMLReader& reader() { return mReader; }

private:
    TOMLReader mReader;
};

}


