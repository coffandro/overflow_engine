#include "raylib.h"
#include "node/node.hpp"
#include "scenes/main_menu.hpp"
#include "config.hpp"

int screen_width = 800;
int screen_height = 800;
int ui_scale = 2.0f;

extern "C"
{
	void set_dimensions(int w, int h)
	{
		screen_width = w;
		screen_height = h;

		if (IsWindowReady())
		{
			SetWindowSize(screen_width, screen_height);
		}
	}
}

int main(void)
{
	InitWindow(screen_width, screen_height, "");
	SetTargetFPS(60);

	Node *sceneRoot = new MainMenu((Rectangle){0, 0, (float)screen_width, (float)screen_height});

	// Main game loop
	while (!WindowShouldClose())
	{
		// Update
		sceneRoot->Update();

		sceneRoot->Draw();

		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);
		sceneRoot->Render();

		EndDrawing();
	}

	delete sceneRoot;
	CloseWindow();

	return 0;
}