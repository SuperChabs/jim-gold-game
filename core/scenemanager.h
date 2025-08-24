#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#pragma once
#include <memory>
#include <map>
#include <string>

#include "scene.h"

class SceneManager {
private:
    std::map<std::string, std::unique_ptr<Scene>> scenes;
    Scene* currentScene;
    std::string currentSceneName;

public:
    SceneManager();
    ~SceneManager();

    // Управління сценами
    void AddScene(const std::string& name, std::unique_ptr<Scene> scene);
    void SwitchScene(const std::string& name);
    void RemoveScene(const std::string& name);

    // Оновлення та рендеринг
    void Update(float deltaTime);
    void Draw();

    // Getters
    Scene* GetCurrentScene() const { return currentScene; }
    const std::string& GetCurrentSceneName() const { return currentSceneName; }
    bool HasScene(const std::string& name) const;
};

#endif // SCENEMANAGER_H
