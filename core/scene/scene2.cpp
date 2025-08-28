#include "scene2.h"
#include "scenemanager.h"
#include "gameobject.h"
#include "player.h"
#include "npc.h"
#include "dialoguewindow.h"

#include <vector>
#include <memory>
#include <iostream>

Scene2::Scene2(std::shared_ptr<Player> playerPtr, std::shared_ptr<Camera2D> cameraPtr) : Scene("Scene2"), player(playerPtr), camera(std::move(cameraPtr)) 
{
    rocks.push_back(std::make_unique<GameObject>(200, 200, 150, 150, 17, 17, "assets/textures/rock1.png"));
    rocks.push_back(std::make_unique<GameObject>(0, 200, 150, 150, 17, 17, "assets/textures/rock1.png"));
    rocks.push_back(std::make_unique<GameObject>(0, 500, 150, 150, 17, 17, "assets/textures/rock1.png"));
    rocks.push_back(std::make_unique<GameObject>(0, 600, 150, 150, 17, 17, "assets/textures/rock1.png"));
    rocks.push_back(std::make_unique<GameObject>(0, 700, 150, 150, 17, 17, "assets/textures/rock1.png"));
    rocks.push_back(std::make_unique<GameObject>(0, 800, 150, 150, 17, 17, "assets/textures/rock1.png"));

    npcs.push_back(std::make_unique<NPC>(-100, -100, 80, 100, 80, 100, "assets/textures/bad_jim.png"));

    npcReplics.push_back("pidaras");

    for (int i = 0; i < rocks.size(); i++) 
    {
        rocks[i]->SetHitboxOffset(75, 110);
        rocks[i]->SetHitboxSize(100, 50);
    }

    npcDialogueWindows1 = std::make_unique<DialogueWindow>(npcReplics);
};

Scene2::~Scene2() 
{   
    rocks.clear();    
}

void Scene2::Update(float deltaTime)
{
    std::vector<std::shared_ptr<GameObject>> rockPtrs;
    for (auto& rock : rocks) 
        rockPtrs.push_back(std::shared_ptr<GameObject>(rock.get(), [](GameObject*){}));
    objectMatrix.push_back(rockPtrs);

    player->Update({0, 0}, objectMatrix);
}

void Scene2::Draw()
{
    ClearBackground(RAYWHITE);

    for(auto& rock : rocks) 
    {
        rock->Draw();
    }

    if (IsKeyDown(KEY_J)) 
    {
        for (auto& row : objectMatrix) 
        {
            for (auto obj : row) 
            {
                Rectangle hitbox = obj->GetHitbox();
                DrawRectangleLines(hitbox.x, hitbox.y, hitbox.width, hitbox.height, RED);
            }
        }
    }

    for (auto& npc : npcs) 
    {
        npc->Draw();
    }

        for (auto& npc : npcs)
    {
        if (CheckCollisionRecs(player->GetHitbox(), npc->GetHitbox())) 
        {
            DrawText("Press E", 0, 0, 20, GREEN);
            std::cout << "Collision between player and npc\n";
        }

        if (IsKeyPressed(KEY_E) && CheckCollisionRecs(player->GetHitbox(), npc->GetHitbox())) 
        {
            npcDialogueWindows1->Draw(*camera);
            std::cout << "Dialogue box has been drawen\n";
        }

    }
}
