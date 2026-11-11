#include "util.hpp"

bool IsPosInRect(Vector2 pos, Rectangle rect)
{
    if (
        pos.x > rect.x && pos.x < (rect.x + rect.width) &&
        pos.y > rect.y && pos.y < (rect.y + rect.height))
    {
        return true;
    }

    return false;
}