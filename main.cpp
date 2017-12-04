//
//  main.cpp
//  
//
//  Created by KSUA on 11/15/17.
//

#include <stdio.h>
#include "connect4.hpp"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    Game("Connect 4!");
    
    
    
    //Old Game
//    //Game game = Game(6,7,"1");
//
//    //construct board
//    Board aBoard = Board();
//
//    //initilize index for column selection
//    int c;
//
//    //while connect 4 is not made, continue taking turns.
//    while(aBoard.getStatus() != true)
//    {
//        //prints board to console (which we'll stop using soon)
//        //aBoard.print_board(cout);
//
//
//        //Player 1 stuff
//
//        //construct first checker
//        Checker p1 = Checker('r');
//
//        //prompt user for checker input
//        cout << "Player 1 (red), select column 0-6" << endl;
//        cin >> c;
//
//        //set checker position
//        p1.setColumn(c);
//
//        //add piece to board, set row as lowest possible
//        aBoard.addPiece(p1);
//
//        //checker for connect 4
//        aBoard.check('r');
//
//
//        //if connect four after player one turn, end game
//        if(aBoard.getStatus() == true)
//        {
//            break;
//        }
//
//        //print board after turn is made
//        //aBoard.print_board(cout);
//
//
//        //////////////////////
//        //Follows in analogy//
//        //////////////////////
//        //Player 2 stuff
//        Checker p2 = Checker('y');
//        cout << "Player 2 (yellow), select column 0-6" << endl;
//        cin >> c;
//        p2.setColumn(c);
//        aBoard.addPiece(p2);
//        aBoard.check('y');
   // }
    
//    vector<vector<char>> v;
//    v.resize(6, std::vector<char>(7,'e'));
//   vector<vector<char>> a = populate(v);
//    print_board(cout, a);
//    check(a,'r');
//    check(a,'y');

}
