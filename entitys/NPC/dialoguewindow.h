#ifndef DIALOGUEWINDOW_H
#define DIALOGUEWINDOW_H

#pragma once
#include <string>
#include <vector>
#include <memory>

#include "raylib.h"
#include "ui.h"

#define WINDOW_WIDHT 1080
#define WINDOW_HEIGHT 720

class DialogueWindow {
public:
    DialogueWindow(std::vector<std::string>& replics);

    void Update();
    void Draw(Camera2D& camera);

    void SetReplic(std::string newReplic);

private:
    std::vector<std::string> npcReplics;
    const int dialogueBoxX = WINDOW_WIDHT - 20;
    const int dialogueBoxY = WINDOW_HEIGHT - 300;  

    std::unique_ptr<UI> dialogueBoxUI;
    std::unique_ptr<UI> pressEText;

    Camera2D camera1;

    // Допоміжні методи
    void DrawNPCText();
    void DrawDialogueBox(const Camera2D& camera);
    void DrawPlayerChoices();
    void HandleChoiceInput();
    void ApplyChoice();
};

#endif