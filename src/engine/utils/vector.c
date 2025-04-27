#include "vector.h"

void addVector(Vector* dst, Vector src) {
    dst->x += src.x;
    dst->y += src.y;
}
