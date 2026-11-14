# CHIP-8 devlog

## 2026-11-14: Setup and M0

**Done**
- Installed and checked the toolchain (g++, CMake, Ninja, gdb, Git).
- Created the repo, pushed to GitHub over SSH.
- Got CMake building and F5 debugging working in VS Code.
- M0: SDL window with the 64x32 display drawn at 10x scale.

**Problems and fixes**
- Link error `undefined reference to WinMain`. SDL renames `main` to
  `SDL_main`, and the `SDL2main` library supplies the real Windows entry
  point. Fix: link `SDL2::SDL2main` before `SDL2::SDL2`.
- `SDL_LoadBMP` failed with "Parameter 'src' is invalid". The file was
  not found because the program looks in the working directory, not next
  to the source file.

**Learned**
- The game loop shape: handle events, update, draw, present.
- Drawing belongs in the outer loop, not inside the event loop.

**Next**
- M1: load a ROM at 0x200, fetch two bytes, build the opcode.