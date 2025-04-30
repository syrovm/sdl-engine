#include "system.h"
#include "gravity.h"
#include "game_state.h"
#include "game_actor.h"
#include "game_systems.h"

void applyGravity(GameState* state, GameActor* object) {
    if(object == NULL 
        || (object->system & GRAVITY) != GRAVITY) {
        return;
    }

    addVector(&object->velocity, (Vector){ .x = 0, .y = 0.1 });
}

System gravitySystem = {
    GRAVITY,
    &applyGravity
};
