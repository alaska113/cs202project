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


////Function that prints the board to an ostream
//ostream & Board::print_board(ostream & os)
//{
//    vector<vector<sf::Sprite>> v = Board::getConfig();
//
//    //loops through rows
//    for(auto i=0u;i<6;++i)
//    {
//        //loops through columns
//        for(auto j=0u;j<7;++j)
//        {
//            //send to ostream
//            os << setw(2) <<v[i][j];
//        }
//        //new line (next row)
//        os << endl;
//    }
//    os << " 0 1 2 3 4 5 6 " << endl;
//    return os;
//}

//Check function that takes a "board" and the color to check,
//then tells user if it has found a connect fou
void Game::check(const Checker &ch)
{
    char gcolor;
    char color = ch.getColorChar();
    vector<vector<sf::Sprite>> v = Game::getConfig();
    
    //sets sum for counting sequential checkers to zero.
    int sum4 = 0;
    
    
    //horizontal check
    //loop through rows
    for(auto i=0u;i<6;++i)
    {
        //loop through columns
        for(auto j=0u;j<7;++j)
        {
            
            if(v[i][j].getColor()==sf::Color::Red)
            {
                gcolor = 'r';
            }
            if(v[i][j].getColor()==sf::Color::Yellow)
            {
                gcolor = 'y';
            }
            //if color in index is a match, add 1 to sequential count.
            if(gcolor==color)
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
//                cout << "there is a connect 4 horizontally at (" << i << "," << j << ")" << "for color " << color << endl;
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
            if(v[j][i].getColor()==sf::Color::Red)
            {
                gcolor = 'r';
            }
            if(v[j][i].getColor()==sf::Color::Yellow)
            {
                gcolor = 'y';
            }
            
            //check if index matches color
            if(gcolor==color)
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
                //cout << "There is a connect 4 vertically at (" << j << "," << i << ")" << "for color " << color << endl;
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
                if(v[i-k][j+k].getColor()==sf::Color::Red)
                {
                    gcolor = 'r';
                }
                if(v[i-k][j+k].getColor()==sf::Color::Yellow)
                {
                    gcolor = 'y';
                }
                
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
                if(gcolor==color)
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
                    //cout << "there is a connect 4 positive diagonally at (" << i << "," << j << ")" << "for color " << color << endl;
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
                
                if(v[i-k][j-k].getColor()==sf::Color::Red)
                {
                    gcolor = 'r';
                }
                if(v[i-k][j-k].getColor()==sf::Color::Yellow)
                {
                    gcolor = 'y';
                }
                
                //If checker k spaces to the left and k spaces up matches
                //add to sequential counter.
                if(gcolor==color)
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
                   // cout << "there is a connect 4 negative diagonally at (" << i << "," << j << ")" << "for color " << color << endl;
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
char Checker::getColorChar() const
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
void Checker::setColorChar(char color)
{
    _color = color;
}


//Piece drop function
void Game::addPiece(Checker & ch)
{
    char gcolor;
    vector<vector<sf::Sprite>> v = getConfig();
    //initialize empty space counter
    int k = 0;
    
    //Loop through rows
    for(int i = 0;i<6;++i)
    {
        sf::Sprite current =v[i][1];
        if(current.getColor() == sf::Color::White)
        {
            gcolor = 'e';
        }
        
        //if next row is not empty, break out of loop.
        if(gcolor != 'e')
        {
            break;
        }
        
        //sets row index to lowest unoccupied row (or the bottom if so)
        k=i;
    }
    
    ch.setRow(k);
    
    //Board color index switched
    Game::setConfig(ch);
}

//Board configuration accessor.
vector<vector<sf::Sprite>> Game::getConfig()
{
    return _gridPieces;
}


void Game::setConfig(const Checker &ch)
{
    //Get color of current checker
    char color = ch.getColorChar();
    
    //takes color, and uses a switch to change the color of the texture on the board.
    switch (color) {
            //if red, change to red texture
        case 'r':
            _gridPieces[ch.getRow()][ch.getColumn()].setColor(sf::Color::Red);
            break;
            //if yellow, change to yellow texture
        case 'y':
            _gridPieces[ch.getRow()][ch.getColumn()].setColor(sf::Color::Yellow);
            break;
    }
}


//maybe make this an overloaded operator?
//void Game::setGrid(const vector<vector<sf::Sprite>> &board)
//{
//    for(int r = 0; r<6; ++r)
//    {
//        for(int c = 0; c<7; ++c)
//        {
//            _gridPieces[r][c] = board[r][c];
//        }
//    }
//}
bool Game::getStatus() const
{
    return _connect4;
}

Game::Game(std::string title)
{
    run();
}

void Game::run()
{
    
    _connect4 = false;
    //Make vector of sprites, resize to board
    vector<vector<sf::Sprite>> v;
    _gridPieces.resize(6,std::vector<sf::Sprite>(7));
    
    
    
    /////////////////GRAPHICAL CONSTRUCTION////////////////
    
    
    
    //Window//
    // create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Connect 4");
    
    // clear the window with black color
    window.clear(sf::Color::Black);
    

    
    //Retry Button//
    //load retry button
    sf::Texture textureRetry;
    textureRetry.loadFromFile("Retry Button.png");
    sf::Sprite _retrySprite;
    _retrySprite.setTexture(textureRetry);
    _retrySprite.setPosition(1000, 50);
    
    //Draws retry button
    window.draw(_retrySprite);
    
    
    //Board//
    //Creates board texture
    sf::Texture _gridTexture; //declare board texture
    _gridTexture.loadFromFile("Connect4_Board.png"); //Set texture to board image
    
    
    
    
    //not sure?
    sf::Sprite _gridSprite;
    _gridSprite.setTexture(_gridTexture);
    _gridSprite.setPosition(50, 50);
    
    //Draws board I believe
    window.draw(_gridSprite);
    
    
    
    //Pieces//
    //Make texture for empty piece
    sf::Texture texturePlain;
    texturePlain.loadFromFile("gray_piece.png");
    sf::Vector2u tempSpriteSize = texturePlain.getSize();
    
    //Nested loops set the pieces in place and makes empty spaces
    //Loop through Rows
    for (int r=0; r<6; ++r)
    {
        //Loop through Columns
        for (int c=0; c<7; ++c)
        {
            //set texture to plain piece
            _gridPieces[r][c].setTexture(texturePlain);
            
            //be sure to set y stuff first then x. Due to the game checking stuff.
            _gridPieces[r][c].setPosition(_gridSprite.getPosition().y+(tempSpriteSize.y*c)+5,_gridSprite.getPosition().x + (tempSpriteSize.x*r)+5);
            
            //Sets pieces to white for empty
            _gridPieces[r][c].setColor(sf::Color::White);
        }
    }
    

    
   
    
    
    //circle.setOrigin(10,300);
    
    
    
   // Board board = Board();
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
        
        Checker p1 = Checker('r');
        Game::addPiece(p1);
        
        _gridPieces[0][0].setColor(sf::Color::Yellow);
        
        //loop through rows
        for (int r=0; r<6; ++r)
        {
            //loop through columns
            for(int c=0; c<7; ++c)
            {
                //draw blank pieces
                window.draw(_gridPieces[r][c]);
            }
        }
        // end the current frame
        window.display();
    }
}


//void Game::run()
//{
//    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Connect 4");
//    // create the window
//    vector<vector<sf::Sprite>> _gridPieces;
//    _gridPieces.resize(6,std::vector<sf::Sprite>(7));
//    sf::Texture texturePlain;
//    texturePlain.loadFromFile("gray_piece.png");
//    //textureRed.loadFromFile("red_piece.png");
//    //    textureYellow.loadFromFile("yellow_piece.png")
//
//    //load retry button
//    sf::Texture textureRetry;
//    textureRetry.loadFromFile("Retry Button.png");
//    sf::Sprite _retrySprite;
//    _retrySprite.setTexture(textureRetry);
//    _retrySprite.setPosition(1000, 50);
//
//    // run the program as long as the window is open
//    while (window.isOpen())
//    {
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        sf::Texture _gridTexture;
//        _gridTexture.loadFromFile("Connect4_Board.png");
//        sf::Sprite _gridSprite;
//        _gridSprite.setTexture(_gridTexture);
//        _gridSprite.setPosition(50, 50);
//
//        sf::Vector2u tempSpriteSize = texturePlain.getSize();
//
//
//        for (int col=0; col<7; col++)
//        {
//            for(int row=0; row<6; row++)
//            {
//                _gridPieces[col][row].setTexture(texturePlain);
//                _gridPieces[col][row].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x*col)+5, _gridSprite.getPosition().y+(tempSpriteSize.y*row)+5);
//                _gridPieces[col][row].setColor(sf::Color::White);
//            }
//        }
//
//
//        sf::Clock clock; // starts the clock
//
//        sf::Time elapsed1 = clock.getElapsedTime();
//        std::cout << elapsed1.asSeconds() << std::endl;
//        clock.restart();
//        //...
//        sf::Time elapsed2 = clock.getElapsedTime();
//        std::cout << elapsed2.asSeconds() << std::endl;
//
//        // draw everything here...
//        // window.draw(...);
//        // clear the window with black color
//        window.clear(sf::Color::Black);
//        window.draw(_retrySprite);
//        //circle.setOrigin(10,300);
//        window.draw(_gridSprite);
//        for (int col=0; col<7; col++)
//        {
//            for(int row=0; row<6; row++)
//            {
//                window.draw(_gridPieces[col][row]);
//            }
//        }
//        // end the current frame
//        window.display();
//    }
//}
//
