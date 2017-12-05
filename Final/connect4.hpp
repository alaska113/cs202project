//
//  connect4.hpp
//  cs202working
//
//  Created by KSUA on 11/27/17.
//  Copyright © 2017 Khan Howe. All rights reserved.
//

#ifndef connect4_hpp
#define connect4_hpp
#include <stdio.h>
#define SCREEN_WIDTH 1300
#define SCREEN_HEIGHT 700
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
using std::vector;
using std::ostream;
using std::cout;

class Checker
{
public:
    Checker(int turn_n);
    int getRow() const;
    int getColumn() const;
    char getColorChar() const;
    void setRow(int r);
    void setColumn(int c);
    void setColorChar(char color);
private:
    char _color;
    int _row;
    int _column;
};
class Game
{
public:
    //char setTurn();
    
    void print_char_board();
    
    void set(int col);
    
    void retry();

    //sets the on screen text to tell who's turn it is
    void turn_name(int turn_n);
    
    //Game constructor
    Game(std::string title);
    
    //Sets textures for sprites
    void setTextures();
    
    //Sets the on screen text given a string
    void setDisplayText(const std::string & txt);
    
    //turn increment (not really needed)
    void incrementTurn();
    
    //Gets the current turn
    int getTurn() const;
    
    //Draws sprites to current window
    void draw_board(sf::RenderWindow & window);
    
    //Adds piece to the board, drops to lowest possible row
    void addPiece(Checker & ch);
    
    //
    sf::Text windowText();
    
    //Accessor of 2D vector of sprites
    vector<vector<sf::Sprite>> getConfig();
    
    //Check function that looks for a connect four of the current color
    //returns true if connect four is found
    void check(const Checker &ch);
    
    //Accessor of connect four status (might not be needed)
    bool getStatus() const;
    
    void setStatus(bool s);

    
    //Gets the onscreen text
    std::string getDisplayText() const;
    //void setGrid(const vector<vector<sf::Sprite>> &board);
    
    //Mutator that sets the 2D vector of sprites
    void setConfig(const Checker &ch);
    
    //Game start
    void run(); //called when we start our game
    
    //will change soon
    bool turn();
    
    //initializes a clock
    sf::Clock _clock;
    
    //initializes window
    sf::RenderWindow window;
    
private:
    //2D vector of sprites
    vector<vector<sf::Sprite>> _gridPieces;
    
    //Retry button sprite
    sf::Sprite _retrySprite;
    
    //Board sprite
    sf::Sprite _gridSprite;
    
    //turn number
    int _turn_n;
    
    //onscreen text
    std::string _displayText;
    
    bool _connect4;
   
};


#endif /* connect4_hpp */
