#include "Scene.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Scene::Scene(const Script& aScript, const TOMLValue& aDesc)
: mDesc(aDesc)
{
    for (const auto& text : aDesc[U"Text"].tableArrayView()) {
        mTexts << Text(aScript, text);
    }

    if (hasTexture()) {
        mTexture = Texture(aDesc[U"image"].getString());
    }
}

//-----------------------------------------------------------------------------
ColorF Scene::backgroundColor() const
{
    if (hasMember(U"backgroundColor")) {
        return mDesc[U"backgroundColor"].get<ColorF>();
    } else {
        return ColorF();
    }
}

}

