#include <SFML/Graphics.hpp>
#include "Include/ScreenInfo.h"
#include "Include/GameManager.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(Screen::width, Screen::height), "Space Invaders");
	sf::Event event;
	Player playerOne;
	EnemyControler enemy;
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
		window.clear(sf::Color::White);

		/*playerOne.drawPlayer(window);*/
		/*playerOne.getMoveInput();
		game.getPlayerShootInput();*/
		game.draw(window);
		game.input();
		game.update();
		/*playerOne.updatePlayer();
		enemy.drawEnemies(window);
		enemy.moveEnemies();*/

		window.display();
	}
}