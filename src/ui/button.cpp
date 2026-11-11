#include "button.hpp"
#include "../util/util.hpp"

void Button::SetOnClick(std::function<void()> funcptr)
{
    onClickCallback = funcptr;
}

void Button::SetOnPress(std::function<void()> funcptr)
{
    onPressCallback = funcptr;
}

void Button::SetOnHover(std::function<void()> funcptr)
{
    onHoverCallback = funcptr;
}

void Button::SetOnUnHover(std::function<void()> funcptr)
{
    onUnHoverCallback = funcptr;
}

Button::Button(const char *text, Rectangle dimensions) : Node(dimensions)
{
    label = text;
}

Button::~Button()
{
}

void Button::Update()
{
    Node::Update();
    bool currentlyHovered = IsPosInRect(GetMousePosition(), dimensions);

    if (currentlyHovered)
    {
        if (!wasHovered)
        {
            if (onHoverCallback != nullptr)
            {
                onHoverCallback();
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            wasPressed = true; // press started on this button
            if (onPressCallback != nullptr)
            {
                onPressCallback();
            }
        }
        else if (wasPressed && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            if (onClickCallback != nullptr)
            {
                onClickCallback();
            }
        }
    }
    else
    {
        if (wasHovered)
        {
            // If we leave the button we stop pressing
            wasPressed = false;

            if (onUnHoverCallback != nullptr)
            {
                onUnHoverCallback();
            }
        }
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        wasPressed = false;
    }

    wasHovered = currentlyHovered;
}

void Button::Draw()
{
    BeginTextureMode(renderTexture);

    Color drawCol;
    if (wasPressed)
    {
        drawCol = RED;
    }
    else
    {
        drawCol = BLUE;
    }
    DrawRectangle(dimensions.x, dimensions.y, dimensions.width, dimensions.height, drawCol);
    DrawText(label, 10, 5, 32, BLACK);

    Node::Draw();
    EndTextureMode();
}