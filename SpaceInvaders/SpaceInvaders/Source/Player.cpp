#include "../Include/Player.h"
#include <iostream>	// DEBUING PURPOSES ! DELETE LATER !

// Set initial player parameters
Player::Player() : Collidable(playerWidth, playerHeight)
{
	player.setSize(sf::Vector2f(playerWidth, playerHeight));
	player.setOrigin(player.getSize().x / 2.0f, player.getSize().y / 2.0f);
	player.setPosition(Screen::width / 2, baseHeight);
	player.setFillColor(sf::Color::Green);
}

void Player::drawPlayer(sf::RenderWindow& window)
{
	window.draw(player);
}

void Player::getMoveInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		std::cout << "LEFT" << std::endl; // DEBUING PURPOSES ! DELETE LATER !
		playerVelocity.x -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		std::cout << "RIGHT" << std::endl; // DEBUING PURPOSES ! DELETE LATER !
		playerVelocity.x += speed;
	}
}

void Player::updatePlayer() 
{
	if (isPlayerAlive) {
		auto halfWidth = player.getGlobalBounds().width / 2;
		player.move(playerVelocity);
		
		playerVelocity.x *= 0.90; // Decrease velocity so player won't move forever
		if (player.getPosition().x - halfWidth <= 0) {
			playerVelocity.x = 1.0f;
			player.setPosition(-1.0f + halfWidth, baseHeight);
		}
		else if (player.getPosition().x + halfWidth >= Screen::width) {
			playerVelocity.x = -1.0f;
			player.setPosition(Screen::width + 1.0f - halfWidth, baseHeight);
		}
	}
}

void Player::onCollision(Collidable& object)
{
}

const sf::Vector2f& Player::getSpritePosition()
{
	return player.getPosition();
}
