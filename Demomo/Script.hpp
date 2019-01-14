#pragma once

#include <Siv3D.hpp>
#include "Actor.hpp"
#include "Scene.hpp"
#include "Setting.hpp"

namespace demomo {

//-----------------------------------------------------------------------------
class Script
{
public:
    Script(const FilePath& aPath);

    const FilePath& path() const { return mPath; }
    bool isOpened() const { return mReader.isOpened(); }
    bool hasChanged() const;

    const Setting& setting() const { return mSetting; }

    const Font& font() const { return mFont; }
    const Font& fontS() const { return mFontS; }

    const Actor& actor(int aIndex) const { return mActors[aIndex]; }
    const Actor& actor(const String& aName) const { return mActors[actorIndex(aName)]; }
    int actorIndex(const String& aName) const { return const_cast<HashTable<String, int>&>(mActorHash)[aName]; }
    
    const Array<Scene>& scenes() const { return mScenes; }
    Scene& scene(int aIndex) { return mScenes[aIndex]; }

private:
    FilePath mPath;
    DirectoryWatcher mDirectoryWatcher;
    TOMLReader mReader;
    Setting mSetting;
    const Font mFont;
    const Font mFontS;
    Array<Actor> mActors;
    HashTable<String, int> mActorHash;
    Array<Scene> mScenes;
};

}


