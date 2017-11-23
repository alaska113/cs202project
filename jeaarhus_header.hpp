
//	jeaarhus_header.hpp
//  Created by Jonathan Aarhus
//	on 11/21/2017

#ifndef jeaarhus_header_hpp
#define jeaarhus_header_hpp

//this is the generic player class
class Player {
public:
	//this is the constructor for players
	Player();

	//this is the virtual destructor for players.
	virtual ~Player();

	//this is the virtual coppy constructor for player
	virtual Player(const Palyer& PlyerToCoppy) = 0;

	//this is the virtual assignment operator for the player classes.
	virtual Player& operator=(Player& rhs)=0;

	//this is the virtual function for executing the players turn.
	virtual void turn()=0;

	//this is the comparison operator for players.
	friend bool operator==(const Player& lhs, const Player& rhs);
};

//this is the class for the current player.
class CurrentPlayer : public Player{};

//this is the first player class
class Player1 : public Player{};

//this is the second player class
class player2 : public Player{};

//this is the board class
class Board{
public:
	//this if the default constructor for board
	Board();

	//this is the destructor for board
	~Board();

	//this is the coppy constructor for board
	Board(const Board& BoardToCoppy);

	//this is the assignment operator for board
	Board& operator=(Board& rhs)
};

//this is the clip base class
class Chip {
	//constructor for chip
	Chip();

	//virtual destructor for chip
	virtual ~Chip();

	//virtual copy constructor for chip
	virtual Chip(const Chip& ChipToCoppy) = 0;

	//virtual assignment operator for chip
	virtual Chip& operator=(Chip& rhs)=0;
};

//this is the currently selected chip
class SelectedChip : public Chip{};

//this is the chip representing an empty slot
class NullChip{} : public Chip;

//this is the red chip class
class RedChip {} : public Chip;

//this is the black chip class
class BlackChip{} : public Chip;


#endif


