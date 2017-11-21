//
//  BoardView.cpp
//  CS202Connect4
//
//  Created by Laura on 11/20/17.
//  Copyright © 2017 Laura. All rights reserved.
//

#include "BoardView.hpp"

BoardView::BoardView()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Tic-Tac-Toe");
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color(255, 255, 0));
    // set the shape color to yellow
    
    while (window.isOpen())
    {
        sf::Event event; //handles events
        
        while(window.pollEvent(event)) //while we're polling events on teh event we just created
        {
            switch (event.type)
            {
                    
                case sf::Event::Closed:
                    window.close();  //close when application is closed by the user
                    break;
            }
        }
        window.clear(); //clear the screen every frame
        //objects to draw
        window.draw(circle);
        //circle.setOrigin(10,300);
        circle.setPosition(50,250);
        window.display();
    }
};

BoardView::~BoardView(){};
