#include <iostream>
#include <string>
#include <thread>
#include "hooks.h"

int main()
{
    std::cout << "hello" << std::endl;
    std::cout << FindWindow("Chrome_WidgetWin_1", NULL) << std::endl;
    if (!hooks::setup())
        std::cout << "hooking returned false" << std::endl;
    while (!GetAsyncKeyState(VK_F10))
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::cout << "done" << std::endl;
}