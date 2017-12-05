//
//  connect4.cpp
//  cs202working
//
//  Created by KSUA on 11/27/17.
//  Copyright © 2017 Khan Howe. All rights reserved.
//
//This function file contains all necessary functions to construct the game of connect 4.
//To play the game, simply make a call of the constructor Game("Title")
//Select a column to drop a piece, or keys 1-7 to corresponding columns.
//To reset the game, click the reset button in the upper right hand corner, or press escape.

#include "connect4.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
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

void Game::retry()
{
    for(int i = 0;i<6;++i)
    {
        for(int j = 0;j<7;++j)
        {
            _gridPieces[i][j].setColor(sf::Color::White);
        }
    }
    _retrySprite.setColor(sf::Color::Blue);
    Game::setDisplayText("Game Reset!");
    Game::setStatus(false);
}

//for use in debugging
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
    //initializes temporary color property
    sf::Color color;
    
    //If checker color property is red, set color check to red
    if(ch.getColorChar() == 'r')
        color = sf::Color::Red;
    //else set to yellow
    else
        color = sf::Color::Yellow;
    
    //Get checker sprite configuration
    vector<vector<sf::Sprite>> v = Game::getConfig();
    
    
    //sets sum for counting sequential checkers to zero.
    int sum4 = 0;
    
    //horizontal check
    //loop through rows
    for(auto i=0u;i<6;++i)
    {
        //Sets sum to zero before checking next row
        sum4=0;
        //loop through columns
        for(auto j=0u;j<7;++j)
        {
            //if color in index is a match, add 1 to sequential count.
            if(v[i][j].getColor()==color)
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
                //Sets connect 4 status to true.
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
        //sets sum to 0 before next column
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
                //If a connect 4 has been made, set status to true
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
    //initialize empty space counter
    int k = 0;
    
    //Loop through rows
    for(int i = 0;i<6;++i)
    {
        int row  = i;
        int column = ch.getColumn();
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

//Function that sets the red or yellow turn based on the turn number
void Game::turn_name(int turn_n)
{
    //First iterate turn
    ++turn_n;
    
    //Initializes turn description vector
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
    //1// Set Turn/Color and Prompt User
    Checker Piece = Checker(Game::getTurn());
    Piece.setColumn(col);
    turn_name(_turn_n);
    
    //draws board, more specifically prompts user after turn is set.
    draw_board(window);
    
    //4// Add Piece
    Game::addPiece(Piece);
    
    //5// Draw Board after piece drop
    Game::draw_board(window);
    Game::check(Piece);
    
    //6a// if true, tell user and reccomend retry button
    if(getStatus())
    {
        Game::setDisplayText("Connect 4!");
        Game::draw_board(window);
    }
   // Game::print_char_board();
    
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
    window.setFramerateLimit(20);
    window.setKeyRepeatEnabled(false);
    
    
    //RETRY BUTTON//
    //load retry button
    sf::Texture textureRetry;
    textureRetry.loadFromFile("Retry Button.png");
    _retrySprite.setTexture(textureRetry);
    _retrySprite.setPosition(SCREEN_WIDTH-270, SCREEN_HEIGHT-675);
    
    //BOARD//
    //Creates board texture
    sf::Texture _gridTexture;
    //Loads texture for board
    _gridTexture.loadFromFile("Connect4_Board.png"); //Set texture to board image
    //Sets board texture to board sprite
    _gridSprite.setTexture(_gridTexture);
    //Sets position of board sprite
    _gridSprite.setPosition((SCREEN_WIDTH/2)-(_gridSprite.getGlobalBounds().width/2), (SCREEN_HEIGHT/2)-(_gridSprite.getGlobalBounds().height/2));
    
    //PIECES//
    //Make texture for empty piece
    sf::Texture texturePlain;
    //Loads texture for piece
    texturePlain.loadFromFile("gray_piece.png");
    //Sets size of piece
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
    
    //sets connect 4 status to flase
    bool _connect4 = false;
    
    //Tells user first turn
    Game::setDisplayText("Red's turn!");
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        
        //Draws the board first
        Game::draw_board(window);
        
        //Declares event
        sf::Event event;
        
        // check all the window's events that were triggered since the last iteration of the loop
        while(window.pollEvent(event))
        {
            
            //Switch to set multiple cases of events
            switch(event.type)
            {
                    
                    //If window is set to close, close window.
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                    //If a key was pressed
                case sf::Event::KeyPressed:
                    //if key pressed, retry sprite reset
                    _retrySprite.setColor(sf::Color::White);
                    
                    //If the key that was pressed is 1, choose column 0
                    if (event.key.code == sf::Keyboard::Num1)
                    {
                        Game::set(0);
                        break;
                    }
                    //" "
                    if (event.key.code == sf::Keyboard::Num2)
                    {
                        Game::set(1);
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Num3)
                    {
                        Game::set(2);
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Num4)
                    {
                        Game::set(3);
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Num5)
                    {
                        Game::set(4);
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Num6)
                    {
                        Game::set(5);
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Num7)
                    {
                        Game::set(6);
                        break;
                    }
                    
                    //If escape is pressed, reset game
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        Game::retry();
                        break;
                    }
                case sf::Event::MouseButtonPressed:
                    //if click made, reset button turned back white
                    _retrySprite.setColor(sf::Color::White);
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i touchPoint {event.mouseButton.x,event.mouseButton.y};
                        
                        sf::FloatRect gridSize = _gridSprite.getGlobalBounds();
                        
                        //distance between the screen width and the screen width so it's centered
                        sf::Vector2f outsideGrid = sf::Vector2f((SCREEN_WIDTH-gridSize.width)/2, (SCREEN_HEIGHT-gridSize.height)/2);
                        
                        //touch position relative to the grid, as if the origin started at the top left hand corner of the grid
                        sf::Vector2f gridLocalTouchPos = sf::Vector2f(touchPoint.x-outsideGrid.x, touchPoint.y - outsideGrid.y);
                        
                        //get the actual (x,y) width/height of each grid column and row
                        sf::Vector2f columnSize = sf::Vector2f(gridSize.width/7, gridSize.height/6);
                        
                        int column, row=0;
                        //check which column the user has clicked
                        
                        
                        //little bump in placement
                        int bb = 50;
                        
                        //x-y bounds of sprite
                        int right = (_retrySprite.getPosition().x)+(_retrySprite.getGlobalBounds().width) + bb;
                        int left = (_retrySprite.getPosition().x)-(_retrySprite.getGlobalBounds().width/2) + bb;
                        int top = 0;
                        int bottom = (_retrySprite.getPosition().y)+(_retrySprite.getGlobalBounds().height) + bb;
                        
                        //If mousepress is within bounds of sprite, reset game.
                        if((left< touchPoint.x)&&(right> touchPoint.x)&&(top<touchPoint.y)&&(bottom>touchPoint.y))
                        {
                            Game::retry();
                            break;
                        }
                        
                        //if it's in the first column, the x coordinate of the gridLocalTouchPos will be less than the size of the column itself
                        if(gridLocalTouchPos.x < columnSize.x)
                        {
                            for(row=0;row<6;row++)
                            {
                                set(0);
                                break;
                            }
                        }
                        else if(gridLocalTouchPos.x < columnSize.x*2)
                        {
                            for(row=0;row<6;row++)
                            {
                                set(1);
                                break;
                            }
                        }
                        else if(gridLocalTouchPos.x < columnSize.x*3)
                        {
                            for(row=0;row<6;row++)
                            {
                                set(2);
                                break;
                            }
                        }
                        else if(gridLocalTouchPos.x < columnSize.x*4)
                        {
                            for(row=0;row<6;row++)
                            {
                                set(3);
                                break;
                            }
                        }
                        else if(gridLocalTouchPos.x < columnSize.x*5)
                        {
                            for(row=0;row<6;row++)
                            {
                                set(4);
                                break;
                            }
                        }
                        else if(gridLocalTouchPos.x < columnSize.x*6)
                        {
                            for(row=0;row<6;row++)
                            {
                                set(5);
                                break;
                            }
                        }
                        else if(gridLocalTouchPos.x > columnSize.x*6)
                        {
                            for(row=0;row<6;row++)
                            {
                                set(6);
                                break;
                            }
                        }
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
    
    // Create a text from a class string
    sf::Text text(getDisplayText(),font);
    
    //set font size
    text.setCharacterSize(40);
    
    //Set style of text
    text.setStyle(sf::Text::Bold);
    
    //Set color of text
    text.setColor(sf::Color::White);
    

    //Set position of text
    text.setPosition(SCREEN_WIDTH-270,SCREEN_HEIGHT-500);
    
    // clear the window with black color
    window.clear(sf::Color::Black);
    
    
    //Draws retry button
    window.draw(_retrySprite);
    
    //Draws board
    window.draw(_gridSprite);
    
    //Draws text
    window.draw(text);
    
    
    //loop through rows
    for (int r=0; r<6; ++r)
    {
        //loop through columns
        for(int c=0; c<7; ++c)
        {
            //Draw all Pieces
            window.draw(getConfig()[r][c]);
        }
    }
    
    // end the current frame
    window.display();
    
}

