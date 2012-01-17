////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Tower.h"
#include "Map.h"
#include "Functions.h"
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////
// Define
////////////////////////////////////////////////////////////
#define square 32

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    int animation = 0;
    // Create main window
    sf::RenderWindow App(sf::VideoMode(1200, 700), "Towerdefence");
   
    
    //Test create a tower and an enemy.
    
    // Tower(position x, position y, range, damage, level, price,reloadtime, sprite_nr)
    Tower towertest1(square*2,square*3,3, 10, 1, 100, 1, 1);
    //Enemy(speed, hp, reward, sprite_nr)
    Enemy enemytest1(5,100,1000,2);
    
        
   


    
    // Start game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
        }
        const sf::Input& Input = App.GetInput();
        
         // Clear screen and puts a dark green background color
        App.Clear(sf::Color(15,100,25));

    //just for test, if space is pushed the background changes to white if target is in range
        if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Space)){
           if(towertest1.target_in_range(& enemytest1))
               App.Clear(sf::Color(255,255,255));
        }
        
        
    //just for test, A and S moves the enemy.sprite left and right to test target_in_range function
        if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::A))
            enemytest1.sprite.Move(-0.2,0);
        if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::S))
            enemytest1.sprite.Move(0.2,0);
        
        
        
    
    // just for test, if mouse is moved over an tower the range_circle is shown    
        if(Event.Type == sf::Event::MouseMoved)
            if(Input.GetMouseX()>towertest1.sprite.GetPosition().x && Input.GetMouseX()<(towertest1.sprite.GetPosition().x+square) && Input.GetMouseY()>towertest1.sprite.GetPosition().y && Input.GetMouseY()<(towertest1.sprite.GetPosition().y+square)){
                App.Draw(towertest1.range_radius);
            }
           

           
    
       
        // Draw apredefined shape
        App.Draw(towertest1.sprite);
        if(enemytest1.hp>0)
            App.Draw(enemytest1.sprite);

        // Finally, display the rendered frame on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
