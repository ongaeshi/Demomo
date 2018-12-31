#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Setting
{
public:
    Setting(const TOMLValue& aDesc);

    bool textToSpeech() const { return mDesc[U"textToSpeech"].get<bool>(); }

private:
    const TOMLValue mDesc;
};

}


