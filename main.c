#include <SDL.h>
#include "sdl_utils.h"
#include "game.h"
#include "game_state.h"

int main() {
    // init
    int initCode = init();
    if(initCode != 0) {
        printf("Error occurred during init. Exiting.\n");
        return initCode;
    }

    // allocate window stuff
    SDL_Window* window = createWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        printf("Window failed to allocate. Exiting.\n");
        return 1;
    }
    SDL_Renderer* renderer = createRenderer(window);
    if(renderer == NULL) {
        printf("Renderer failed to allocate. Exiting.\n");
        return 2;
    }

    //init game state
    GameState state = initState(renderer);
    initGame(&state);

    //game loop
    int quit = 0;
    SDL_Event e;
    while(!quit) {
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                quit = 1;
            }
        }
        loop(&state);
    }

    //cleanup
    deallocState(&state);
    cleanup(window, renderer);

    return 0;
}
