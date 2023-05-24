//
//  Background.cpp
//  Game-mac
//
//  Created by Jun Lee on 4/7/23.
//  Copyright © 2023 Sanjay Madhav. All rights reserved.
//

#include "Background.h"
#include "Game.h"
#include "ScrollingSpriteComponent.h"

Background::Background(Game* pGame)
:Actor(pGame) {
    SetPosition(Vector2(512.0f, 384.0f));
    
    // Create a background
    //SpriteComponent* bg = new SpriteComponent(this);
	//bg->SetTexture(pGame->GetTexture("Assets/Farback01.png"));
    
	// Create a scrolling background.
	ScrollingSpriteComponent* bg = new ScrollingSpriteComponent(this);
	bg->SetScreenSize(Vector2(1024, 768));
	vector<SDL_Texture*> texes = {
		pGame->GetTexture("/users/jun/Desktop/SpaceGame/SpaceGame/Assets/Farback01.png"),
		pGame->GetTexture("/users/jun/Desktop/SpaceGame/SpaceGame/Assets/Farback02.png")
        //pGame->GetTexture("Assets/Farback01.png"),
        //pGame->GetTexture("Assets/Farback02.png")
	};
	bg->SetScrollingTextures(texes);
	bg->SetScrollSpeed(-100);

	// Create another scrolling background that is
	// "closer" and moves at a different speed.
	ScrollingSpriteComponent* bg2 = new ScrollingSpriteComponent(this);
	bg2->SetScreenSize(Vector2(1024, 768));
	vector<SDL_Texture*> texes2 = {
		pGame->GetTexture("/users/jun/Desktop/SpaceGame/SpaceGame/Assets/Stars.png"),
		pGame->GetTexture("/users/jun/Desktop/SpaceGame/SpaceGame/Assets/Stars.png")
        //pGame->GetTexture("Assets/Stars.png"),
        //pGame->GetTexture("Assets/Stars.png")
	};
	bg2->SetScrollingTextures(texes2);
	bg2->SetScrollSpeed(-200);
}
