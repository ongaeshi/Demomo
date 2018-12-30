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

    const Font& font() const { return mFont; }
    const Font& fontS() const { return mFontS; }

    const Actor& actor(int aIndex) const { return mActors[aIndex]; }
    const Actor& actor(const String& aName) const { return mActors[actorIndex(aName)]; }
    int actorIndex(const String& aName) const { return const_cast<HashTable<String, int>&>(mActorHash)[aName]; }
    
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


