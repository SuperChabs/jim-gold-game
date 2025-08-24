#include "scenemanager.h"
#include <iostream>

SceneManager::SceneManager() : currentScene(nullptr), currentSceneName("") {
}

SceneManager::~SceneManager() {
    scenes.clear();
}

void SceneManager::AddScene(const std::string& name, std::unique_ptr<Scene> scene) {
    if (scenes.find(name) != scenes.end()) {
        std::cout << "Warning: Scene '" << name << "' already exists!" << std::endl;
        return;
    }

    scenes[name] = std::move(scene);
    std::cout << "Scene '" << name << "' added successfully!" << std::endl;
}

void SceneManager::SwitchScene(const std::string& name) {
    auto it = scenes.find(name);
    if (it == scenes.end()) {
        std::cout << "Error: Scene '" << name << "' not found!" << std::endl;
        return;
    }

    // Вихід з поточної сцени
    if (currentScene) {
        currentScene->OnExit();
    }

    // Перемикання на нову сцену
    currentScene = it->second.get();
    currentSceneName = name;

    // Вхід в нову сцену
    if (currentScene) {
        currentScene->OnEnter();
    }

    std::cout << "Switched to scene: " << name << std::endl;
}

void SceneManager::RemoveScene(const std::string& name) {
    auto it = scenes.find(name);
    if (it == scenes.end()) {
        std::cout << "Error: Scene '" << name << "' not found!" << std::endl;
        return;
    }

    // Якщо видаляємо поточну сцену
    if (currentSceneName == name) {
        if (currentScene) {
            currentScene->OnExit();
        }
        currentScene = nullptr;
        currentSceneName = "";
    }

    scenes.erase(it);
    std::cout << "Scene '" << name << "' removed!" << std::endl;
}

void SceneManager::Update(float deltaTime) {
    if (currentScene && currentScene->IsActive()) {
        currentScene->Update(deltaTime);
    }
}

void SceneManager::Draw() {
    if (currentScene && currentScene->IsActive()) {
        currentScene->Draw();
    }
}

bool SceneManager::HasScene(const std::string& name) const {
    return scenes.find(name) != scenes.end();
}
