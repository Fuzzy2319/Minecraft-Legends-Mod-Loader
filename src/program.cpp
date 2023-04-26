#include "program.hpp"

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD ul_reason_for_call,
    LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        MessageBox(NULL, current_path().wstring().c_str(), TEXT("Test"), MB_OK);
    }

    return TRUE;
}
