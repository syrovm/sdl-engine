#include "system.h"
#include "gravity.h"
#include "game_state.h"

void applyGravity(GameState* state, Graphic* object) {
    if(object == NULL 
        || (object->system & GRAVITY) != GRAVITY) {
        return;
    }

    object->y_vel += 0.1;
}

System gravitySystem = {
    GRAVITY,
    &applyGravity
};