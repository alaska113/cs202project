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
    char getColor() const;
    void setRow(int r);
    void setColumn(int c);
    void setColor(char color);
private:
    char _color;
    int _row;
    int _column;
};
class Board
{
public:
    Board();
    void clearBoard();
    void addPiece(Checker & ch);
    vector<vector<char>> getConfig();
    void check(char color);
    ostream & print_board(ostream & os);
    bool getStatus() const;
    void setConfig(int r, int c, char color);
    
private:
    vector<vector<char>> _config;
    bool _connect4;
};


class Game
{
public:
    Game(int width, int height, std::string title);
private:
    void run(); //called when we start our game
};


#endif /* connect4_hpp */
