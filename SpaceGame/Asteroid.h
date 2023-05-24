//
//  Asteroid.h
//  SpaceGame
//
//  Created by Junyup Lee on 5/3/23.
//

#ifndef Asteroid_h
#define Asteroid_h

#include "Actor.h"
#include "CircleComponent.h"

class Asteroid : public Actor {
public:
    Asteroid(class Game* pGame);
    CircleComponent* GetCircleComponent() { return _circle; }
private:
    CircleComponent* _circle = new CircleComponent(this);
};

#endif /* Asteroid_h */
