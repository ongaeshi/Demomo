#pragma once

#include <Siv3D.hpp>

namespace demomo {

//-----------------------------------------------------------------------------
class Scene
{
public:
    Scene(const TOMLValue& aDesc);

    String title() const { return mDesc[U"title"].getString(); }

    String initLeft() const { return mDesc[U"initLeft"].getString(); }
    String initRight() const { return mDesc[U"initRight"].getString(); }

    ColorF backgroundColor() const;

private:
    bool hasMember(const String& aStr) const { return mDesc.hasMember(aStr); }

    const TOMLValue& mDesc;

};

}

