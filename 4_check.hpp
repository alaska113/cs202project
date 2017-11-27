//
//  4_check.hpp
//  
//
//  Created by KSUA on 11/15/17.
//

#ifndef __check_hpp
#define __check_hpp

#include <iostream>
#include <vector>
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


vector<vector<char>> populate(vector<vector<char>> v);


#endif
/* __check_hpp */

