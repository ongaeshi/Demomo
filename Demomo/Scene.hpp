#pragma once

#include <Siv3D.hpp>
#include "Text.hpp"

namespace demomo {
    class Script;
}

namespace demomo {

//-----------------------------------------------------------------------------
class Scene
{
public:
    Scene(const Script& aScript, const TOMLValue& aDesc);

    String title() const { return mDesc[U"title"].getString(); }

    bool hasInitLeft() const { return hasMember(U"initLeft"); }
    String initLeft() const { return mDesc[U"initLeft"].getString(); }

    bool hasInitRight() const { return hasMember(U"initRight"); }
    String initRight() const { return mDesc[U"initRight"].getString(); }

    ColorF backgroundColor() const;

    const Texture& texture() const { return mTexture; }

    const Array<Text>& texts() const { return mTexts; }

private:
    bool hasMember(const String& aStr) const { return mDesc.hasMember(aStr); }

    const TOMLValue mDesc;
    Texture mTexture;
    Array<Text> mTexts;
};

}

