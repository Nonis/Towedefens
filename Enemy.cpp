//
//  enemies.cpp
//  Towerdefence
//
//  Created by Christian Pettersson on 2012-01-09.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Functions.h"

#define square 16


class Enemy
{    
public:
    int speed;
    int hp;
    sf::Sprite sprite;
    
};