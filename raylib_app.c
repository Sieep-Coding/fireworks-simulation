#include <raylib.h>
#include <math.h>
#include <stdlib.h>

#define MAX_PARTICLES 500
#define MAX_FIREWORKS 10
#define FIREWORK_LIFESPAN 200

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

void initFirwork(Firework *firework, int screen)


int main(void) {
    const int screenWidth = 900;
    const int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "Fireworks Simulation");
}