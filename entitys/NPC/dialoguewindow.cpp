#include "dialoguewindow.h"

DialogueWindow::DialogueWindow(std::vector<std::string>& replics)
{
    npcReplics = replics;
}
void DialogueWindow::Update()
{

}

void DialogueWindow::Draw()
{
    DrawDialogueBox();
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

void DialogueWindow::DrawDialogueBox()
{
    DrawRectangle(dialogueBoxX, dialogueBoxY, 1040, 200, BLACK);
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
