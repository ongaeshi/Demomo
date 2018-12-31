#include "Setting.hpp"

namespace demomo {
//-----------------------------------------------------------------------------
Setting::Setting(const TOMLValue& aDesc)
: mDesc(aDesc)
{
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

