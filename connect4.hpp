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
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1024
#include <iostream>
#include <vector>
#include <stdio.h>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "InputManager.hpp"
using std::vector;
using std::ostream;
using std::cout;
#include <stdio.h>

class Checker
{
public:
    Checker(char color);
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
    Game(std::string title);
    void setTextures();
    void setDisplayText(const std::string & txt);
    void incrementTurn();
    int getTurn() const;
    void draw_board(sf::RenderWindow & window);
    void addPiece(Checker & ch);
    sf::Text windowText();
    vector<vector<sf::Sprite>> getConfig();
    bool check(const Checker &ch);
    bool getStatus() const;
    std::string getDisplayText() const;
    //void setGrid(const vector<vector<sf::Sprite>> &board);
    void setConfig(const Checker &ch);
    void run(); //called when we start our game
    bool turn();
    sf::RenderWindow window;
    InputManager input;
private:
    vector<vector<sf::Sprite>> _gridPieces;
    sf::Sprite _retrySprite;
    sf::Sprite _gridSprite;
    int _turn_n;
    std::string _displayText;
   
};


#endif /* connect4_hpp */
