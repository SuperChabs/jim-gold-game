#ifndef GAME_H
#define GAME_H

#pragma once
#include "raylib.h"
#include "player.h"
#include <memory>
#include <string>
#include <optional>

// Forward declarations
class SceneManager;
class AudioManager;

class Game {
private:
    // Налаштування вікна
    int screenWidth;
    int screenHeight;
    std::string windowTitle;
    bool isRunning;

    // Менеджери
    std::unique_ptr<SceneManager> sceneManager;
    std::unique_ptr<AudioManager> audioManager;

    // Камера
    Camera2D camera;

    // Час
    float deltaTime;

    std::shared_ptr<Player> player;

public:
    // Конструктор
    Game(int width = 800, int height = 600, const std::string& title = "My Game");
    ~Game();

    // Основні методи
    bool Init();
    void Run();
    void Update();
    void Draw();
    void Cleanup();

    // Getters
    int GetScreenWidth() const { return screenWidth; }
    int GetScreenHeight() const { return screenHeight; }
    float GetDeltaTime() const { return deltaTime; }
    Camera2D& GetCamera() { return camera; }
    SceneManager* GetSceneManager() const { return sceneManager.get(); }
    AudioManager* GetAudioManager() const { return audioManager.get(); }

    // Setters
    void SetWindowSize(int width, int height);
    void SetWindowTitle(const std::string& title);
};

#endif // GAME_H
