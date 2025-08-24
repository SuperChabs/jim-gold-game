#ifndef DIALOGUEWINDOW_H
#define DIALOGUEWINDOW_H

#pragma once
#include <string>
#include <vector>
#include "raylib.h"

#define WINDOW_WIDHT 1080
#define WINDOW_HEIGHT 720

class DialogueWindow {
public:
    DialogueWindow(std::vector<std::string>& replics);

    void Update();
    void Draw();

    void SetReplic(std::string newReplic);

private:
    std::vector<std::string> npcReplics;
    const int dialogueBoxX = WINDOW_WIDHT - 20;
    const int dialogueBoxY = WINDOW_HEIGHT - 300;  

    // Допоміжні методи
    void DrawNPCText();
    void DrawDialogueBox();
    void DrawPlayerChoices();
    void HandleChoiceInput();
    void ApplyChoice();
};

#endif