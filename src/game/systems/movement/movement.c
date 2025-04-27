#include "system.h"
#include "movement.h"
#include "game_state.h"
#include "vector.h"

void applyMovement(GameState* state, Graphic* object) {
    if(object == NULL || (object->system & MOVEMENT) != MOVEMENT) {
        return;
    }
    
    //TODO: do this using vectors 
    object->positionRect.x += object->velocity.x;
    object->positionRect.y += object->velocity.y;
}

System movementSystem = {
    MOVEMENT,
    &applyMovement
};
