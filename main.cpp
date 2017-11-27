//
//  main.cpp
//  
//
//  Created by KSUA on 11/15/17.
//

#include <stdio.h>
#include "4_check.hpp"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    Board b = Board();
    while(b.getStatus() != true)
    {
        int c;
        b.print_board(cout);
        //Player 1 stuff
        Checker p1 = Checker('r');
        cout << "Player 1 (red), select column 0-6" << endl;
        cin >> c;
        p1.setColumn(c);
        b.addPiece(p1);
        b.check('r');
   
        if(b.getStatus() == true)
        {
            break;
        }
        
        b.print_board(cout);
        //Player 2 stuff
        Checker p2 = Checker('y');
        cout << "Player 2 (yellow), select column 0-6" << endl;
        cin >> c;
        p2.setColumn(c);
        b.addPiece(p2);
        b.check('y');
    }
    
//    vector<vector<char>> v;
//    v.resize(6, std::vector<char>(7,'e'));
//   vector<vector<char>> a = populate(v);
//    print_board(cout, a);
//    check(a,'r');
//    check(a,'y');

}
