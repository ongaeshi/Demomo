#include "Setting.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Setting::Setting(const TOMLValue& aDesc)
: mDesc(aDesc)
{
}

//-----------------------------------------------------------------------------
Color Setting::fontColor() const
{
    if (hasMember(U"fontColor")) {
        return mDesc[U"fontColor"].get<Color>();
    } else {
        return Palette::White;
    }
}

//-----------------------------------------------------------------------------
Color Setting::backgroundColor() const
{
    if (hasMember(U"backgroundColor")) {
        return mDesc[U"backgroundColor"].get<Color>();
    } else {
        return Color();
    }
}

//-----------------------------------------------------------------------------
double Setting::speechSpeed() const
{
    if (hasMember(U"speechSpeed")) {
        return mDesc[U"speechSpeed"].get<double>();
    } else {
        return 1.0;
    }
}

}

