/* This is the main header file for our project */

#pragma once
#include <iostream>
#include <string>
#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Player.hpp"
#include "Level.hpp"
#include <random>
#include <time.h>

class Game {
public:
	Game() {}
	~Game() {}

	void runGame();

    void runMenu(sf::RenderWindow &window);

    void displayRules(sf::RenderWindow& window);

    void drawDiffCar(sf::RenderWindow& window, float *xPosition, float *yPosition, float speed, sf::Color color);

private:

};

void Game::drawDiffCar(sf::RenderWindow& window, float* xPosition, float* yPosition, float speed, sf::Color color) {
    sf::RectangleShape vehicleBody(sf::Vector2f(76, 46)); vehicleBody.setFillColor(color); vehicleBody.setOutlineColor(sf::Color::Black); vehicleBody.setOutlineThickness(2);
    sf::RectangleShape vehicleRoof(sf::Vector2f(56, 43)); vehicleRoof.setFillColor(sf::Color::Black);
    *xPosition += speed;
    vehicleBody.setPosition(*xPosition, *yPosition); window.draw(vehicleBody);
    vehicleRoof.setPosition(*xPosition + 10, *yPosition + 1); window.draw(vehicleRoof);
}

void Game::displayRules(sf::RenderWindow& window) {

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
                return;
			}
		}

        window.clear(sf::Color(100, 100, 100));

        sf::Font font;

        if (!font.loadFromFile("Assets/geo_1.ttf")) {
            return; // Exit the function if the font cannot be loaded
        }

        sf::Text rules; rules.setString("Rules"); rules.setFont(font); rules.setCharacterSize(150); rules.setPosition(180, 200); rules.setFillColor(sf::Color::Black); window.draw(rules);
      
        sf::Text rule1; rule1.setString("Player 1: Press W to increase speed"); rule1.setFont(font); rule1.setCharacterSize(40); rule1.setPosition(330, 390); rule1.setFillColor(sf::Color::Black); window.draw(rule1);

        sf::Text rule2; rule2.setString("Player 2: Press Up to increase speed"); rule2.setFont(font); rule2.setCharacterSize(40); rule2.setPosition(330, 440); rule2.setFillColor(sf::Color::Black); window.draw(rule2);

		sf::Text rule3; rule3.setString("First to reach the end of the track first to wins!"); rule3.setFont(font); rule3.setCharacterSize(40); rule3.setPosition(330, 490); rule3.setFillColor(sf::Color::Black); window.draw(rule3);

        sf::RectangleShape yellowLine(sf::Vector2f(15, 5));
        yellowLine.setFillColor(sf::Color::Yellow);
        yellowLine.setPosition(10, 350);
        for (int i = 0; i < 35; i++) {
            yellowLine.setPosition(0.0f + i * 45.0f, 350.0f);
            window.draw(yellowLine);
        }

        window.display();
	}

}

void Game::runGame() {
    sf::RenderWindow window(sf::VideoMode(1200, 700), "SFML Window");
    Player p1, p2;
    p1.setXPosition(50);
    p1.setYPosition(380);
    p2.setXPosition(50);
    p2.setYPosition(300);

    runMenu(window);

    while (window.isOpen()) {
        sf::Event event;


        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed: //window closed
                window.close();
                break;

            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Up) {
                    p2.increaseSpeed();
                    std::cout << "Up is pressed" << std::endl;
                }
                if (event.key.code == sf::Keyboard::W) {
                    p1.increaseSpeed();
                    std::cout << "W is pressed" << std::endl;
                }
            }
        }

        //game

        Level l1;
        l1.drawBackground(window);


        p1.drawPlayer(window);
        p2.drawPlayer(window);

        window.display();
    }
}

void Game::runMenu(sf::RenderWindow& window) {
    float xPosition1, yPosition1, xPosition2, yPosition2;
    xPosition1 = 0; xPosition2 = 0;
    yPosition1 = 170; yPosition2 = 500;

    sf::Clock clock;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 FPS, can change to whatever I want

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    std::cout << "Rules" << std::endl;
					displayRules(window);
                }
                if (event.key.code == sf::Keyboard::Num2) {
                    std::cout << "Play" << std::endl;
                    return;
                }
            }
        }

        sf::Time deltaTime = clock.restart();
        if (deltaTime < timePerFrame) {
            sf::sleep(timePerFrame - deltaTime);
        }

        window.clear(sf::Color(100, 100, 100));

        sf::Font font;
        if (!font.loadFromFile("Assets/geo_1.ttf")) {
            return; // Exit the function if the font cannot be loaded
        }

        sf::RectangleShape yellowLine(sf::Vector2f(15, 5));
        yellowLine.setFillColor(sf::Color::Yellow);
        yellowLine.setPosition(10, 350);
        for (int i = 0; i < 35; i++) {
            yellowLine.setPosition(0.0f + i * 45.0f, 350.0f);
            window.draw(yellowLine);
        }

        sf::Text menu;
        menu.setString("Drag Racers");
        menu.setFont(font);
        menu.setCharacterSize(150);
        menu.setPosition(180, 200);
        menu.setFillColor(sf::Color::Black);
        window.draw(menu);

        sf::Text option1; option1.setString("1) Rules"); option1.setFont(font); option1.setFillColor(sf::Color::Black); option1.setCharacterSize(40); option1.setPosition(350, 390); window.draw(option1);
        sf::Text option2; option2.setString("2) Play"); option2.setFont(font); option2.setFillColor(sf::Color::Black); option2.setCharacterSize(40); option2.setPosition(350, 440); window.draw(option2);

        float dt = timePerFrame.asSeconds(); //displaying the cars at whatever my monitors refresh rate is was way too much so I had to force an fps limit

        if (xPosition1 > 1200) { xPosition1 = -70; }
        if (xPosition2 < -70) { xPosition2 = 1270; }

        drawDiffCar(window, &xPosition1, &yPosition1, 150 * dt, sf::Color::Red);
        drawDiffCar(window, &xPosition2, &yPosition2, -250 * dt, sf::Color::Blue);

        window.display(); // Add this line to display the menu
    }
}