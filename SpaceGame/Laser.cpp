//
//  Laser.cpp
//  SpaceGame
//
//  Created by Junyup Lee on 5/3/23.
//

#include "Laser.h"
#include "Game.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "CircleComponent.h"

Laser::Laser(Game* pGame)
:Actor(pGame) {
    
    deathTimer = 4.0f;
    
    SpriteComponent* sprite = new SpriteComponent(this);
    sprite->SetTexture(pGame->GetTexture("/users/jun/Desktop/SpaceGame/SpaceGame/Assets/Laser.png"));
    //sprite->SetTexture(pGame->GetTexture("Assets/Laser.png"));
    
    // Set radius of circle component
    _circle->SetRadius(11.0f);
}

void Laser::Update(float deltaTime) {
    
    // Decrement the deathTimer
    deathTimer -= 1;
    
    // Destroy after timer up
    if (deathTimer <= 0) {
        SetState(EDead);
    }
    
    for (auto asteroid : this->GetGame()->GetAsteroids()) {
        if (this->_circle->Intersect(*asteroid->GetCircleComponent())) {
            
            // Destroy after collisons
            this->SetState(EDead);
            asteroid->SetState(EDead);
        }
    }
}
