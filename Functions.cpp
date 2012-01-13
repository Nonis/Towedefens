//
//  Functions.cpp
//  Towerdefence
//
//  Created by Christian Pettersson on 2012-01-12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#define square 16
#include <iostream>
#include <SFML/Graphics.hpp>

//Loads the SpriteSheet.png in to a sf::Image
void load_sprite_sheet(){
    sf::Image spritesheet;
    spritesheet.LoadFromFile("SpriteSheet.png");
    spritesheet.CreateMaskFromColor(sf::Color(255,0,255));
}

//function that sets the returns a IntRect for the subrect on the sf::sprite
sf::IntRect sprite_select(int sprite_nr){
    int row = (sprite_nr / 16);
    int col = (sprite_nr%16)*16;  
    
    // Define a rectangle, located at (0, 0) with a size of 20x5;
    
    // Define a rectangle, located at (0, 0) with a size of 20x5

    sf::IntRect sprite_rect(row*square, col*square, square, square);
    
    return sprite_rect ;

}

