#include <iostream>
#include "Header.h"

int main()
{
	//констр по умолч
	Player player1;
	player1.info();

	Player player2("name1", 10, 5, 10, "running");
	player2.info();

	//написать сеттер коорды + имя
	player2.set_name("player2");

	player2.set_x(10);
	player2.set_y(-10);

	player2.takeDamage(5);

	player2.heal(20);
	
	player2.short_info();

	//констр копирования
	Player player3 = player2;
	player3.short_info();
}