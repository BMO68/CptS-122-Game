#pragma once
#include "Vehicle.hpp"
#include "Game.hpp"

class Player : public Vehicle {
public:
	Player() {

	}
	~Player() {

	}

	void pickColor(sf::Color newColor) {
		setColor(newColor);
	}

	void drawPlayer(sf::RenderWindow& window) {
		sf::RectangleShape player(sf::Vector2f(50, 50));
		player.setFillColor(getColor());
		player.setPosition(100, 100);
		window.draw(player);
	}

private:

};