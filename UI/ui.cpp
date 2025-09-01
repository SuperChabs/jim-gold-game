#include "ui.h"
#include <iostream>

UI::UI(const std::string& text, float x, float y, int fontSize, Color color, bool isScreenSpace)
    : position{x, y}
    , fontSize(fontSize)
    , textColor(color)
    , text(text)
    , type(UIType::TEXT)
    , isScreenSpace(isScreenSpace)
{
}

UI::UI(const std::string& text, float x, float y, float width, float height, Color backgroundColor, Color textColor)
    : position{x, y}
    , size{width, height}
    , fontSize(20)
    , textColor(textColor)
    , backgroundColor(backgroundColor)
    , text(text)
    , type(UIType::DIALOGUE_BOX)
    , isScreenSpace(true)
{
}

void UI::Draw(const Camera2D& camera) {
    Vector2 drawPos = position;
    
    // Якщо UI прив'язаний до екрану, коригуємо позицію відносно камери
    if (isScreenSpace) {
        drawPos.x += camera.offset.x;
        drawPos.y += camera.offset.y;
    } else {
        // Конвертуємо світові координати в екранні
        drawPos = GetWorldToScreen2D(position, camera);
    }

    if (type == UIType::TEXT) {
        DrawText(text.c_str(), drawPos.x, drawPos.y, fontSize, textColor);
    } else if (type == UIType::DIALOGUE_BOX) {
        DrawRectangle(drawPos.x, drawPos.y, size.x, size.y, backgroundColor);
        DrawText(text.c_str(), drawPos.x + 10, drawPos.y + 10, fontSize, textColor);
        std::cout << "This UI shit was been drawen\n";
    }
}

void UI::SetText(const std::string& newText) {
    text = newText;
}

void UI::SetPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void UI::SetColor(Color color) {
    textColor = color;
}

