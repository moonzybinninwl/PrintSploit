![C++](https://img.shields.io/badge/language-C++-00599C?logo=c%2B%2B&logoColor=white)

# Printsploit

A small DLL that calls Roblox's 'print' function using a manually updated address.

## Usage
Inject the DLL into Roblox.
On injection it will show a MessageBox and print four test messages to the Roblox output.

## Finding the Print Offset
1. Dump `RobloxPlayerBeta.exe`. You can find how to dump Roblox at https://github.com/moonzybinninwl/Vulkan-Dumper
2. Open it in **IDA 9.0 Pro**.
3. Rebase the program to `0x0` (`Edit → Segments → Rebase Program`).
4. Press **Shift + F12**, search: `Current Identity is %d`.
5. Open the result, press **Ctrl + X**, confirm.
6. Press **F5** to view the decompiled function.
7. Copy the function name (e.g. `sub_1A06390`).
8. Replace `sub_` with `0x` → `0x1A06390`.
9. Use this as your print offset.

## Note
- Offset must be updated after every Roblox update.

Enjoy!
