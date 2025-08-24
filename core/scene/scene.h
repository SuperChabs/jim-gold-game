#ifndef SCENE_H
#define SCENE_H

class Scene {
protected:
    const char* name;
    bool active;

public:
    Scene(const char* sceneName) : name(sceneName), active(true) {}
    virtual ~Scene() = default;

    virtual void OnEnter() {}
    virtual void OnExit() {}
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;

    // Getters/Setters
    const char* GetName() const { return name; }
    bool IsActive() const { return active; }
    void SetActive(bool isActive) { active = isActive; }
};

#endif // SCENE_H
