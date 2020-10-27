#include <iostream>
#include <string>
#include <thread>
#include "hooks.h"

int runMain()
{
    std::cout << "hello" << std::endl;
    if (!hooks::setup())
        std::cout << "hooking returned false" << std::endl;
    while (!GetAsyncKeyState(VK_F10))
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::cout << "done" << std::endl;
}

BOOL APIENTRY DllMain(HMODULE handle, DWORD reason, LPVOID reserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)runMain, handle, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

