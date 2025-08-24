#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>
#include "gameobject.h"
#include "raylib.h"

class Player
{
public:
    Player(float x, float y, float width, float height, Vector2 centre,const char *texturePath);
    ~Player();

    void Update(Vector2 centre, const std::vector<std::vector<std::shared_ptr<GameObject>>>& collisionObjectsMatrix);
    void Draw() const;

    void SetPosition(Vector2 newPos);
    void SetTexture(const char *newTexturePath);
    void SetSize(float w, float h);

    Vector2 GetPosition() const;
    Vector2 GetPosition();
    Rectangle GetHitbox() const;
    float GetX();
    float GetY();

private:
    Vector2 pos;
    Vector2 velocity;
    Vector2 size;
    Vector2 centre;
    Vector2 oldPos;
    float speed;
    Texture2D currentTexture;
};

#endif // PLAYER_H
