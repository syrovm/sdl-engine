#include "collision.h"
#include "system.h"
#include "game_state.h"
#include "game_actor.h"
#include "game_systems.h"

void applyCollision(GameState* state, GameActor* object) {
    if(!object || (object->system & COLLISION) != COLLISION) {
        return;
    }

    GameActor** objectsChecked = calloc(1, sizeof(GameActor*));
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

        GameActor* obj1 = state->objects[i];
        GameActor* obj2 = object;

        if(obj1->position.x < obj2->position.x + obj2->width &&
            obj1->position.x + obj1->width > obj2->position.x &&
            obj1->position.y < obj2->position.y + obj2->height &&
            obj1->position.y + obj1->height > obj2->position.y) {
            
        }
    }

    free(objectsChecked);
}

System collisionSystem = {
    COLLISION,
    &applyCollision
};
