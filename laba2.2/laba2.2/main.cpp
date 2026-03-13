#include <iostream>
#include "Player.h"

int main()
{ 
	srand(time(NULL));

	Player player;
	Player player1("P1",10,10,{"a","b"});
	Player player2("P2", 10, 5, {"a","c","d"});

	player = player1 + player2;
	player.info();

	player = player1 - player2;
	player.info();

	player = player1 / player2;
	player.info();
}

