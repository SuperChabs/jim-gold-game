#include "dialoguewindow.h"
#include "ui.h"

DialogueWindow::DialogueWindow(std::vector<std::string>& replics)
{
    npcReplics = replics;
    dialogueBoxUI = std::make_unique<UI>("", 100, 600, 1040, 200, BLACK, WHITE); // screen space
    pressEText = std::make_unique<UI>("Press E", 20, 20, 20, GREEN, true); // screen space
}
void DialogueWindow::Update()
{

}

void DialogueWindow::Draw(Camera2D& camera)
{
    camera1 = camera;
    DrawDialogueBox(camera1);
}

/**************            Setters                 **************/

void DialogueWindow::SetReplic(std::string newReplic) 
{
    npcReplics.push_back(newReplic);
}

/**************            Private Methods                     **************/

void DialogueWindow::DrawNPCText()
{

}

void DialogueWindow::DrawDialogueBox(const Camera2D& camera)
{
    //DrawRectangle(dialogueBoxX, dialogueBoxY, 1040, 200, BLACK);
    dialogueBoxUI->Draw(camera);
}

void DialogueWindow::DrawPlayerChoices()
{

}

void DialogueWindow::HandleChoiceInput()
{

}

void DialogueWindow::ApplyChoice()
{

}
