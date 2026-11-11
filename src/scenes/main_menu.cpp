#include "main_menu.hpp"
#include "../config.hpp"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

void MainMenu::QuitGame()
{
#ifdef __EMSCRIPTEN__
    EM_ASM(
        location.reload());
#else
    CloseWindow();
#endif
}

MainMenu::MainMenu(Rectangle dimensions) : Node(dimensions)
{
    playButton = new Button("Play!", (Rectangle){0, 0, 100, 50});
    playButton->SetOnClick([this]()
                           { QuitGame(); });
    AddChild(playButton);
}

MainMenu::~MainMenu()
{
    RemoveChild(playButton);
    delete playButton;
}

void MainMenu::Update()
{
    Node::Update();
    dimensions.width = GetScreenWidth() / ui_scale;
}

void MainMenu::Draw()
{
    BeginTextureMode(renderTexture);

    Node::Draw();
    EndTextureMode();
}