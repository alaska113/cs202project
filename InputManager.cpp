//
//  InputManager.cpp
//  Connect4Graphics
//
//  Created by Laura on 12/3/17.
//  Copyright © 2017 Laura. All rights reserved.
//

#include "InputManager.hpp"

//check if a sprite is clicked
bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf:: RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height); //temp for our object to see if it contains the mouse
        //check for any collision
        if(tempRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }
    return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition(window);
}
