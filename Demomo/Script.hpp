#pragma once

#include <Siv3D.hpp>
#include "Actor.hpp"

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
    Actor& actor(const String& aStr) { return mActors[actorIndex(aStr)]; }
    int actorIndex(const String& aStr) { return mActorHash[aStr]; }

private:
    TOMLReader mReader;
    const Font mFont;
    const Font mFontS;
    Array<Actor> mActors;
    HashTable<String, int> mActorHash;
};

}


