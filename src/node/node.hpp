#pragma once

#include <vector>
#include "raylib.h"

class Node
{
protected:
    std::vector<Node *> children;
    RenderTexture2D renderTexture;
    Rectangle dimensions;

public:
    Node(Rectangle dimensions);
    ~Node();

    Node *GetChild(int index);
    int GetChildIndex(int index);
    void AddChild(Node *node);
    void RemoveChild(Node *node);
    void RemoveChild(int index);
    void ClearChildren();

    virtual void Update();
    virtual void Draw();
    virtual void Render();
};