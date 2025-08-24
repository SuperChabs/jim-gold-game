#include "entity.h"
#include <cmath>

Entity::Entity()
    : position{0, 0}, velocity{0, 0}, rotation(0), active(true), name("Entity") {
}

Entity::Entity(Vector2 pos, const std::string& entityName)
    : position(pos), velocity{0, 0}, rotation(0), active(true), name(entityName) {
}

void Entity::Update(float deltaTime) {
    if (!active) return;

    // Оновлення позиції на основі швидкості
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

void Entity::Draw() {
    if (!active) return;

    // Базовий рендеринг - простий червоний квадрат
    DrawRectangle(position.x - 10, position.y - 10, 20, 20, RED);
}

void Entity::OnCollision(Entity* other) {
    // Базова реакція на колізію - може бути перевизначена
}

void Entity::Move(Vector2 direction) {
    velocity = direction;
}

float Entity::DistanceTo(const Entity& other) const {
    float dx = position.x - other.position.x;
    float dy = position.y - other.position.y;
    return std::sqrt(dx * dx + dy * dy);
}

Rectangle Entity::GetBounds() const {
    return {position.x - 10, position.y - 10, 20, 20};
}
