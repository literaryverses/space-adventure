// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "CircleComponent.h"
#include "Actor.h"

CircleComponent::CircleComponent(class Actor* pActor)
: Component(pActor)
,_radius(0.0f) {
	
}

const Vector2& CircleComponent::GetCenter() const {
	return _pActor->GetPosition();
}

float CircleComponent::GetRadius() const {
	return _pActor->GetScale() * _radius;
}

// TODO: Implement this method
bool CircleComponent::Intersect(const CircleComponent& other) {
	// Calculate distance squared between this CircleComponet
    // and other.
    float dist_sqr =
    pow(this->GetCenter().x - other.GetCenter().x,2) +
    pow(this->GetCenter().y - other.GetCenter().y,2);
    
	// Calculate the sum of the radii squared.
    float radii_sqr = pow(this->_radius + other._radius, 2);
    
    // Return whether or not the distance squared is less
    // than the radii squared - if it is, Intersect of these
    // two CircleComponets is true.
    if (dist_sqr < radii_sqr) {
        return true;
    }
    
    return false;
}
