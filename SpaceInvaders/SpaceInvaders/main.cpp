#include <SFML/Graphics.hpp>
#include <iostream>

#include "Include/ScreenInfo.h"
#include "Include/GameManager.h"
#include "Include/GUI.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(Screen::width, Screen::height), "Space Invaders");
	sf::Event event;

	GUI interface;
	GameManager game;
	

	window.setFramerateLimit(60);

	while (window.isOpen()) 
	{
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}
		/*while (game.won()) {
		}
		while (game.isGameLost()) {
		}*/
		window.clear(sf::Color::Black);
		//if()
		if (!game.isGameLost() && !game.won()) {
			game.draw(window);
			game.input();
			game.update();
		}
		else if (game.isGameLost()) {
			interface.drawGameOverScreen(window);
		}
		else if (game.won()) {
			interface.drawWinScreen(window);
		}

		window.display();
	}
}