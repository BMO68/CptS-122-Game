#pragma once
#include "../Headers/Game.hpp"
#include <iostream>
#include <SFML/Window.hpp>

class Vehicle {
public:
	Vehicle() {
		speed = 0;
		color = sf::Color::White;
		xPosition = 0;
		yPosition = 0;
	}
	Vehicle(sf::Color newColor, float newSpeed, float newXPosition, float newYPosition) {
		color = newColor;
		speed = newSpeed;
		xPosition = newXPosition;
		yPosition = newYPosition;
	}
	~Vehicle() { }

	void increaseSpeed() {
		setSpeed(speed += speed + 0.1);
	}

	float getSpeed() {
		return speed;
	}

	void setSpeed(float newSpeed) {
		speed = newSpeed;
	}


	sf::Color getColor() {
		return color;
	}

	void setColor(sf::Color newColor) {
		color = newColor;
	}

	float getXPosition() {
		return xPosition;
	}

	float getYPosition() {
		return yPosition;
	}

	void setXPosition(float newX) {
		xPosition = newX;
	}

	void setYPosition(float newY) {
		yPosition = newY;
	}

private:
	sf::Color color;
	float speed;
	float xPosition;
	float yPosition;
};