#include "Scene.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Scene::Scene(const TOMLValue& aDesc)
: mDesc(aDesc)
{
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

