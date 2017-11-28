//
//  connect4.cpp
//  cs202working
//
//  Created by KSUA on 11/27/17.
//  Copyright © 2017 Khan Howe. All rights reserved.
//

#include "connect4.hpp"
//#include "4_check.hpp"
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
using std::ostream;
using std::endl;
using std::cout;
using std::setw;


////Temporary populate function that creates a full board of random peices.
//vector<vector<char>> populate(vector<vector<char>> v)
//{
//    //Three checker types; red yellow and empty
//    vector<char> list = {'e','y','r'};
//    //random set
//    srand (time(NULL));
//    //loops through rows
//    for(auto i=0u;i<6;++i)
//    {
//        //loops through columns
//        for(auto j=0u;j<7;++j)
//        {
//            //sets random checker in 2d vector
//            v[i][j] = list[rand()%2+1];
//        }
//    }
//    return v;
//}


//Function that prints the board to an ostream
ostream & Board::print_board(ostream & os)
{
    vector<vector<char>> v = Board::getConfig();
    
    //loops through rows
    for(auto i=0u;i<6;++i)
    {
        //loops through columns
        for(auto j=0u;j<7;++j)
        {
            //send to ostream
            os << setw(2) <<v[i][j];
        }
        //new line (next row)
        os << endl;
    }
    os << " 0 1 2 3 4 5 6 " << endl;
    return os;
}

//Check function that takes a "board" and the color to check,
//then tells user if it has found a connect fou
void Board::check(char color)
{
    vector<vector<char>> v = Board::getConfig();
    //sets sum for counting sequential checkers to zero.
    int sum4 = 0;
    
    
    //horizontal check
    //loop through rows
    for(auto i=0u;i<6;++i)
    {
        //loop through columns
        for(auto j=0u;j<7;++j)
        {
            //if color in index is a match, add 1 to sequential count.
            if(v[i][j]==color)
            {
                ++sum4;
            }
            //if not, set sequential count back to zero.
            else
            {
                sum4=0;
            }
            //If a connect four is found, tell user where it is.
            if(sum4==4)
            {
                cout << "there is a connect 4 horizontally at (" << i << "," << j << ")" << "for color " << color << endl;
                _connect4 = true;
            }
        }
        //cout << "There is no horizontal connect 4 in row " << i << endl;
        sum4=0;
        //cout << endl;
    }
    
    
    //vertical check
    
    //loop throw columns
    for(auto i=0u;i<7;++i)
    {
        //loop threw rows
        for(auto j=0u;j<6;++j)
        {
            //check if index matches color
            if(v[j][i]==color)
            {
                ++sum4;
            }
            //if not, set sequential count back to zero.
            else
            {
                sum4=0;
            }
            //If a connect four is found, tell user where it is.
            if(sum4==4)
            {
                cout << "There is a connect 4 vertically at (" << j << "," << i << ")" << "for color " << color << endl;
                _connect4 = true;
            }
        }
        sum4=0;
        //cout << "There is no vertical connect 4 in column "<< i << endl;
        //cout << endl;
    }
    
    //positive diagonal
    //loop through rows
    for(int i = 4;i<6;++i)
    {
        //loops through columns
        for(int j = 0;j<4;++j)
        {
            sum4=0;
            //iterates through index of piece in upper right placements,
            //where k is the length of pieces from current index.
            for(int k = 0;k<6;++k)
            {
                //If we try to go an index above the board, or an index to the right of the board
                //Tell user that we are breaking the boundary and set counter of sequential pieces to zero.
                //Then move to next piece.
                if(((j+k)>6) || ((i-k)<0))
                {
                    // cout << "I am breaking the boundary" << endl;
                    sum4=0;
                    break;
                }
                //If checker k spaces to the right and k spaces up matches
                //add to sequential counter.
                if(v[i-k][j+k]==color)
                {
                    ++sum4;
                }
                //If not, set sequential counter to zero
                else
                {
                    sum4 = 0;
                }
                //If sequential counter is 4, let user know where a connect four has been made.
                if(sum4==4)
                {
                    cout << "there is a connect 4 positive diagonally at (" << i << "," << j << ")" << "for color " << color << endl;
                    _connect4 = true;
                    
                }
            }
            //If we make it all the way on a positive diagonal without a connect four,
            //set sequential counter to zero and let user know there is not a connect four there.
            
            //cout << "There is no connect 4 in the positive diagonal direction from ("<< i << "," << j << ")" << endl;
        }
    }
    //negative diagonal
    //loop through rows
    for(int i = 4;i<6;++i)
    {
        //loops through columns
        for(int j = 4;j<7;++j)
        {
            sum4=0;
            //iterates through index of piece in upper left placements,
            //where k is the length of pieces from current index.
            for(int k = 0;k<6;++k)
            {
                //If we try to go an index above the board, or an index to the left of the board
                //Tell user that we are breaking the boundary and set counter of sequential pieces to zero.
                //Then move to next piece.
                if(((j-k)>6) || ((i-k)<0))
                {
                    //  cout << "I am breaking the boundary" << endl;
                    sum4=0;
                    break;
                }
                //If checker k spaces to the left and k spaces up matches
                //add to sequential counter.
                if(v[i-k][j-k]==color)
                {
                    ++sum4;
                }
                //If not, set sequential counter to zero
                else
                {
                    sum4 = 0;
                }
                //If sequential counter is 4, let user know where a connect four has been made.
                if(sum4==4)
                {
                    cout << "there is a connect 4 negative diagonally at (" << i << "," << j << ")" << "for color " << color << endl;
                    _connect4 = true;
                }
            }
            //If we make it all the way on a negative diagonal without a connect four,
            //set sequential counter to zero and let user know there is not a connect four there.
            
            //cout << "There is no connect 4 in the positive diagonal direction from ("<< i << "," << j << ")" << endl;
        }
    }
}
/////////////////
//Checker stuff//
/////////////////

