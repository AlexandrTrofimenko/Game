#include <game.hpp>
#include <menu.hpp>
#include <iostream>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
int main()
{
	int height = 600; int width = 900;
	sf::RenderWindow window(sf::VideoMode(width, height), "BirdIn");
	while (1)
	{
		if (!mn::menu(window))
			break;
		int score = 0;
		game::game(window, height, width, score);
		if (!mn::Remenu(window, score))
			break;
	}
	return 0;
}