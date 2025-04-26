#include "game_systems.h"
#include "gravity.h"
#include "movement.h"
#include "controls.h"

System* getGameSystems() {
    System* systems = malloc(sizeof(System)*GAME_SYSTEMS_LENGTH);
    systems[0] = gravitySystem;
    systems[1] = controlsSystem;
    systems[2] = movementSystem;
    return systems;
};