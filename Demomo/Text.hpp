#pragma once

#include <Siv3D.hpp>

namespace demomo {
    class Actor;
}

namespace demomo {

//-----------------------------------------------------------------------------
class Text
{
public:
    Text(const TOMLValue& aDesc);

    const Actor& actor() const { return *mActor; }
    String text() const { return mText; }

private:
    Actor* mActor;
    String mText;
};

}