//Default Constructor
Checker::Checker(char color) : _color(color)
{}

//Checker index and color accessors
int Checker::getRow() const
{
    return _row;
}
int Checker::getColumn() const
{
    return _column;
}
char Checker::getColor() const
{
    return _color;
}

//Checker index and color mutators
void Checker::setRow(int r)
{
    _row = r;
}
void Checker::setColumn(int c)
{
    _column = c;
}
void Checker::setColor(char color)
{
    _color = color;
}


///////////////
//Board Stuff//
///////////////

//Default Board set up of empty spaces
Board::Board()
{
    //_config.resize(6, std::vector<char>(7,'e'));
    _connect4 = false;
    
    //GRAPHICAL CONSTRUCTION//
    // create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Connect 4");
    
    
    //Make vector of sprites, resize to board
    vector<vector<sf::Sprite>> _gridPieces;
    _gridPieces.resize(6,std::vector<sf::Sprite>(7));
    
    
    //Populate Board with gray pieces
    sf::Texture texturePlain;
    texturePlain.loadFromFile("gray_piece.png");
    
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
        
        for (int r=0; r<6; ++r)
        {
            for (int c=0; c<7; ++c)
            {
                //set texture to 
                _gridPieces[r][c].setTexture(texturePlain);
                
                
                //be sure to set y stuff first then x. Due to the game checking stuff.
                _gridPieces[r][c].setPosition(_gridSprite.getPosition().y+(tempSpriteSize.y*c)+5,_gridSprite.getPosition().x + (tempSpriteSize.x*r)+5);
                
                _gridPieces[r][c].setColor(sf::Color::White);
            }
        }
        // draw everything here...
        // window.draw(...);
        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(_retrySprite);
        //circle.setOrigin(10,300);
        window.draw(_gridSprite);
        for (int r=0; r<6; ++r)
        {
            for(int c=0; c<7; ++c)
            {
                window.draw(_gridPieces[r][c]);
            }
        }
        // end the current frame
        window.display();
        
        
    }
}

//Member function to set board back to empty (might be unnessicary, could just reconstruct same object?)
void Board::clearBoard()
{
    for(auto i=0u;i<6;++i)
    {
        for(auto j=0u;j<7;++j)
        {
            _config[i][j] = 'e';
        }
    }
}

//Piece drop function
void Board::addPiece(Checker & ch)
{
    int k = 0;
    for(int i = 0;i<6;++i)
    {
        //  cout << "i = " << i << endl;
        // cout << "looking at " << (getConfig()[i][ch.getColumn()]) << "in row " << i << endl; //debug
        if((getConfig()[i][ch.getColumn()]) != 'e')
        {
            break;
        }
        k=i;
    }
    //    cout << "k = " << k << endl;
    ch.setRow(k);
    
    //checker index switched
    Board::setConfig(ch.getRow(),ch.getColumn(),ch.getColor());
}

//Board configuration accessor.
vector<vector<char>> Board::getConfig()
{
    return _config;
}


void Board::setConfig(int r, int c, char color)
{
    _config[r][c] = color;
}

bool Board::getStatus() const
{
    return _connect4;
}

Game::Game(int width, int height, std::string title)
{
    run();
    
}

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Connect 4");
    // create the window
    vector<vector<sf::Sprite>> _gridPieces;
    _gridPieces.resize(6,std::vector<sf::Sprite>(7));
    sf::Texture texturePlain;
    texturePlain.loadFromFile("gray_piece.png");
    //textureRed.loadFromFile("red_piece.png");
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

