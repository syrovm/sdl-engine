#include "controls.h"
#include "game_state.h"
#include "system.h"

void applyControls(GameState* state, Graphic* object) {
    if(object == NULL || (object->system & CONTROL) != CONTROL) {
        return;
    }

    static int jumpHeld = 0;

    if(state->keyboardState[SDL_SCANCODE_A]) {
        object->x_vel -= 0.5f;
    }
    if(state->keyboardState[SDL_SCANCODE_S]) {
        object->y_vel += 0.5f;
    }
    if(state->keyboardState[SDL_SCANCODE_D]) {
        object->x_vel += 0.5f;
    }

    if(state->keyboardState[SDL_SCANCODE_SPACE] && !jumpHeld) {
        object->y_vel = -5.0f;
        jumpHeld = 1;
    }
    else if(!state->keyboardState[SDL_SCANCODE_SPACE] && jumpHeld) { 
        jumpHeld = 0;
    }
}

System controlsSystem = {
    CONTROL,
    &applyControls
};