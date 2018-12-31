#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Setting
{
public:
    Setting(const TOMLValue& aDesc);

    bool textToSpeech() const { return mDesc[U"textToSpeech"].get<bool>(); }
    bool autoPlay() const { return mDesc[U"autoPlay"].get<bool>(); }
    double speechSpeed() const;

private:
    bool hasMember(const String& aName) const { return mDesc.hasMember(aName); }

    const TOMLValue mDesc;
};

}


