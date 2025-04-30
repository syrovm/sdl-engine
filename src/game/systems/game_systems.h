#ifndef GAME_SYSTEMS_H
#define GAME_SYSTEMS_H
#include "system.h"
#define GAME_SYSTEMS_LENGTH 3

typedef enum {
    GRAVITY = 1,
    MOVEMENT = 2,
    CONTROL = 4,
    COLLISION = 8
} SYSTEM;

System* getGameSystems();

#endif
