//
//  Laser.h
//  SpaceGame
//
//  Created by Junyup Lee on 5/3/23.
//

#ifndef Laser_h
#define Laser_h

#include "Actor.h"
#include "CircleComponent.h"

class Laser : public Actor {
public:
    Laser(class Game* pGame);
    void Update(float deltaTime);
private:
    float deathTimer;
    CircleComponent* _circle = new CircleComponent(this);
};

#endif /* Laser_h */
