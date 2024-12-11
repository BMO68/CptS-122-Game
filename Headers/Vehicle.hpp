#pragma once
#include "../Headers/Game.hpp"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

class Vehicle {
public:
	Vehicle() {
		speed = 0;
		color = sf::Color::White;
		xPosition = 0;
		yPosition = 0;
	}
	Vehicle(sf::Color newColor, float newSpeed, float newXPosition, float newYPosition, float newWidth, float newHeight) {
		color = newColor;
		speed = newSpeed;
		xPosition = newXPosition;
		yPosition = newYPosition;
	}
	~Vehicle() { }

	void increaseSpeed() {
		setSpeed(speed += speed + 0.000001); //0.000001
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

	void drawVehicle(sf::RenderWindow& window) {
		sf::RectangleShape vehicleBody(sf::Vector2f(56, 26)); vehicleBody.setFillColor(color); vehicleBody.setOutlineColor(sf::Color::Black); vehicleBody.setOutlineThickness(2); 
		sf::RectangleShape vehicleRoof(sf::Vector2f(36, 24)); vehicleRoof.setFillColor(sf::Color::Black);   
		xPosition += speed;
		vehicleBody.setPosition(xPosition, yPosition); window.draw(vehicleBody);
		vehicleRoof.setPosition(xPosition + 10, yPosition + 1); window.draw(vehicleRoof);
	}

private:

	sf::Color color;
	float speed;
	float xPosition;
	float yPosition;
};