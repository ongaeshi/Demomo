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

    Script& script() const { return *mScript; }

    void tryReload();
    void update();

    void speech(const Text& aText);

private:
    Scene& scene() const { return script().scene(mSceneIndex); }

    Script* mScript;
    int mSceneIndex;
    int mTextIndex;
    const Actor* mActorLeft;
    const Actor* mActorRight;
    bool mIsSpeech;
    int mIsWaitSpeechEnd;
};

}

