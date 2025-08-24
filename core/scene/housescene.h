#pragma once
#include "scene.h"
#include "raylib.h"

class HouseScene : public Scene {
public:
    HouseScene();
    ~HouseScene() override;
    
    void Update(float deltaTime) override;
    void Draw() override;

private:
    // Color grassColor;
    // Color houseColor;
    // Color roofColor;
};