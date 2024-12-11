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
		drawVehicle(window);
	}
private:

};