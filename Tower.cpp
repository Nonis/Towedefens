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
    Tower (int in_x, int in_y, int in_range,int in_damage, int in_level, int in_price, int in_reloadtime, int in_sprite_nr);
    //Tower(range, damage, level, price, reloadtime, spritenumber) 
     //destructor
     ~Tower(){};

    int range; // range * square
    int damage;
    int level; 
    int price; //set the price of the tower
    int reloadtime; // how long between attacks
    int sprite_nr; //defines subrect sprite
    
    sf::Shape range_radius;
    sf::Sprite sprite; // sprite
    sf::Image spritesheet;
    sf::Clock reload_clock; // use to count seconds between attacks
    //to set subrect Class_name.sprite.SetSubRect(sprite_select(sprite_nr))
    
    
    virtual bool target_in_range(Enemy *target); // checks if targets is in range, viritual so i can use it with "help towers"
    
    void attack(Enemy *target);// attack target
    
    
};


//constructor
Tower::Tower (int in_x, int in_y, int in_range,int in_damage, int in_level, int in_price, int in_reloadtime, int in_sprite_nr){
    this->range = in_range*square;
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
    this->sprite.SetPosition(in_x,in_y);
    
  //  Shape.circle(x, y, r, thick = 1.0, color = Color::White, outline_width = 0.0, outline_color = Color::Clear)
    this->range_radius = range_radius.Circle(this->sprite.GetPosition().x + (this->sprite.GetSize().x / 2),this->sprite.GetPosition().y + (this->sprite.GetSize().y / 2),range,sf::Color(255,255,255,0),5,sf::Color(sf::Color::Black));

}


//controll of target is in range
bool Tower::target_in_range(Enemy *target)
{
        //Simplest circle collision test possible
        //Distance between points <= sum of radius
        
        float Radius1 = this->range;
        float Radius2 = (target->sprite.GetSize().x + target->sprite.GetSize().y) / 4;
        float xd = this->sprite.GetPosition().x - target->sprite.GetPosition().x;
        float yd = this->sprite.GetPosition().y - target->sprite.GetPosition().y;
        
        return sqrt(xd * xd + yd * yd) <= Radius1 + Radius2;
    
}
