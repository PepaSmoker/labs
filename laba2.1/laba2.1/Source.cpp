#include <iostream>
#include "Header.h"

int main()
{
	Player player1("Sanya", 10, 5, 10, "running");
	player1.info();

	
	player1.takeDamage(5);
	player1.info();

	player1.heal(20);
	player1.info();

	Player player2 = player1;
	player2.info();
}