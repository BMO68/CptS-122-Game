/* this file contains the class Vehicle: base class for player (since each car is controlled by a player) */
#pragma once
#include "../Headers/Game.hpp"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

class Vehicle {
public:
	Vehicle() { //contructor
		speed = 0;
		color = sf::Color::White;
		xPosition = 0;
		yPosition = 0;
	}
	Vehicle(sf::Color newColor, float newSpeed, float newXPosition, float newYPosition, float newWidth, float newHeight) { //overloaded constructor
		color = newColor;
		speed = newSpeed;
		xPosition = newXPosition;
		yPosition = newYPosition;
	}
	~Vehicle() { } //destructor

	void increaseSpeed() { //increases "speed" of the vehicle
		setSpeed(speed + 0.2); //0.000001
	}

	float getSpeed() { //gets the "speed" of the vehicle
		return speed;
	}

	void setSpeed(float newSpeed) { //sets the "speed" of the vehicle
		speed = newSpeed;
	}

	sf::Color getColor() { //gets the color of the vehicle in sfml format
		return color;
	}

	void setColor(sf::Color newColor) { //seth the color of the vehicle in sfml format
		color = newColor;
	}

	float getXPosition() { //gets the x position of the vehicle
		return xPosition;
	}

	float getYPosition() { //gets the y position of the vehicle
		return yPosition;
	}

	void setXPosition(float newX) { //sets the x position of the vehicle
		xPosition = newX;
	}	

	void setYPosition(float newY) { //sets the y position of the vehicle
		yPosition = newY;
	}

	void drawVehicle(sf::RenderWindow& window) { //accepts an sfml window stream and draws the vehicle which a player controls
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