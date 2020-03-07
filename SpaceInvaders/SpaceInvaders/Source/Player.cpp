#include <SFML/Graphics.hpp>
#include "../Include/Player.h"
#include "../Include/ScreenInfo.h"

// Set player position base heigth to 40
namespace
{
	constexpr float baseHeight = (float)Screen::height - 40.0f;
}

// Set initial player parameters
Player::Player()
{
	player.setSize(sf::Vector2f(30.0f, 30.0f));
	player.setOrigin(player.getSize().x / 2.0f, player.getSize().y / 2.0f);
	player.setPosition(Screen::width / 2, baseHeight);
	player.setFillColor(sf::Color::Green);
}

void Player::drawPlayer(sf::RenderWindow& window)
{
	window.draw(player);
}

void Player::getInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
	{
		playerVelocity.x -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerVelocity.x += speed;
	}
}

void Player::updatePlayer() 
{
	if (isAlive) 
	{
		auto halfWidth = player.getGlobalBounds().width / 2;
		player.move(playerVelocity);
		
		playerVelocity.x *= 0.90;
		if (player.getPosition().x - halfWidth <= 0) 
		{
			playerVelocity.x = 1.0f;
			player.setPosition(-1.0f + halfWidth, baseHeight);
		}
		else if (player.getPosition().x + halfWidth >= Screen::width) 
		{
			playerVelocity.x = -1.0f;
			player.setPosition(Screen::width + 1.0f - halfWidth, baseHeight);
		}
	}
}