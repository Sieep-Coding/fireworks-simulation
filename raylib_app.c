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

void UpdateFirework(Firework *firework, int screenWidth, int screenHeight) {
    if (!firework->exploded) {
        firework->position.x += firework->speed.x;
        firework->position.y += firework->speed.y;
        firework->speed.y += 0.1f;  // Gravity

        firework->explodeTime--;
        if (firework->explodeTime <= 0 || firework->position.y <= screenHeight / 4) {
            firework->exploded = true;
            for (int i = 0; i < MAX_PARTICLES; i++) {
                firework->particles[i].active = true;
            }
        }
    } else {
        for (int i = 0; i < MAX_PARTICLES; i++) {
            if (firework->particles[i].active) {
                firework->particles[i].position.x += firework->particles[i].speed.x;
                firework->particles[i].position.y += firework->particles[i].speed.y;
                firework->particles[i].lifespan--;
                if (firework->particles[i].lifespan <= 0) {
                    firework->particles[i].active = false;
                }
            }
        }
    }
}

void DrawFirework(Firework *firework) {
    if (!firework->exploded) {
        DrawCircleV(firework->position, 5, firework->color);
    } else {
        for (int i = 0; i < MAX_PARTICLES; i++) {
            if (firework->particles[i].active) {
                DrawCircleV(firework->particles[i].position, 3, firework->particles[i].color);
            }
        }
    }
}

int main(void) {
    const int screenWidth = 900;
    const int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "Fireworks Simulation");

    for (int i = 0; i < MAX_FIREWORKS; i++) {
        InitFirework(&fireworks[i], screenWidth, screenHeight);
    }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        for (int i = 0; i < MAX_FIREWORKS; i++) {
            if (fireworks[i].exploded && fireworks[i].particles[0].lifespan <= 0) {
                InitFirework(&fireworks[i], screenWidth, screenHeight);
            } else {
                UpdateFirework(&fireworks[i], screenWidth, screenHeight);
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < MAX_FIREWORKS; i++) {
            DrawFirework(&fireworks[i]);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}