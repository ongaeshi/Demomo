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

    bool hasTitle() const { return hasMember(U"title"); }
    String title() const { return mDesc[U"title"].getString(); }

    bool hasTexture() const { return hasMember(U"image"); }
    const Texture& texture() const { return mTexture; }

    bool hasInitLeft() const { return hasMember(U"initLeft"); }
    String initLeft() const { return mDesc[U"initLeft"].getString(); }

    bool hasInitRight() const { return hasMember(U"initRight"); }
    String initRight() const { return mDesc[U"initRight"].getString(); }

    const Array<Text>& texts() const { return mTexts; }

private:
    bool hasMember(const String& aName) const { return mDesc.hasMember(aName); }

    const TOMLValue mDesc;
    Texture mTexture;
    Array<Text> mTexts;
};

}

