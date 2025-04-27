#include "game_state.h"
#include "sdl_utils.h"
#include <SDL.h>

GameState initState(SDL_Renderer* renderer) {
    Graphic** initList = malloc(sizeof(Graphic*));
    initList[0] = NULL;
    GameState g = (GameState){
        initList,
        SDL_GetKeyboardState(NULL),
        1,
        renderer
    };

    return g;
}

void renderFrame(GameState* state) {
    SDL_RenderClear(state->renderer);
    for(int i = 0; i < state->object_length; i++) {
        Graphic* object = state->objects[i];
        if(object != NULL) {
            SDL_RenderCopy(state->renderer, object->texture, NULL, &object->positionRect);
        }
    }
    SDL_RenderPresent(state->renderer);
}

void addObject(GameState* state, Graphic* object) {
    state->objects = realloc(state->objects, sizeof(Graphic*) * (state->object_length + 1));
    state->objects[state->object_length] = object;
    state->object_length++;
}

void removeObject(GameState* state, Graphic* object) {
    int indexToRemove = -1;
    for(int i = 0; i < state->object_length; i++) {
        if(state->objects[i] == object) {
            indexToRemove = i;
            break;
        }
    }

    SDL_DestroyTexture(state->objects[indexToRemove]->texture);

    if(indexToRemove != -1) {
        for(int i = indexToRemove; i < state->object_length - 1; i++) {
            state->objects[i] = state->objects[i + 1];
        }

        state->objects = realloc(state->objects, sizeof(Graphic*) * (state->object_length - 1));
        state->object_length -= 1;
    }
}

Graphic* createGraphic(GameState* state, const char* texturePath, SDL_Rect initialDstRect) {
    SDL_Texture* texture = createTexture(state->renderer, texturePath);
    Graphic* result = malloc(sizeof(Graphic));
    *result = (Graphic){
        .texture = texture,
        .positionRect = initialDstRect,
        .x_vel = 0.0,
        .y_vel = 0.0
    };

    return result;
}

void deallocGObject(Graphic* object) {
    if(object != NULL) {
        SDL_DestroyTexture(object->texture);
    }
    free(object);
}

void deallocState(GameState* state) {
    for(int i = 0; i < state->object_length; i++) {
        deallocGObject(state->objects[i]);
    }
    free(state->objects);
    SDL_DestroyRenderer(state->renderer);
}

