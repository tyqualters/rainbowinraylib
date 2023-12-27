#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raymath.h>
#include "raygui.h"
#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Taste the rainbow with raylib");

    SetTargetFPS(30);

    const Vector2 SCREEN_CENTER = (Vector2) {
        WINDOW_WIDTH / 2,
        WINDOW_HEIGHT / 2
    };

    float factor = 1.0f;
    float rotation = 0.0f;
    Vector2 offset = {0.0f, 0.0f};

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawCircleSector(Vector2Add(SCREEN_CENTER, offset), 105.f * factor, -180.f + rotation, 0.f + rotation, 30, VIOLET);
        DrawCircleSector(Vector2Add(SCREEN_CENTER, offset), 90.f * factor, -180.f + rotation, 0.f + rotation, 30, PURPLE);
        DrawCircleSector(Vector2Add(SCREEN_CENTER, offset), 75.f * factor, -180.f + rotation, 0.f + rotation, 30, BLUE);
        DrawCircleSector(Vector2Add(SCREEN_CENTER, offset), 60.f * factor, -180.f + rotation, 0.f + rotation, 30, GREEN);
        DrawCircleSector(Vector2Add(SCREEN_CENTER, offset), 45.f * factor, -180.f + rotation, 0.f + rotation, 30, YELLOW);
        DrawCircleSector(Vector2Add(SCREEN_CENTER, offset), 30.f * factor, -180.f + rotation, 0.f + rotation, 30, ORANGE);
        DrawCircleSector(Vector2Add(SCREEN_CENTER, offset), 15.f * factor, -180.f + rotation, 0.f + rotation, 30, RED);

        GuiLabel((Rectangle){96, 36, 216, 16}, "Scale Rainbow");
        GuiSlider((Rectangle){ 96, 48, 216, 16 }, TextFormat("%0.1f", factor), NULL, &factor, 0.0f, 2.5f);

        GuiLabel((Rectangle){96, 64, 216, 16}, "Rotation");
        GuiSlider((Rectangle){ 96, 80, 216, 16 }, TextFormat("%0.1f", rotation), NULL, &rotation, 0.0f, 360.0f);

        GuiLabel((Rectangle){96, 96, 216, 16}, "Rainbow X:");
        GuiSlider((Rectangle){ 96, 112, 216, 16 }, TextFormat("%0.1f", offset.x), NULL, &offset.x, -100.0f, 100.0f);

        GuiLabel((Rectangle){96, 128, 216, 16}, "Rainbow Y:");
        GuiSlider((Rectangle){ 96, 144, 216, 16 }, TextFormat("%0.1f", offset.y), NULL, &offset.y, -100.0f, 350.0f);

        if(GuiButton((Rectangle){96, 176, 216, 16}, "Reset")) {
            factor = 1.0f;
            rotation = 0.0f;
            offset = (Vector2){0.0f, 0.0f};
        }

        EndDrawing();
    }

    CloseWindow();
}