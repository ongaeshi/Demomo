#include "Setting.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Setting::Setting(const TOMLValue& aDesc)
: mDesc(aDesc)
{
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

