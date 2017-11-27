//
//  Game.hpp
//  CS202Connect4
//
//  Created by Laura on 11/25/17.
//  Copyright © 2017 Laura. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1024

#include <stdio.h>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "BoardView.hpp"

class Game
{
public:
    Game(int width, int height, std::string title);
private:
    void run(); //called when we start our game
};


#endif /* Game_hpp */
