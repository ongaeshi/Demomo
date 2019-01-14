#include "Script.hpp"

namespace demomo {

//-----------------------------------------------------------------------------
Script::Script(const FilePath& aPath)
: mPath(aPath)
, mDirectoryWatcher(FileSystem::ParentPath(mPath))
, mReader(mPath)
, mSetting(mReader[U"Setting"])
, mFont(60)
, mFontS(20)
{
    // Illegal TOML?
    if (!isOpened()) {
        return;
    }

    for (const auto& actor : mReader[U"Actor"].tableArrayView()) {
        mActors << Actor(actor);
        mActorHash.emplace(actor[U"name"].getString(), mActors.count() - 1);
    }

    for (const auto& scene : mReader[U"Scene"].tableArrayView()) {
        mScenes << Scene(*this, scene);
    }
}

//-----------------------------------------------------------------------------
bool Script::hasChanged() const
{
    auto changes = mDirectoryWatcher.retrieveChanges();

    // TODO: Check relative files only.
    return changes.count() > 0;
}

}
