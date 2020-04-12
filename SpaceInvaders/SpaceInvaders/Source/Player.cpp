#include "../Include/Player.h"

// Set initial player parameters
Player::Player() : Collidable(playerWidth, playerHeight)
{
	player.setSize(sf::Vector2f(playerWidth, playerHeight));
	//player.setOrigin(player.getSize().x / 2.0f, player.getSize().y / 2.0f);
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
		playerVelocity.x -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		playerVelocity.x += speed;
	}
}

void Player::updatePlayer() 
{
	if (isPlayerAlive) {
		auto halfWidth = player.getGlobalBounds().width;
		player.move(playerVelocity);
		
		playerVelocity.x *= 0.90; // Decrease velocity so player won't move forever
		if (player.getPosition().x <= 0) {
			playerVelocity.x = 1.0f;
			player.setPosition(-1.0f, baseHeight);
		}
		else if (player.getPosition().x + halfWidth >= Screen::width) {
			playerVelocity.x = -1.0f;
			player.setPosition(Screen::width + 1.0f - halfWidth, baseHeight);
		}

	}
}

void Player::onCollision(Collidable& object)
{
	isPlayerAlive = false;
}

void Player::revivePlayer()
{
	isPlayerAlive = true;
	player.setPosition(Screen::width / 2, baseHeight);

}

bool Player::isAlive()
{
	return isPlayerAlive;
}


const sf::Vector2f& Player::getSpritePosition()
{
	return player.getPosition();
}
