#include "program.hpp"
using namespace mlml;
using namespace std;
using namespace filesystem;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        Logger::log(LogLevel::Debug, current_path().wstring());
    }

    return TRUE;
}
