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
    void addPiece(Checker & ch);
    vector<vector<sf::Sprite>> getConfig();
    void check(const Checker &ch);
    void draw_board();
    bool getStatus() const;
    //void setGrid(vconst vector<vector<sf::Sprite>> &board);
    void setConfig(const Checker &ch);
    void run(); //called when we start our game
private:
    vector<vector<sf::Sprite>> _gridPieces;
    bool _connect4;
};


#endif /* connect4_hpp */
