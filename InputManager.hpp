//
//  InputManager.hpp
//  Connect4Graphics
//
//  Created by Laura on 12/3/17.
//  Copyright © 2017 Laura. All rights reserved.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class InputManager
{
public:
    InputManager() {}
    ~InputManager() {}
    
    bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf:: RenderWindow &window);
    //check if a sprite is clicked
    
    sf::Vector2i getMousePosition(sf::RenderWindow &window);
    //return type-- the mouse position -- call this method and get the mouse position
    
};

#endif /* InputManager_hpp */
