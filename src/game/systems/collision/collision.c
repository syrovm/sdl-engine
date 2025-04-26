#include "collision.h"
#include "system.h"
#include "game_state.h"

void applyCollision(GameState* state, Graphic* object) {
    if(!object || (object->system & COLLISION) != COLLISION) {
        return;
    }

    Graphic** objectsChecked = calloc(1, sizeof(Graphic*));
    int objectsCheckedLength = 0;

    for(int i = 0; i < state->object_length; i++) {
        int skip = 0;
        //don't check collision of current object with itself
        if(state->objects[i] == object)
            skip = 1;
        //don't recheck collisions
        for(int j = 0; j < objectsCheckedLength; j++) {
            if(object == objectsChecked[j]) {
                skip = 1;
                break;
            }
        }

        if(skip)
            continue;

        Graphic* obj1 = state->objects[i];
        Graphic* obj2 = object;

        if(obj1->positionRect.x < obj2->positionRect.x + obj2->positionRect.w &&
            obj1->positionRect.x + obj1->positionRect.w > obj2->positionRect.x &&
            obj1->positionRect.y < obj2->positionRect.y + obj2->positionRect.h &&
            obj1->positionRect.y + obj1->positionRect.h > obj2->positionRect.y) {
            
        }
    }

    free(objectsChecked);
}

System collisionSystem = {
    COLLISION,
    &applyCollision
};