#include "lay.hpp"

#include <math.h>

Rectangle rect_cut_top(Rectangle *rect, float a)
{
    Rectangle result = {
        .x = rect->x,
        .y = rect->y,
        .width = rect->width,
        .height = a};
    rect->y += a;
    rect->height = fmax(rect->height - a, 0);
    return result;
}

Rectangle rect_cut_bottom(Rectangle *rect, float a)
{
    Rectangle result = {.x = rect->x + rect->width - a,
                        .y = rect->y,
                        .width = a,
                        .height = rect->height};
    rect->width = fmax(rect->width - a, 0);
    return result;
}

Rectangle rect_cut_left(Rectangle *rect, float a)
{
    Rectangle result = {
        .x = rect->x,
        .y = rect->y,
        .width = a,
        .height = rect->height};
    rect->x += a;
    rect->width = fmax(rect->width - a, 0);
    return result;
}

Rectangle rect_cut_right(Rectangle *rect, float a)
{
    Rectangle result = {
        .x = rect->x,
        .y = rect->y + rect->height - a,
        .width = rect->width,
        .height = a};
    rect->height = fmax(rect->height - a, 0);
    return result;
}

void rect_shrink(Rectangle *rect, float a)
{
    rect->x += a;
    rect->y += a;
    rect->width -= a * 2;
    rect->height -= a * 2;
}