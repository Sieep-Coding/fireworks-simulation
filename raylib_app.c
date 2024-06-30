#include <math.h>
#include <stdlib.h>
#include "firework.h"

void initFirework(Firework *firework, int screenWidth, int screenHeight)
{
    firework->position = (Vector2){GetRandomValue(screenWidth / 4, 3 * screenWidth / 4), screenHeight};
    firework->speed = (Vector2){(float)GetRandomValue(-20, 20) / 10.0f, -(float)GetRandomValue(20, 50) / 10.0f};
    firework->color = (Color){GetRandomValue(50, 255), GetRandomValue(50, 255), GetRandomValue(50, 255), 255};
    firework->explodeTime = GetRandomValue(30, 60);
    firework->exploded = false;

    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        firework->particles[i].position = firework->position;
        firework->particles[i].speed = (Vector2){(float)GetRandomValue(-20, 20) / 10.0f, (float)GetRandomValue(-20, 20) / 10.0f};
        firework->particles[i].color = firework->color;
        firework->particles[i].lifespan = FIREWORK_LIFESPAN;
        firework->particles[i].active = false;
    }
}

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "Fireworks Simulation");
}