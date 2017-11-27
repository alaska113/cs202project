//
//  Game.cpp
//  CS202Connect4
//
//  Created by Laura on 11/25/17.
//  Copyright © 2017 Laura. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

Game::Game(int width, int height, std::string title)
{
    run();

}

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Connect 4");
    // create the window
    
    sf::Sprite _gridPieces[7][6];//array of pieces that will be placed on the grid
    sf::Texture texturePlain, textureRed, textureYellow;
    texturePlain.loadFromFile("gray_piece.png");
    textureRed.loadFromFile("red_piece.png");
//    textureYellow.loadFromFile("yellow_piece.png")
    
    //load retry button
    sf::Texture textureRetry;
    textureRetry.loadFromFile("Retry Button.png");
    sf::Sprite _retrySprite;
    _retrySprite.setTexture(textureRetry);
    _retrySprite.setPosition(1000, 50);
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        sf::Texture _gridTexture;
        _gridTexture.loadFromFile("Connect4_Board.png");
        sf::Sprite _gridSprite;
        _gridSprite.setTexture(_gridTexture);
        _gridSprite.setPosition(50, 50);
        
        sf::Vector2u tempSpriteSize = texturePlain.getSize();
        
        
        for (int col=0; col<7; col++)
        {
            for(int row=0; row<6; row++)
            {
                _gridPieces[col][row].setTexture(texturePlain);
                _gridPieces[col][row].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x*col)+5, _gridSprite.getPosition().y+(tempSpriteSize.y*row)+5);
                _gridPieces[col][row].setColor(sf::Color::White);
            }
        }
        sf::Clock clock; // starts the clock
        
        sf::Time elapsed1 = clock.getElapsedTime();
        std::cout << elapsed1.asSeconds() << std::endl;
        clock.restart();
        //...
        sf::Time elapsed2 = clock.getElapsedTime();
        std::cout << elapsed2.asSeconds() << std::endl;
        
        // draw everything here...
        // window.draw(...);
        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(_retrySprite);
        //circle.setOrigin(10,300);
        window.draw(_gridSprite);
        for (int col=0; col<7; col++)
        {
            for(int row=0; row<6; row++)
            {
                window.draw(_gridPieces[col][row]);
            }
        }
        // end the current frame
        window.display();
    }
}
