// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "SDL2/SDL.h"
#include <unordered_map>
#include <string>
#include <vector>
#include "Actor.h"
#include "Asteroid.h"

class Game {
public:
    Game();
    bool Initialize();
    void RunLoop();
    void Shutdown();

    void AddActor(class Actor* actor);
    void RemoveActor(class Actor* actor);

    std::vector <Asteroid*> GetAsteroids() { return _vecAsteroids; }
    
    SDL_Texture* GetTexture(const std::string& fileName);
    
private:
    void _processInput();
    void _updateGame();
    void _generateOutput();
    void _loadData();
    void _unloadData();
    
    // Map of textures loaded
    std::unordered_map<std::string, SDL_Texture*> _mapTextures;

    // All the actors in the game
    std::vector<class Actor*> _vecActors;
    
    // All the asteroids in the game
    std::vector<class Asteroid*> _vecAsteroids;
    
    SDL_Window* _pWindow;
    SDL_Renderer* _pRenderer;
    Uint32 _ticksCount;
    bool _isRunning;
};
