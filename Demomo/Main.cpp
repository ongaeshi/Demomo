#include <Siv3D.hpp>
#include <filesystem>
#include "Player.hpp"

namespace {
    // Windows.hを読み込む前に呼ばないとSetCurrentDirectoryが
    // マクロで上書きされてしまいうまく動かない。
    void SetDir(const FilePath& path)
    {
        ::s3d::Windows::FileSystem::SetCurrentDirectory(path);
    }
}

#include <Windows.h>

namespace {
    Array<String> getArgs()
    {
        auto argv = Array<String>();
    
        int nArgs = 0;
        LPWSTR* szArglist = ::CommandLineToArgvW(::GetCommandLineW(), &nArgs);
    
        for (int i = 1; i < nArgs; i++) {
            argv << Unicode::FromWString(szArglist[i]);
        }
        ::LocalFree(szArglist);
    
        return argv;
    }
}

void Main()
{
    SetDir(::s3d::Windows::FileSystem::WorkingDirectory());

    auto args = getArgs();

    auto path = std::filesystem::path(args[0].toUTF32());
    SetDir(path.parent_path().u32string());

    demomo::Player player(path.filename().u32string());

	while (System::Update())
	{
        player.tryReload();
        player.update();
	}
}
