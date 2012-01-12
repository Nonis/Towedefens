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

sf::IntRect sprite_select(int sprite_nr){
    int row = (sprite_nr / 16);
    int col = (sprite_nr%16)*16;  
    
    // Define a rectangle, located at (0, 0) with a size of 20x5;
    
    // Define a rectangle, located at (0, 0) with a size of 20x5

    sf::IntRect sprite_rect(row*square, col*square, square, square);
    
    return sprite_rect ;

}