//
//  Asteroid.cpp
//  SpaceGame
//
//  Created by Junyup Lee on 5/3/23.
//

#include "Asteroid.h"
#include "Game.h"
#include "Actor.h"
#include "Random.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleComponent.h"

Asteroid::Asteroid(Game* pGame)
:Actor(pGame) {
    // start at a random position and rotation
    SetPosition(Random::GetVector(
        Vector2(Random::GetFloat()*1024, Random::GetFloat()*768),
        Vector2(Random::GetFloat()*1024, Random::GetFloat()*768)));
    SetRotation(Random::GetFloat());
    
    // Create sprite component
    SpriteComponent* sprite = new SpriteComponent(this);
    sprite->SetTexture(pGame->GetTexture("/users/jun/Desktop/SpaceGame/SpaceGame/Assets/asteroid.png"));
    //sprite->SetTexture(pGame->GetTexture("Assets/asteroid.png"));
    
    // Create move component
    MoveComponent* move = new MoveComponent(this);
    move->SetForwardSpeed(200.0f * Random::GetFloat());
    move->SetAngularSpeed(5.0f * Random::GetFloat());
    
    // Set radius in circle component
    //circle->SetRadius(40.0f);
    _circle->SetRadius(sprite->GetTexWidth()/2);
}
