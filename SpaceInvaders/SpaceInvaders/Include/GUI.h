#include <SFML/Graphics.hpp>

#include "../Include/ScreenInfo.h"
#include "../Include/ResourceManager.h"
/*
	End game basic graphical user interface
*/
class GUI
{
public:
	GUI();

	void drawScreen(sf::RenderWindow& window);

	void drawGameOverScreen(sf::RenderWindow& window);
	void drawWinScreen(sf::RenderWindow& window);

	sf::Font test;

	sf::Text gameOver;
	sf::Text win;
private:
	ResourceManager GUIResourceManager;
};
