#include "program.hpp"
using namespace mlml;
using namespace std;
using namespace filesystem;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        Logger::log(LogLevel::Debug, current_path().wstring());
        Logger::log(LogLevel::Info, TEXT("Initializing..."));
        if (!exists("./mods/"))
        {
            Logger::log(LogLevel::Info, TEXT("Creating mods directory"));
            create_directory("./mods/");
        }
        for (const directory_entry &entry : directory_iterator("./mods/"))
        {
            if (entry.path().extension() == ".dll")
            {
                Logger::log(LogLevel::Info, TEXT("Loading mod : ") + entry.path().wstring());
                LoadModule((LPCSTR)entry.path().c_str(), NULL);
            }
        }
    }

    return TRUE;
}
