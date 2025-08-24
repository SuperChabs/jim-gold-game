#pragma once
#include "raylib.h"

class GameObject 
{
public:
    GameObject(float x, float y, float texW, float texH, float hitW, float hitH, const char *texturePath);
    ~GameObject();

    void Update();
    void Draw();

    bool CheckCollision(Rectangle playerRect);

    Rectangle GetHitbox();
    Vector2 GetPosition();

    void SetPosition(float x, float y);
    void SetHitboxOffset(float offsetX, float offsetY);
    void SetHitboxSize(float width, float height);
    void SetActive(bool active);
    void SetSourceRect(float x, float y, float w, float h);

    bool IsActive();

private:
    Vector2 position;
    Vector2 textureSize;
    Vector2 hitboxSize;
    Vector2 hitboxOffset;
    Texture2D texture = {};
    bool isActive;
    Color tint;
    Rectangle sourceRect;
};