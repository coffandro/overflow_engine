#pragma once

#include "../node/node.hpp"
#include "../ui/button.hpp"

class MainMenu : public Node
{
protected:
    Button *playButton;

public:
    MainMenu(Rectangle dimensions);
    ~MainMenu();

    void Update() override;
    void Draw() override;

    // Logic
    void QuitGame();
};