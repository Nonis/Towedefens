//
//  Tower.h
//  Towerdefence
//
//  Created by Christian Pettersson on 2012-01-09.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Towerdefence_Tower_h
#define Towerdefence_Tower_h

class Tower
{    
public:
    //constructor
    Tower (int in_range,int in_damage, int in_level, int in_price, int in_reloadtime, int in_sprite_nr);
    Tower();
    //Tower(range, damage, level, price, reloadtime, spritenumber) 


    //destructor
    ~Tower(){};
    
    int range; // range * square
    int damage;
    int level; 
    int price; //set the price of the tower
    int reloadtime; // how long between attacks
    int sprite_nr; //defines subrect sprite
    sf::Image spritesheet;
    sf::Sprite sprite; // sprite
    sf::Clock reload_clock; // use to count seconds between attacks
    //to set subrect Class_name.sprite.SetSubRect(sprite_select(sprite_nr))
    
    virtual bool target_in_range(Enemy *target);
    void attack(Enemy *target);
    
    
};


#endif
