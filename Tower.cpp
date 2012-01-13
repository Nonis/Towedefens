//
//  Tower.cpp
//  Towerdefence
//
//  Created by Christian Pettersson on 2012-01-09.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Functions.h"


using namespace std;
////////////////////////////////////////////////////////////
// Define
////////////////////////////////////////////////////////////
#define square 16

class Tower
{    
public:
    int range; // range * square
    int damage;
    int level; 
    int price; //set the price of the tower
    int reloadtime; // how long between attacks
    int sprite_nr; //defines subrect sprite
    sf::Sprite sprite; // sprite
    
    //to set subrect Class_name.sprite.SetSubRect(sprite_select(sprite_nr))
    
    
    virtual bool target_in_range(Enemy *target); // checks if targets is in range
    
    void attack(Enemy *target);// attack target
    
    
};

//controll of target is in range
bool Tower::target_in_range(Enemy *target)
{
        //Simplest circle collision test possible
        //Distance between points <= sum of radius
        
        float Radius1 = (this->sprite.GetSize().x + this->sprite.GetSize().y) / 4;
        float Radius2 = (target->sprite.GetSize().x + target->sprite.GetSize().y) / 4;
        float xd = this->sprite.GetPosition().x - target->sprite.GetPosition().x;
        float yd = this->sprite.GetPosition().y - target->sprite.GetPosition().y;
        
        return sqrt(xd * xd + yd * yd) <= Radius1 + Radius2;
    
}
