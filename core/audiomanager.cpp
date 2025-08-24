#include "audiomanager.h"
#include <iostream>
#include <algorithm>

AudioManager::AudioManager()
    : masterVolume(1.0f), sfxVolume(1.0f), musicVolume(1.0f), currentMusic("") {
}

AudioManager::~AudioManager() {
    UnloadAll();
}

bool AudioManager::LoadSound(const std::string& name, const std::string& filePath) {
    if (sounds.find(name) != sounds.end()) {
        std::cout << "Warning: Sound '" << name << "' already loaded!" << std::endl;
        return true;
    }

    Sound sound = ::LoadSound(filePath.c_str());
    if (sound.frameCount == 0) {
        std::cout << "Error: Failed to load sound '" << filePath << "'" << std::endl;
        return false;
    }

    sounds[name] = sound;
    std::cout << "Sound '" << name << "' loaded successfully!" << std::endl;
    return true;
}

void AudioManager::PlaySound(const std::string& name) {
    auto it = sounds.find(name);
    if (it == sounds.end()) {
        std::cout << "Error: Sound '" << name << "' not found!" << std::endl;
        return;
    }

    SetSoundVolume(it->second, masterVolume * sfxVolume);
    ::PlaySound(it->second);
}

void AudioManager::StopSound(const std::string& name) {
    auto it = sounds.find(name);
    if (it != sounds.end()) {
        ::StopSound(it->second);
    }
}

void AudioManager::UnloadSound(const std::string& name) {
    auto it = sounds.find(name);
    if (it != sounds.end()) {
        ::UnloadSound(it->second);
        sounds.erase(it);
        std::cout << "Sound '" << name << "' unloaded!" << std::endl;
    }
}

bool AudioManager::LoadMusic(const std::string& name, const std::string& filePath) {
    if (musicTracks.find(name) != musicTracks.end()) {
        std::cout << "Warning: Music '" << name << "' already loaded!" << std::endl;
        return true;
    }

    Music music = LoadMusicStream(filePath.c_str());
    if (music.frameCount == 0) {
        std::cout << "Error: Failed to load music '" << filePath << "'" << std::endl;
        return false;
    }

    musicTracks[name] = music;
    std::cout << "Music '" << name << "' loaded successfully!" << std::endl;
    return true;
}

void AudioManager::PlayMusic(const std::string& name, bool loop) {
    auto it = musicTracks.find(name);
    if (it == musicTracks.end()) {
        std::cout << "Error: Music '" << name << "' not found!" << std::endl;
        return;
    }

    // Зупинити поточну музику
    if (!currentMusic.empty()) {
        StopMusic();
    }

    currentMusic = name;
    it->second.looping = loop;
    ::SetMusicVolume(it->second, masterVolume * musicVolume);
    PlayMusicStream(it->second);
}

void AudioManager::StopMusic() {
    if (!currentMusic.empty()) {
        auto it = musicTracks.find(currentMusic);
        if (it != musicTracks.end()) {
            StopMusicStream(it->second);
        }
        currentMusic = "";
    }
}

void AudioManager::PauseMusic() {
    if (!currentMusic.empty()) {
        auto it = musicTracks.find(currentMusic);
        if (it != musicTracks.end()) {
            PauseMusicStream(it->second);
        }
    }
}

void AudioManager::ResumeMusic() {
    if (!currentMusic.empty()) {
        auto it = musicTracks.find(currentMusic);
        if (it != musicTracks.end()) {
            ResumeMusicStream(it->second);
        }
    }
}

void AudioManager::UnloadMusic(const std::string& name) {
    auto it = musicTracks.find(name);
    if (it != musicTracks.end()) {
        if (currentMusic == name) {
            StopMusic();
        }
        UnloadMusicStream(it->second);
        musicTracks.erase(it);
        std::cout << "Music '" << name << "' unloaded!" << std::endl;
    }
}

void AudioManager::SetMasterVolume(float volume) {
    masterVolume = std::max(0.0f, std::min(1.0f, volume));
    ::SetMasterVolume(masterVolume);
}

void AudioManager::SetSFXVolume(float volume) {
    sfxVolume = std::max(0.0f, std::min(1.0f, volume));
}

void AudioManager::SetMusicVolume(float volume) {
    musicVolume = std::max(0.0f, std::min(1.0f, volume));

    // Оновити гучність поточної музики
    if (!currentMusic.empty()) {
        auto it = musicTracks.find(currentMusic);
        if (it != musicTracks.end()) {
            ::SetMusicVolume(it->second, masterVolume * musicVolume);
        }
    }
}

bool AudioManager::IsMusicPlaying() const {
    if (currentMusic.empty()) return false;

    auto it = musicTracks.find(currentMusic);
    if (it != musicTracks.end()) {
        return IsMusicStreamPlaying(it->second);
    }
    return false;
}

void AudioManager::UnloadAll() {
    // Зупинити всі звуки
    for (auto& pair : sounds) {
        ::StopSound(pair.second);
        ::UnloadSound(pair.second);
    }
    sounds.clear();

    // Зупинити всю музику
    StopMusic();
    for (auto& pair : musicTracks) {
        UnloadMusicStream(pair.second);
    }
    musicTracks.clear();

    std::cout << "All audio resources unloaded!" << std::endl;
}
