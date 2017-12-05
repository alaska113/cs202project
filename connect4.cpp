//
//  connect4.cpp
//  cs202working
//
//  Created by KSUA on 11/27/17.
//  Copyright © 2017 Khan Howe. All rights reserved.
//

#include "connect4.hpp"
#include "InputManager.hpp"
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
#include <stdexcept>
using std::runtime_error;
using std::ostream;
using std::endl;
using std::cout;
using std::setw;


/////////////////
//Checker stuff//
/////////////////

//Default Constructor
Checker::Checker(int turn_n)
{
    //Vector of red or blue colors and screen text
    vector<char> turn_color = {'r','y'};
  
    
    //Set color for checking use
    Checker::setColorChar(turn_color[turn_n%2]);
}


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


//////////////
//Game Stuff//
//////////////
void Game::print_char_board()
{
    vector<vector<sf::Sprite>> v = Game::getConfig();
    char gcolor;
    for(int i = 0;i<6;++i)
    {
        for(int j =0;j<7;++j)
        {
            if(v[i][j].getColor()==sf::Color::Red)
            {
                gcolor = 'r';
            }
            if(v[i][j].getColor()==sf::Color::Yellow)
            {
                gcolor = 'y';
            }
            if(v[i][j].getColor() == sf::Color::White)
            {
                gcolor = 'e';
            }
            std::cout << gcolor << setw(2);
        }
        std::cout << std::endl;
    }
}

//Check function that takes a "board" and the color to check,
//then tells user if it has found a connect fou
void Game::check(const Checker &ch)
{
    char gcolor='x';
    sf::Color color;
    if(ch.getColorChar() == 'r')
        color = sf::Color::Red;
    else
        color = sf::Color::Yellow;
    
    vector<vector<sf::Sprite>> v = Game::getConfig();
    
    //sets sum for counting sequential checkers to zero.
    int sum4 = 0;
    
    //horizontal check
    //loop through rows
    for(auto i=0u;i<6;++i)
    {
        sum4=0;
        cout << i << " " << sum4 << endl;
        //loop through columns
        for(auto j=0u;j<7;++j)
        {
            //if color in index is a match, add 1 to sequential count.
            if(v[i][j].getColor()==color)
            {
                ++sum4;
                cout << i<<j<<" add1 " << sum4 << endl;
            }
            //if not, set sequential count back to zero.
            else
            {
                sum4=0;
            }
            //If a connect four is found, tell user where it is.
            if(sum4==4)
            {
                Game::setStatus(true);
            }
        }

    }
    
    
    //vertical check
    
    //loop throw columns
    for(auto i=0u;i<7;++i)
    {
        //loop threw rows
        for(auto j=0u;j<6;++j)
        {
            if(v[j][i].getColor()==color)
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
                Game::setStatus(true);
            }
        }
        sum4=0;
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
                if(v[i-k][j+k].getColor()==color)
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
                    Game::setStatus(true);
                }
            }
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
                
                if(v[i-k][j-k].getColor()==color)
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
                    Game::setStatus(true);
                }
            }
        }
    }
}

//Piece drop function
void Game::addPiece(Checker & ch)
{
    
    //If the column is already full, prompt user to try another column
    if(_gridPieces[0][ch.getColumn()].getColor() != sf::Color::White)
    {
       // throw runtime_error("Column full! Try another please.");
       // std::cout <<
        //turn(turn_n);
    }
    
    //vector<vector<sf::Sprite>> v = getConfig();
    //initialize empty space counter
    int k = 0;
    
    //Loop through rows
    for(int i = 0;i<6;++i)
    {
        //char gcolor = 'u';
        int row  = i;
        int column = ch.getColumn();
        //std::cout << "row is " << row << " column is " << column << std::endl;
        //sf::Sprite current =v[i][ch.getColumn()];
        if(_gridPieces[row][column].getColor() != sf::Color::White)
        {
            break;
        }
        
        //sets row index to lowest unoccupied row (or the bottom if so)
        k=i;
    }
    //sets row of checker to lowest open row
    ch.setRow(k);
    
    //Board color index switched
    Game::setConfig(ch);
}

//Board configuration accessor.
vector<vector<sf::Sprite>> Game::getConfig()
{
    return _gridPieces;
}

//Mutator for on screen text
void Game::setDisplayText(const std::string & txt)
{
    _displayText = txt;
}
//Accessor for on screen text
std::string Game::getDisplayText() const
{
    return _displayText;
}


//Sets the configuration of checker sprites
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

//Standard Game start, taks a title and begins game.
Game::Game(std::string title)
{
    run();
}

