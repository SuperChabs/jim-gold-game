#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#pragma once
#include "raylib.h"
#include <map>
#include <string>

class AudioManager {
private:
    std::map<std::string, Sound> sounds;
    std::map<std::string, Music> musicTracks;

    float masterVolume;
    float sfxVolume;
    float musicVolume;

    std::string currentMusic;

public:
    AudioManager();
    ~AudioManager();

    // Управління звуками
    bool LoadSound(const std::string& name, const std::string& filePath);
    void PlaySound(const std::string& name);
    void StopSound(const std::string& name);
    void UnloadSound(const std::string& name);

    // Управління музикою
    bool LoadMusic(const std::string& name, const std::string& filePath);
    void PlayMusic(const std::string& name, bool loop = true);
    void StopMusic();
    void PauseMusic();
    void ResumeMusic();
    void UnloadMusic(const std::string& name);

    // Управління гучністю
    void SetMasterVolume(float volume);
    void SetSFXVolume(float volume);
    void SetMusicVolume(float volume);

    // Getters
    float GetMasterVolume() const { return masterVolume; }
    float GetSFXVolume() const { return sfxVolume; }
    float GetMusicVolume() const { return musicVolume; }
    const std::string& GetCurrentMusic() const { return currentMusic; }

    // Стан музики
    bool IsMusicPlaying() const;

    // Очищення ресурсів
    void UnloadAll();
};

#endif // AUDIOMANAGER_H
