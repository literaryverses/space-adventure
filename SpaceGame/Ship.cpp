//
//  Ship.cpp
//  SpaceGame
//
//  Created by Junyup Lee on 5/3/23.
//

#include "Ship.h"
#include "Game.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Laser.h"

Ship::Ship(Game* pGame)
:Actor(pGame) {
    // Set variables
    SetPosition(Vector2(1024/2, 768/2)); // Put Ship in center of screen
    laserCoolDown = 0;
    
    // Create sprite component
    SpriteComponent* sprite = new SpriteComponent(this);
    sprite->SetTexture(pGame->GetTexture("/users/jun/Desktop/SpaceGame/SpaceGame/Assets/ShipWithThrust.png"));
    //sprite->SetTexture(pGame->GetTexture("Assets/ShipWithThrust.png"));

    
    // Create input component
    InputComponent* input = new InputComponent(this);
    input->SetMaxForwardSpeed(200.0f);
    input->SetMaxAngularSpeed(10.0f);
    
    // Set keys for input component
    input->SetForwardKey(SDL_SCANCODE_W);
    input->SetBackKey(SDL_SCANCODE_S);
    input->SetClockwiseKey(SDL_SCANCODE_D);
    input->SetCounterClockwiseKey(SDL_SCANCODE_A);    
}

void Ship::Update(float deltaTime) {
    // Run parent method first
    Actor::Update(deltaTime);
    
    // count down timer
    laserCoolDown -= 1;
}

void Ship::ProcessInput(const uint8_t* keyboardState) {
    // Run parent method first
    Actor::ProcessInput(keyboardState);
    
    // Emit lasers
    if (keyboardState[SDL_SCANCODE_SPACE] && laserCoolDown <= 0) {
        Laser* laser = new Laser(this->GetGame());
        laser->SetPosition(this->GetPosition());
        laser->SetRotation(this->GetRotation());
        
        // Set laserCoolDown to half a second
        laserCoolDown = 2;
    }
}
