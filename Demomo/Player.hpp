#pragma once

#include <Siv3D.hpp>
#include "Actor.hpp"
#include "Script.hpp"

namespace demomo {

//-----------------------------------------------------------------------------
class Player
{
public:
    Player(const FilePath& aPath);

    Script& script() { return mScript; }

    void tryReload();
    void update();

private:
    Scene& scene() { return mScript.scene(mSceneIndex); }

    Script mScript;
    int mSceneIndex;
    int mTextIndex;
    const Actor* mActorLeft;
    const Actor* mActorRight;
    bool mIsSpeech;
    int mIsWaitSpeechEnd;
};

}

