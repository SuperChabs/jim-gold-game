#include "raylib.h"
#include "player.h"
#include "gameobject.h"
#include <iostream>
#include <vector>
#include <memory>

Player::Player(float x, float y, float width, float height, Vector2 centre, const char *texturePath)
{
    pos = {x, y};
    size = {width, height};
    this->centre.x = centre.x;
    this->centre.y = centre.y;

    currentTexture = LoadTexture(texturePath);
    SetTextureFilter(currentTexture, TEXTURE_FILTER_POINT);
}

Player::~Player()
{
    if (currentTexture.id > 0)
    {
        UnloadTexture(currentTexture);
    }
}

void Player::Update(Vector2 centre, const std::vector<std::vector<std::shared_ptr<GameObject>>>& collisionObjectsMatrix)
{
    const float MOVE_SPEED = 4.0f;
    const float SIZE_CHANGE_SPEED = 2.0f;
    const float MIN_SIZE = 1.0f;
    const float MAX_SIZE = 95.0f;

    //Vector2 newCentre = centre;
    oldPos = pos;

    Vector2 newPos = pos;

    if (IsKeyDown(KEY_D)) newPos.x += MOVE_SPEED;
    if (IsKeyPressed(KEY_D)) this->SetTexture("assets/textures/jim_right.png");

    if (IsKeyDown(KEY_A)) newPos.x -= MOVE_SPEED;
    if (IsKeyPressed(KEY_A)) this->SetTexture("assets/textures/jim_left.png");

    if (IsKeyDown(KEY_W)) newPos.y -= MOVE_SPEED;
    if (IsKeyPressed(KEY_W)) this->SetTexture("assets/textures/jim_forward.png");

    if (IsKeyDown(KEY_S)) newPos.y += MOVE_SPEED;
    if (IsKeyPressed(KEY_S)) this->SetTexture("assets/textures/jim_t.png");

    bool sizeChanged = false;

    if (IsKeyDown(KEY_RIGHT)) {
        size.x += SIZE_CHANGE_SPEED;
        size.y += SIZE_CHANGE_SPEED;
        sizeChanged = true;
    }
    if (IsKeyDown(KEY_LEFT)) {
        size.x -= SIZE_CHANGE_SPEED;
        size.y -= SIZE_CHANGE_SPEED;
        sizeChanged = true;
    }

    if (size.x <= MIN_SIZE) {
        size.x = MIN_SIZE;
        size.y = MIN_SIZE;
        sizeChanged = true;
    }
    if (size.x >= MAX_SIZE) {
        size.x = MAX_SIZE;
        size.y = MAX_SIZE;
        sizeChanged = true;
    }

    pos = newPos;
    SetPosition(pos);

    //centre = newCentre;
    //this->SetPosition(centre.x, centre.y);

    if (sizeChanged) {
        this->SetSize(size.x, size.y);
    }

    Rectangle currentRect = GetHitbox();
    
    bool collision = false;
    for (auto& row : collisionObjectsMatrix) {
        for (auto& obj : row) {
            if (CheckCollisionRecs(currentRect, obj->GetHitbox())) {
                collision = true;
                break;
            }
        }
    }
    
    if (collision) {
        if (IsKeyDown(KEY_D)) {
            pos.x -= MOVE_SPEED;
        }
        if (IsKeyDown(KEY_A)) {
            pos.x += MOVE_SPEED;
        }
        if (IsKeyDown(KEY_W)) {
            pos.y += MOVE_SPEED;
        }
        if (IsKeyDown(KEY_S)) {
            pos.y -= MOVE_SPEED;
        }
        std::cout << "Collision!" << std::endl;
    }

}

void Player::Draw() const
{
    DrawTexturePro
        (
            currentTexture,
            {0, 0, (float)currentTexture.width, (float)currentTexture.height},
            {pos.x - size.x/2, pos.y - size.y/2, size.x, size.y},
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

Vector2 Player::GetPosition()
{
    return this->pos;
}

float Player::GetX() {return pos.x;}
float Player::GetY() {return pos.y;}

void Player::SetPosition(Vector2 newPos)
{
    pos.x = newPos.x;
    pos.y = newPos.y;
}

void Player::SetTexture(const char *newTexturePath)
{
    if (currentTexture.id > 0) {
        UnloadTexture(currentTexture);
    }
    currentTexture = LoadTexture(newTexturePath);
    SetTextureFilter(currentTexture, TEXTURE_FILTER_POINT);
}

void Player::SetSize(float w, float h)
{
    size.x = w;
    size.y = h;
}

Rectangle Player::GetHitbox() const
{
    return {
        pos.x - size.x / 2.0f /*+ centre.x*/,
        pos.y - size.y / 2.0f /*+ centre.y*/,
        size.x,
        size.y
    };
}