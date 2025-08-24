#ifndef UI_H
#define UI_H

#include "raylib.h"
#include <string>

enum class UIType {
    TEXT,
    DIALOGUE_BOX
};

class UI {
public:
    // Конструктор для простого тексту
    UI(const std::string& text, float x, float y, int fontSize, Color color, bool isScreenSpace = true);
    
    // Конструктор для діалогового вікна
    UI(const std::string& text, float x, float y, float width, float height, Color backgroundColor, Color textColor);
    
    void Draw(const Camera2D& camera);
    void SetText(const std::string& text);
    void SetPosition(float x, float y);
    void SetColor(Color color);
    
    ~UI() = default;

private:
    Vector2 position;
    Vector2 size;
    int fontSize;
    Color textColor;
    Color backgroundColor;
    std::string text;
    UIType type;
    bool isScreenSpace; // true = прив'язка до екрану, false = прив'язка до світу
};

#endif // UI_H
