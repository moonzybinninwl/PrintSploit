#include <Windows.h>

extern "C" __declspec(dllexport) LRESULT CALLBACK ntqueryinformationthread(int code, WPARAM wParam, LPARAM lParam) { return CallNextHookEx(NULL, code, wParam, lParam); }
uintptr_t Handle = (uintptr_t)GetModuleHandleA(0);

using print = DWORD64(__cdecl*)(unsigned int type, const char* message, ...);
print Print = reinterpret_cast<print>(Handle + 0x1A06390); // This requires the print offset.

/*
You can find the print offset by loading the dumped Roblox executable into IDA 9.0 Pro.
Once analysed (it should say the inital analysis is complete), Go to Edit -> Segments -> Rebase Program -> change the value to 0x0
Once rebased, press F12 + Shift to generate strings. Then, in the strings window, press Ctrl + F and search 'Current Identity is %d'.
Double click the result, hit Ctrl + X on your keyboard and press 'OK'. Now, press F5 on you keyboard to decompile.
In the decompiled view, there'll be the line with the string or your cursor should be on that line with the searched string.
The start of the line should have something like, 'sub_1A06390'. Copy that, put it into notepad, relace 'sub_' with '0x' so it looks like '0x1A06390'.
And then you're done! You have the print offset and you can now update this.
*/

void start() {
    MessageBoxA(0, "Printsploit Injected", "Printsploit", MB_TOPMOST);
    Print(0LL, "Working!");
    Print(1LL, "Working!");
    Print(2LL, "Working!");
    Print(3LL, "Working!");
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        start();

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
