#include "Scene.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Scene::Scene(const TOMLValue& aDesc)
: mDesc(aDesc)
{
    for (const auto& text : aDesc[U"Text"].tableArrayView()) {
        mTexts << Text(text);
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

