# Notes

## The machine
- Screen: 64x32 monochrome. I store it as `disp[y][x]` (row first).
- Memory: 4096 bytes. Programs load at 0x200.
- Timers tick at 60 Hz.

## SDL functions
- `SDL_CreateWindow`: makes the window, returns null on failure.
- `SDL_CreateRenderer`: draws into a window. Check the vsync flag.
- `SDL_PollEvent`: call in a loop each frame, returns 0 when no
  events are left. Very very imp. 
- `SDL_RenderFillRect`: filled rectangle, takes an `SDL_Rect`.
- `SDL_RenderPresent`: shows what was drawn. Once per frame, last.

## Rules I learned
- `main` must be `int main(int argc, char* argv[])` with SDL on Windows.

## Links
- SDL2 wiki: https://wiki.libsdl.org/SDL2/FrontPage
- SDL2 full guide: https://thenumb.at/cpp-course/sdl2/04/04.html