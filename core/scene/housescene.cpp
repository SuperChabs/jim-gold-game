#include "housescene.h"
#include "scenemanager.h"

HouseScene::HouseScene() : Scene("HouseScene") 
{
   
}

HouseScene::~HouseScene() {}

void HouseScene::Update(float deltaTime) 
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        SetActive(false);
    }
}

void HouseScene::Draw() 
{
    ClearBackground(WHITE);    
}