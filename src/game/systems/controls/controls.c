#include "controls.h"
#include "game_state.h"
#include "system.h"
#include "vector.h"

void applyControls(GameState* state, Graphic* object) {
    if(object == NULL || (object->system & CONTROL) != CONTROL) {
        return;
    }

    static int jumpHeld = 0;

    Vector left =  (Vector){ .x = -0.5 };
    Vector right = (Vector){ .x =  0.5 };

    if(state->keyboardState[SDL_SCANCODE_A]) {
        addVector(&object->velocity, left);
    }
    if(state->keyboardState[SDL_SCANCODE_D]) {
        addVector(&object->velocity, right);
    }

    if(state->keyboardState[SDL_SCANCODE_SPACE] && !jumpHeld) {
        object->velocity.y = -5.0;
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
