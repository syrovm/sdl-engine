#ifndef SYSTEM_H
#define SYSTEM_H
#include "game_state.h"

typedef struct System {
    int systemId;
    void (*applySystem)(GameState*, GameActor*);
} System;

void applySystem(GameActor*, int);

#endif
