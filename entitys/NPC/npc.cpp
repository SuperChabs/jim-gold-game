#include "npc.h"
#include "ui.h"

NPC::NPC(float x, float y, float width, float height, float hitboxWidht, float hitboxHeight, const char *texturePath) 
{
    position = {x, y};
    size = {width, height};
    hitbox = {hitboxWidht, hitboxHeight};

    currentTexture = LoadTexture(texturePath);
    SetTextureFilter(currentTexture, TEXTURE_FILTER_POINT);
}

NPC::~NPC() 
{
    if (currentTexture.id > 0)
    {
        UnloadTexture(currentTexture);
    }
}

void NPC::Draw()
{
    DrawTexturePro
        (
            currentTexture,
            {0, 0, (float)currentTexture.width, (float)currentTexture.height},
            {position.x - size.x/2, position.y - size.y/2, size.x, size.y},
            {0, 0},
            0.0f,
            WHITE
            );
    
    if (IsKeyDown(KEY_J))
    {        
        Rectangle hitbox = GetHitbox();
        DrawRectangleLines(hitbox.x, hitbox.y, hitbox.width, hitbox.height, RED);
    }
}

void NPC::Update()
{

}

void NPC::Move()
{

}

void NPC::DrawDialogueBox()
{

}
///                 Private Class Methods                  ///

///                         Geters                         ///

Rectangle NPC::GetHitbox()
{
    return Rectangle{
        position.x - hitbox.x / 2.0f,
        position.y - hitbox.y / 2.0f,
        hitbox.x,
        hitbox.y
    };
}

Vector2 NPC::GetSize()
{
    return this->size;
}

Vector2 NPC::GetPosition()
{
    return this->position;
}

///                         Seters                         ///

void NPC::SetHitbox(float widht, float height)
{
    hitbox.x = widht;
    hitbox.y = height;
}

void NPC::SetSize(float widht, float height)
{
    size.x = widht;
    size.y = height;
}

void NPC::SetPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void NPC::SetTexture(const char* texturePath)
{
    currentTexture = LoadTexture(texturePath);
    SetTextureFilter(currentTexture, TEXTURE_FILTER_POINT);
}



