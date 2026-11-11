#pragma once

#include "raylib.h"

Rectangle rect_cut_top(Rectangle *rect, float a);
Rectangle rect_cut_bottom(Rectangle *rect, float a);
Rectangle rect_cut_left(Rectangle *rect, float a);
Rectangle rect_cut_right(Rectangle *rect, float a);
void rect_shrink(Rectangle *rect, float a);