//
//  Enemy.h
//  Towerdefence
//
//  Created by Christian Pettersson on 2012-01-09.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Towerdefence_Enemy_h
#define Towerdefence_Enemy_h

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
    Enemy (int in_speed,int in_hp, int in_reward, int in_sprite_nr);
    //Enemy(speed, hp, spritenumber) 
    //destructor
    ~Enemy(){};
    
};

#endif
