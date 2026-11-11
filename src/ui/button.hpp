#pragma once

#include "../node/node.hpp"
#include <functional>

class Button : public Node
{
protected:
    const char *label;
    bool wasHovered = false;
    bool wasPressed = false;

    // Callback pointers
    std::function<void()> onClickCallback;
    std::function<void()> onPressCallback;
    std::function<void()> onHoverCallback;
    std::function<void()> onUnHoverCallback;

public:
    Button(const char *text, Rectangle dimensions);
    ~Button();

    void Update() override;
    void Draw() override;

    // logic
    void SetOnClick(std::function<void()> funcptr);
    void SetOnPress(std::function<void()> funcptr);
    void SetOnHover(std::function<void()> funcptr);
    void SetOnUnHover(std::function<void()> funcptr);
};