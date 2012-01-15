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
#define square 32


class Tower
{    
public:
     //constructor
    Tower (int in_range,int in_damage, int in_level, int in_price, int in_reloadtime, int in_sprite_nr);
    //Tower(range, damage, level, price, reloadtime, spritenumber) 
     //destructor
     ~Tower(){};

    int range; // range * square
    int damage;
    int level; 
    int price; //set the price of the tower
    int reloadtime; // how long between attacks
    int sprite_nr; //defines subrect sprite
   
    sf::Sprite sprite; // sprite
    sf::Image spritesheet;
    sf::Clock reload_clock; // use to count seconds between attacks
    //to set subrect Class_name.sprite.SetSubRect(sprite_select(sprite_nr))
    
    
    virtual bool target_in_range(Enemy *target); // checks if targets is in range, viritual so i can use it with "help towers"
    
    void attack(Enemy *target);// attack target
    
    
};


//constructor
Tower::Tower (int in_range,int in_damage, int in_level, int in_price, int in_reloadtime, int in_sprite_nr){
    this->range = in_range;
    this->damage = in_damage;
    this->level = in_level;
    this->price = in_price;
    this->reloadtime = in_reloadtime;
    this->sprite_nr = in_sprite_nr; 
    
    this->spritesheet.LoadFromFile("SpriteSheet.png");
    this->spritesheet.SetSmooth(false);
    this->spritesheet.CreateMaskFromColor(sf::Color(255,0,255));
    this->sprite.SetImage(spritesheet);
    this->sprite.SetSubRect(sprite_select(this->sprite_nr));
}


//controll of target is in range
bool Tower::target_in_range(Enemy *target)
{
        //Simplest circle collision test possible
        //Distance between points <= sum of radius
        
        float Radius1 = this->range*square;
        float Radius2 = (target->sprite.GetSize().x + target->sprite.GetSize().y) / 4;
        float xd = this->sprite.GetPosition().x - target->sprite.GetPosition().x;
        float yd = this->sprite.GetPosition().y - target->sprite.GetPosition().y;
        
        return sqrt(xd * xd + yd * yd) <= Radius1 + Radius2;
    
}