void Game::turn_name(int turn_n)
{
    vector<std::string> turn_v = {"Red's turn!", "Yellow's turn!"};
    //Set display text to implicate turn
    Game::setDisplayText(turn_v[turn_n%2]);
}
//Accessor of turn number
int Game::getTurn() const
{
    return _turn_n;
}

bool Game::getStatus() const
{
    return _connect4;
}

void Game::setStatus(bool s)
{
    _connect4 = s;
}

void Game::set(int col)
{
    //////////////////////////////////////
    //1// Set Turn/Color and Prompt User
    
    Checker Piece = Checker(Game::getTurn());
    Piece.setColumn(col);
    turn_name(_turn_n);
    //draws board, more specifically prompts user after turn is set.
    draw_board(window);
    ////////////////////////////////////
    
    /////////////////////////////////////////////////////////////////////
    //4// Add Piece
    Game::addPiece(Piece);
    //4a// if column is full, reset turn
    if(_gridPieces[0][Piece.getColumn()].getColor() != sf::Color::White)
    {
    }
    //5// Draw Board after piece drop
    Game::draw_board(window);
    Game::check(Piece);
    //6a// if true, tell user and reccomend retry button
    if(getStatus())
    {
        std::cout << "I AM BEING CALLED at the end" << std::endl;
        Game::setDisplayText("A connect 4 has been made!");
        Game::draw_board(window);
    }
    Game::print_char_board();
    //6b// if not, continue to next turn

    ++_turn_n;
}

//Run function that constructs window, sprites, etc. Then takes turns playing game.
void Game::run()
{
    //Initialize turn number
    _turn_n = 0;
    
    //Make vector of sprites, resize to board
    vector<vector<sf::Sprite>> v;
    _gridPieces.resize(6,std::vector<sf::Sprite>(7));
    
    // create the window
    window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Connect 4");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    
    //RETRY BUTTON//
    //load retry button
    sf::Texture textureRetry;
    textureRetry.loadFromFile("Retry Button.png");
    _retrySprite.setTexture(textureRetry);
    _retrySprite.setPosition(1000, 50);
    
    //BOARD//
    //Creates board texture
    sf::Texture _gridTexture; //declare board texture
    _gridTexture.loadFromFile("Connect4_Board.png"); //Set texture to board image
    _gridSprite.setTexture(_gridTexture);
    _gridSprite.setPosition((SCREEN_WIDTH/2)-(_gridSprite.getGlobalBounds().width/2), (SCREEN_HEIGHT/2)-(_gridSprite.getGlobalBounds().height/2));
    
    //PIECES//
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
            _gridPieces[r][c].setPosition(_gridSprite.getPosition().x+(tempSpriteSize.x*c)+5,_gridSprite.getPosition().y + (tempSpriteSize.y*r)+5);
            
            //Sets pieces to white for empty
            _gridPieces[r][c].setColor(sf::Color::White);
        }
    }
    
    bool _connect4 = false;
    
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        
        Game::draw_board(window);
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
        
            while(window.pollEvent(event))
            {
                switch(event.type)
                {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::Num0)
                        {
                            Game::set(0);
                        }
                        if (event.key.code == sf::Keyboard::Num1)
                        {
                            Game::set(1);
                        }
                        if (event.key.code == sf::Keyboard::Num2)
                        {
                            Game::set(2);
                        }
                        if (event.key.code == sf::Keyboard::Num3)
                        {
                            Game::set(3);
                        }
                        if (event.key.code == sf::Keyboard::Num4)
                        {
                            Game::set(4);
                        }
                        if (event.key.code == sf::Keyboard::Num5)
                        {
                            Game::set(5);
                        }
                        if (event.key.code == sf::Keyboard::Num6)
                        {
                            Game::set(6);
                        }
                }
                
            }
    }
    
}

//Function to be called at the end of each turn, takes current window and redraws configuration to screen
void Game::draw_board(sf::RenderWindow & window)
{
    //(Might do some of this initialization elsewhere)//
    // Declare and load a font
    sf::Font font;
    
    //load from file
    font.loadFromFile("/Users/ksua/Documents/cs202working/cs202working/arial.ttf");
    
    // Create a text
    // std::cout << getDisplayText() << std::endl;
    sf::Text text(getDisplayText(),font);
    text.setCharacterSize(50);
    text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::White);
    text.setPosition(800,300);
    
   
    // clear the window with black color
    window.clear(sf::Color::Black);
    
    
    //Draws retry button
    window.draw(_retrySprite);
    //Draws board I believe
    window.draw(_gridSprite);
    
    window.draw(text); //wtf is going on??
    
    //loop through rows
    for (int r=0; r<6; ++r)
    {
        //loop through columns
        for(int c=0; c<7; ++c)
        {
            //draw blank pieces
            window.draw(getConfig()[r][c]);
        }
    }
  
    // end the current frame
    window.display();
    
}

