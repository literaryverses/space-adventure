//
//  Ship.h
//  SpaceGame
//
//  Created by Junyup Lee on 5/3/23.
//

#ifndef Ship_h
#define Ship_h

#include "Actor.h"

class Ship : public Actor {
public:
    Ship(class Game* pGame);
    void Update(float deltaTime);
    void ProcessInput(const uint8_t* keyboardState);

private:
    int laserCoolDown;
};


#endif /* Ship_h */
