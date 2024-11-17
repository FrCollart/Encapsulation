#include "RaylibTests.h"
#include "raylib.h"

int RaylibTests::TestRaylib()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    InitWindow(WIDTH, HEIGHT, "raylib Test Window");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("raylib is working! Close the window to exit.", 190, 280, 20, LIGHTGRAY);

        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
