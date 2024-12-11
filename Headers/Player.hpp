/* this file contains class Player: a derived class of vehicle (since a player is a diver of a vehicle) */
#pragma once
#include "Vehicle.hpp"
#include "Game.hpp"

class Player : public Vehicle {
public:
	Player() {

	}
	~Player() {

	}

	void pickColor(sf::Color newColor) { //picks the color of the player's vehicle (did not implement);
		setColor(newColor);
	}

	void drawPlayer(sf::RenderWindow& window) { //accepts an sfml window stream and draws the player's vehicle to the window
		drawVehicle(window);
	}
private:

};