#include "../Include/GUI.h"

GUI::GUI()
{
	gameOver.setFont(GUIResourceManager.loadFont("unifont"));
	gameOver.setString("GAME OVER");
	gameOver.setCharacterSize(80);
	gameOver.setOrigin(gameOver.getLocalBounds().left + gameOver.getLocalBounds().width / 2.0f,
		gameOver.getLocalBounds().top + gameOver.getLocalBounds().height / 2.0f);
	gameOver.setPosition((float)Screen::width / 2.0f,(float)Screen::height / 2.0f);
	gameOver.setFillColor(sf::Color::White);

	win.setFont(GUIResourceManager.loadFont("unifont"));
	win.setString("YOU WON!");
	win.setCharacterSize(80);
	win.setOrigin(win.getLocalBounds().left + win.getLocalBounds().width / 2.0f,
		win.getLocalBounds().top + win.getLocalBounds().height / 2.0f);
	win.setPosition((float)Screen::height / 2.0f, (float)Screen::width / 2.0f);
	win.setFillColor(sf::Color::White);
}

void GUI::drawScreen(sf::RenderWindow& window)
{
}

void GUI::drawGameOverScreen(sf::RenderWindow& window)
{
	window.draw(gameOver);
}

void GUI::drawWinScreen(sf::RenderWindow& window)
{
	window.draw(win);
}
