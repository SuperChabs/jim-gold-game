#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include "raylib.h"
#include <string>

class Entity {
protected:
    Vector2 position;
    Vector2 velocity;
    float rotation;
    bool active;
    std::string name;

public:
    // Конструктори
    Entity();
    Entity(Vector2 pos, const std::string& entityName = "Entity");
    virtual ~Entity() = default;

    // Віртуальні методи для перевизначення
    virtual void Update(float deltaTime);
    virtual void Draw();
    virtual void OnCollision(Entity* other);

    // Getters
    Vector2 GetPosition() const { return position; }
    Vector2 GetVelocity() const { return velocity; }
    float GetRotation() const { return rotation; }
    bool IsActive() const { return active; }
    const std::string& GetName() const { return name; }

    // Setters
    void SetPosition(Vector2 pos) { position = pos; }
    void SetVelocity(Vector2 vel) { velocity = vel; }
    void SetRotation(float rot) { rotation = rot; }
    void SetActive(bool isActive) { active = isActive; }
    void SetName(const std::string& entityName) { name = entityName; }

    // Допоміжні методи
    void Move(Vector2 direction);
    float DistanceTo(const Entity& other) const;
    virtual Rectangle GetBounds() const;
};

#endif // ENTITY_H
