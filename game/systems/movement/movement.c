#include "system.h"
#include "movement.h"
#include "game_state.h"

void applyMovement(GameState* state, Graphic* object) {
    if(object == NULL || (object->system & MOVEMENT) != MOVEMENT) {
        return;
    }
    
    //TODO: vectors
    object->positionRect.x += object->x_vel;
    object->positionRect.y += object->y_vel;
}

System movementSystem = {
    MOVEMENT,
    &applyMovement
};