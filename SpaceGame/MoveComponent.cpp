// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "MoveComponent.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* pActor, int updateOrder)
:Component(pActor, updateOrder)
,_angularSpeed(0.0f)
,_forwardSpeed(0.0f) {
	
}

void MoveComponent::Update(float deltaTime) {
    // Check if angular speed is "close enough" to zero.
	if (!Math::NearZero(_angularSpeed)) {
        // Get the actor's current rotation and add to it.
		float rot = _pActor->GetRotation();
		rot += _angularSpeed * deltaTime;
        _pActor->SetRotation(rot);
	}
	
    // Check if forward speed is "close enough" to zero.
	if (!Math::NearZero(_forwardSpeed)) {
        // Get the actor's current position and add to it.
		Vector2 pos = _pActor->GetPosition();
		pos += _pActor->GetForward() * _forwardSpeed * deltaTime;
		
        // Screen wrapping horizontally
        if (pos.x < 0) {
            pos.x = 1024;
        } else if (pos.x > 1024) {
            pos.x = 0;
        }
        
        // Screen wrapping vertically
        if (pos.y < 0) {
            pos.y = 764;
        } else if (pos.y > 764) {
            pos.y = 0;
        }
        
        _pActor->SetPosition(pos);
    }
}
