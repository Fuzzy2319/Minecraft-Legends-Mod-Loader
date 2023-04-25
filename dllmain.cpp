// dllmain.cpp : Définit le point d'entrée de l'application DLL.
#include <windows.h>
#include <stdlib.h>

BOOL APIENTRY DllMain( 
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            system("calc");
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

