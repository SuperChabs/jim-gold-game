#pragma once
#include "scene.h"
#include "gameobject.h"
#include "player.h"
#include "npc.h"
#include "dialoguewindow.h"

#include <vector>
#include <memory>

class Scene2 : public Scene {
public:
    Scene2(std::shared_ptr<Player> playerPtr);
    ~Scene2() override;
    
    void Update(float deltaTime) override;
    void Draw() override;

private:
    std::vector<std::vector<std::shared_ptr<GameObject>>> objectMatrix;

    std::vector<std::shared_ptr<GameObject>> rocks;
    std::vector<std::shared_ptr<GameObject>> trees;

    std::vector<std::shared_ptr<NPC>> npcs;

    std::unique_ptr<DialogueWindow> npc1;

    std::vector<std::string> npcReplics;

    std::shared_ptr<Player> player;
};