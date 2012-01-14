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
    sf::RenderWindow App(sf::VideoMode(640, 480), "Towerdefence");
    
    //Test create a tower and draw it on screen
        
        // Tower(range,damage,level,price,reloadtime,sprite_nr)
       Tower towertest1(4, 10, 1, 100, 1, 1);

    
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
    
        // Clear screen
        App.Clear(sf::Color(255,255,255));
        // Draw apredefined shape
        App.Draw(towertest1.sprite);
        // Finally, display the rendered frame on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
