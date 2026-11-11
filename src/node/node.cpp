#include "node.hpp"

Node::Node(Rectangle dimensions)
{
    this->dimensions = dimensions;
    children = std::vector<Node *>();
    renderTexture = LoadRenderTexture(dimensions.width, dimensions.height);
}

Node::~Node()
{
    UnloadRenderTexture(renderTexture);
    for (Node *node : children)
    {
        delete node;
    }
    ClearChildren();
}

Node *Node::GetChild(int index)
{
    return children[index];
}

void Node::AddChild(Node *node)
{
    children.push_back(node);
}

void Node::RemoveChild(Node *node)
{
    for (int i = 0; i < children.size(); i++)
    {
        if (GetChild(i) == node)
        {
            RemoveChild(i);
        }
    }
}

void Node::RemoveChild(int index)
{
    children.erase(children.begin() + index);
}

void Node::ClearChildren()
{
    children.clear();
}

void Node::Update()
{
    for (Node *node : children)
    {
        node->Update();
    }
}

void Node::Draw()
{
    for (Node *node : children)
    {
        node->Draw();
    }
}

void Node::Render()
{
    DrawTextureRec(
        renderTexture.texture,
        (Rectangle){0, 0, dimensions.width, -dimensions.height},
        (Vector2){dimensions.x, dimensions.y},
        WHITE);
    for (Node *node : children)
    {
        node->Render();
    }
}