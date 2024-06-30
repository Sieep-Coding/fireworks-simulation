#ifndef FIREWORK_H
#define FIREWORK_H

#define MAX_PARTICLES 500
#define MAX_FIREWORKS 10
#define FIREWORK_LIFESPAN 200

#include <raylib.h>

typedef struct
{
    Vector2 position;
    Vector2 speed;
    Color color;
    int lifespan;
    bool active;
} Particle;

typedef struct
{
    Vector2 position;
    Vector2 speed;
    Color color;
    int explodeTime;
    bool exploded;
    Particle particles[MAX_PARTICLES];
} Firework;

Firework fireworks[MAX_FIREWORKS];

#endif 