#pragma once

#include <Siv3D.hpp>
#include "Actor.hpp"
#include "Scene.hpp"

namespace demomo {

//-----------------------------------------------------------------------------
class Script
{
public:
    Script(const FilePath& aPath);

    TOMLReader& reader() { return mReader; }

    const Font& font() const { return mFont; }
    const Font& fontS() const { return mFontS; }

    Actor& actor(int aIndex) { return mActors[aIndex]; }
    Actor& actor(const String& aName) { return mActors[actorIndex(aName)]; }
    int actorIndex(const String& aName) { return mActorHash[aName]; }
    
    Scene& scene(int aIndex) { return mScenes[aIndex]; }

private:
    TOMLReader mReader;
    const Font mFont;
    const Font mFontS;
    Array<Actor> mActors;
    HashTable<String, int> mActorHash;
    Array<Scene> mScenes;
};

}


