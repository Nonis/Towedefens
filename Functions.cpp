//
//  Functions.cpp
//  Towerdefence
//
//  Created by Christian Pettersson on 2012-01-12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#define square 32
#define spritesheet_size 256
#define sprite_size 32

#include <iostream>
#include <SFML/Graphics.hpp>

//function that sets the returns a IntRect for the subrect on the sf::sprite

sf::IntRect sprite_select(int sprite_nr){
    // pos_y = sprite_nr/"how manny sprites per row" * size of sprite
    int pos_y = (sprite_nr/(spritesheet_size/sprite_size))*sprite_size;
    
    // pos_x = whats left after spritenr/"sprites per row" * how manny sprites * spritesize to get starting point of sprite in Y axis
    float pos_x = (((float(sprite_nr)/(spritesheet_size/sprite_size)) - (sprite_nr/(spritesheet_size/sprite_size)))*(spritesheet_size/sprite_size))*sprite_size;
                   
    // Define a rectangle, located at (0, 0) with a ssprite_nr)/squareize of 20x5;
    
    // Define a rectangle, located at (0, 0) with a size of 20x5
    
    sf::IntRect sprite_rect(pos_x, pos_y, pos_x + square, pos_y +square);
    std::cout << std::endl << pos_x << "   " << pos_y;
    return sprite_rect ;

}

