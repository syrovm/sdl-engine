#ifndef SYSTEM_H
#define SYSTEM_H
#include "game_state.h"

typedef enum {
    GRAVITY = 1,
    MOVEMENT = 2,
    CONTROL = 4,
    COLLISION = 8
} SYSTEM;

typedef struct System {
    SYSTEM system;
    void (*applySystem)(GameState*, Graphic*);
} System;

#endif