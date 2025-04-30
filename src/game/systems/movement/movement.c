#include "system.h"
#include "game_systems.h"
#include "movement.h"
#include "game_state.h"
#include "game_actor.h"
#include "vector.h"

void applyMovement(GameState* state, GameActor* object) {
    if(object == NULL || (object->system & MOVEMENT) != MOVEMENT) {
        return;
    }
    
    //TODO: do this using vectors 
    object->position.x += object->velocity.x;
    object->position.y += object->velocity.y;
}

System movementSystem = {
    MOVEMENT,
    &applyMovement
};
