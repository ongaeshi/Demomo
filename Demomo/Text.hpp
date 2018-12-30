#pragma once

#include <Siv3D.hpp>

namespace demomo {
    class Actor;
}

namespace demomo {
    class Script;
}

namespace demomo {

//-----------------------------------------------------------------------------
class Text
{
public:
    Text(const Script& aScript, const TOMLValue& aDesc);

    const Actor& actor() const { return mActor; }
    String text() const { return mText; }

private:
    const Actor& mActor;
    String mText;
};

}

