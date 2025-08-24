#include "game.h"
#include "scenemanager.h"
#include "audiomanager.h"
#include "housescene.h"
#include "scene2.h"
#include "player.h"
#include "ui.h"

#include <iostream>

#define PLAYER_WIDHT 80
#define PLAYER_HEIGHT 100

UI escapeText("Press ESC to exit", -530, -320, 20, BLACK, true);

Game::Game(int width, int height, const std::string& title)
    : screenWidth(width), screenHeight(height), windowTitle(title), isRunning(false) {

    // Ініціалізація менеджерів
    sceneManager = std::make_unique<SceneManager>();
    audioManager = std::make_unique<AudioManager>();
}

Game::~Game() {
    Cleanup();
}

bool Game::Init() {
    // Ініціалізація Raylib
    InitWindow(screenWidth, screenHeight, windowTitle.c_str());
    SetTargetFPS(60);

    //InitAudioDevice();

    camera.target = {0, 0};
    camera.offset = {screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    isRunning = true;

    player = std::make_shared<Player>(0, 0, PLAYER_WIDHT, PLAYER_HEIGHT, Vector2{32, 32}, "assets/textures/jim_t.png");

    auto houseScene = std::make_unique<HouseScene>();
    auto scene2 = std::make_unique<Scene2>(player);

    sceneManager->AddScene("HouseScene", std::move(houseScene));
    sceneManager->AddScene("Scene2", std::move(scene2));

    sceneManager->SwitchScene("Scene2");

    std::cout << "Game initialized successfully!" << std::endl;
    return true;
}

void Game::Run() {
    if (!Init()) {
        std::cerr << "Failed to initialize game!" << std::endl;
        return;
    }

    while (!WindowShouldClose() && isRunning) {
        deltaTime = GetFrameTime();

        Update();

        if(sceneManager)
            sceneManager->Update(GetFPS());

        camera.target = player->GetPosition();

        BeginDrawing();

        BeginMode2D(camera);

        if (IsKeyPressed(KEY_G)) 
            sceneManager->SwitchScene("Scene2");
        if (IsKeyPressed(KEY_H))
            sceneManager->SwitchScene("HouseScene");

        player->Draw();

        Draw();

        EndMode2D();

        DrawFPS(10, 10);

        DrawText(TextFormat("Player: %.1f, %.1f", player->GetX(), player->GetY()), 10, 30, 10, BLACK);
        
        escapeText.Draw(camera);

        EndDrawing();
    }

    Cleanup();
}

void Game::Update() {
    if (sceneManager) {
        sceneManager->Update(deltaTime);
    }

    if (IsKeyPressed(KEY_F1)) {
        isRunning = false;
    }
}

void Game::Draw()
{
    if (sceneManager) {
        sceneManager->Draw();
    }
}

void Game::Cleanup()
{

    sceneManager.reset();
    audioManager.reset();

    //CloseAudioDevice();
    CloseWindow();

    std::cout << "Game cleaned up successfully!" << std::endl;
}

void Game::SetWindowSize(int width, int height) {
    screenWidth = width;
    screenHeight = height;
    SetWindowSize(width, height);
}

void Game::SetWindowTitle(const std::string& title) {
    windowTitle = title;
    ::SetWindowTitle(title.c_str());
}
