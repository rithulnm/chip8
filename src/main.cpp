#include <iostream>
#include <cstdint>
#include <SDL.h>

bool init(SDL_Window*& window,SDL_Renderer*& renderer);

int main(int argc, char* argv[]){
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    if (!init(window, renderer)) return 1;

    std::uint8_t disp[32][64] {0};

    //testing hahaha
    //for (int i=32; i<44; i++){
    disp[1][1] = 1;
    

    bool isRunning = true;
    SDL_Event ev;

    while(isRunning){
        while(SDL_PollEvent(&ev) != 0){
            switch (ev.type){
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        for (int y=0; y<32; y++){
            for(int x=0; x<64; x++){
                if (disp[y][x] == 1){
                    SDL_Rect pixel = {
                        x*10,
                        y*10,
                        10,
                        10,
                    };
                    SDL_RenderFillRect(renderer, &pixel);
                }
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);

        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

bool init(SDL_Window*& window,SDL_Renderer*& renderer){
    if (SDL_Init(SDL_INIT_VIDEO)<0){
        std::cout << "Video Init Error\n" << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    window = SDL_CreateWindow("CHIP8",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,320,SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::cout << "Window Creation Error\n" << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr){
        std::cout << "Renderer Creation Error\n" << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    return true;
}