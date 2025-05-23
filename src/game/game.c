#include <SDL.h>
#include "game_state.h"
#include "game_actor.h"
#include "system.h"
#include "game_systems.h"
#include "vector.h"

void initGame(GameState* state) {
    GameActor* smile = createGameActor(state, "assets/smile.jpg", (Vector){ .x = 250, .y = 0 }, 50, 50 );
    applySystem(smile, MOVEMENT|CONTROL|GRAVITY);
    addObject(state, smile);
}

void loop(GameState* state) {
    System* systems = getGameSystems();
    for(int i = 0; i < state->object_length; i++) {
        for(int j = 0; j < GAME_SYSTEMS_LENGTH; j++) {
            System system = systems[j];
            system.applySystem(state, state->objects[i]);
        }
    }
    renderFrame(state);
    free(systems);

    //TODO framerate
    SDL_Delay(10);
}
