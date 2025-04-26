#ifndef EVENT_NODE_H
#define EVENT_NODE_H

typedef struct EventNode {
    SDL_Event event;
    struct EventNode* next;
} EventNode;

#endif