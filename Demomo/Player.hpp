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


private:
    Scene& scene() const { return script().scene(mSceneIndex); }

    void speech(const Text& aText);
    void reset();

    void setTextIndexToFirst();
    void setTextIndexToLast();

    std::unique_ptr<Script> mScript;
    int mSceneIndex;
    int mTextIndex;
    String mActorLeft;
    String mActorRight;
    bool mIsSpeech;
    int mIsWaitSpeechEnd;
};

}

