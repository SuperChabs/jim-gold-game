#include "gameobject.h"
#include "raylib.h"

bool flagForButtonJ = false;

GameObject::GameObject(float x, float y, float texW, float texH, float hitW, float hitH, const char *texturePath)
{
    position = {x, y};
    textureSize = {texW, texH};
    hitboxSize = {hitW, hitH};
    hitboxOffset = {0, 0};

    tint = WHITE;
    isActive = true;
    sourceRect = {0, 0, 0, 0};

    texture = LoadTexture(texturePath);
    SetTextureFilter(texture, TEXTURE_FILTER_POINT);
}

GameObject::~GameObject()
{
    //if (texture.id != 0)  
        UnloadTexture(texture);

}

void GameObject::Update() 
{
    if (IsKeyPressed(KEY_J)) 
    {
        flagForButtonJ = !flagForButtonJ;
    }
}

void GameObject::Draw() 
{
    if (!isActive) return;

    if(texture.id != 0)
    {
        Rectangle source;
        if (sourceRect.width > 0 && sourceRect.height > 0)
            source = sourceRect;
        else
            source = {0, 0, (float)texture.width, (float)texture.height};
        Rectangle dest = {position.x, position.y, textureSize.x, textureSize.y};
        DrawTexturePro(texture, source, dest, {0, 0}, 0.0f, tint);
    } else {
        DrawRectangle(position.x, position.y, textureSize.x, textureSize.y, tint);
    }
    
    if (flagForButtonJ) 
    {
        Rectangle hitbox = GetHitbox();
        DrawRectangleLines(hitbox.x, hitbox.y, hitbox.width, hitbox.height, RED);
    }
}

bool GameObject::CheckCollision(Rectangle playerRect) 
{
    if (!isActive) return false;
    return CheckCollisionRecs(GetHitbox(), playerRect);
}

Rectangle GameObject::GetHitbox() 
{
    return {
        position.x + hitboxOffset.x - hitboxSize.x / 2.0f,
        position.y + hitboxOffset.y - hitboxSize.y / 2.0f,
        hitboxSize.x,
        hitboxSize.y
    };
}

Vector2 GameObject::GetPosition() 
{
    return position;
}

void GameObject::SetPosition(float x, float y) 
{
    position.x = x;
    position.y = y;
}

void GameObject::SetHitboxOffset(float offsetX, float offsetY)
{
    hitboxOffset = {offsetX, offsetY};
}

void GameObject::SetHitboxSize(float width, float height)
{
    hitboxSize = {width, height};
}

void GameObject::SetActive(bool active) 
{
    isActive = active;
}

void GameObject::SetSourceRect(float x, float y, float w, float h) 
{
    sourceRect = {x, y, w, h};
}

bool GameObject::IsActive() 
{
    return isActive;
}