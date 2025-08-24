#ifndef NPC_H
#define NPC_H

#include "raylib.h"
#include "ui.h"

class NPC
{
private:
    Texture currentTexture;
    Vector2 size;
    Vector2 hitbox;
    Vector2 position;
    Vector2 centre;
    UI* dialogueBox = nullptr;

public:
    NPC(float x, float y, float width, float height, float hitboxWidht, float hitboxHeight, const char *texturePath);
    ~NPC();
  
    void Draw();
    void Update();
    void Move();
    void DrawDialogueBox();

    Rectangle GetHitbox();
    Vector2 GetSize();
    Vector2 GetPosition();

    void SetHitbox(float widht, float height);
    void SetSize(float widht, float height);
    void SetPosition(float x, float y);
    void SetTexture(const char* texturePath);
};

#endif