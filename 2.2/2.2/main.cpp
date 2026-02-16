#include <iostream>
#include "Header.h"

int main()
{
	srand(time(NULL));

	char o;

	Player player1("", 10, 10, { "a","b" });
	Player player2("", 10, 5, { "a","c","d" });

	std::cout << "Enter oparation >> ";
	std::cin >> o;
	operations(o, player1, player2);

	////написать сеттер коорды + имя
	//player2.set_name("player2");

	//player2.set_x(10);
	//player2.set_y(-10);

	//player2.takeDamage(5);

	//player2.heal(20);

}

