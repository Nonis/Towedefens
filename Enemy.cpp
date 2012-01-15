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

#define square 32

sf::Image spritesheet;


class Enemy
{    
public:
    int speed;
    int hp;
    int reward;
    int sprite_nr;
    bool dead;
    sf::Sprite sprite;
    sf::Image spritesheet;
    
    //constructor
    Enemy (int in_speed,int in_hp,int in_reward, int in_sprite_nr);
    //Enemy(speed, hp, spritenumber) 
    //destructor
    ~Enemy(){};
};

Enemy::Enemy(int in_speed,int in_hp, int in_reward, int in_sprite_nr){
    this->speed = in_speed;
    this->hp = in_hp;
    this->reward = in_reward;
    this->sprite_nr=in_sprite_nr;
    this->spritesheet.LoadFromFile("SpriteSheet.png");
    this->spritesheet.SetSmooth(false);
    this->spritesheet.CreateMaskFromColor(sf::Color(255,0,255));
    this->sprite.SetImage(spritesheet);
    this->sprite.SetSubRect(sprite_select(this->sprite_nr));
    
    
}