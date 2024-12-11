/* This header file contains our Game class and important libraries which our other files referece */

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
#include <iomanip>
#include <cmath>

/* game class which contains functions that execute our game logic */
class Game {
public:
    Game() { winSeconds = 0; }
	~Game() {}

	void runGame();

    int playGame(sf::RenderWindow& window);

    void runMenu(sf::RenderWindow &window);

	void runWinScreen(sf::RenderWindow& window, int winner);

    void displayRules(sf::RenderWindow& window);

    void drawMenuCar(sf::RenderWindow& window, float *xPosition, float *yPosition, float speed, sf::Color color);

private:
    float winSeconds;
};

void Game::drawMenuCar(sf::RenderWindow& window, float* xPosition, float* yPosition, float speed, sf::Color color) { //draws an npc car for the menu screen
    sf::RectangleShape vehicleBody(sf::Vector2f(76, 46)); vehicleBody.setFillColor(color); vehicleBody.setOutlineColor(sf::Color::Black); vehicleBody.setOutlineThickness(2);
    sf::RectangleShape vehicleRoof(sf::Vector2f(56, 43)); vehicleRoof.setFillColor(sf::Color::Black);
    *xPosition += speed;
    vehicleBody.setPosition(*xPosition, *yPosition); window.draw(vehicleBody);
    vehicleRoof.setPosition(*xPosition + 10, *yPosition + 1); window.draw(vehicleRoof);
}

void Game::displayRules(sf::RenderWindow& window) { //displays the rules of the game at the beginning 

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

int Game::playGame(sf::RenderWindow& window) { //hands player keyboard inputs and game logic for when to end player control
    Player p1, p2;
    p1.setXPosition(50);
    p1.setYPosition(380);
    p2.setXPosition(50);
    p2.setYPosition(300);
    p1.setColor(sf::Color::Blue);
    p2.setColor(sf::Color::Red);

    Level l1;

    int i = 0; int* ip = &i;

    runMenu(window);

    sf::Time timer = sf::seconds(0);
    sf::Clock clock;

    while (window.isOpen()) {
        l1.drawBackground(window);

        sf::Color color;
        if (*ip < 20) { 
            color = sf::Color::Blue;
        }
        if (*ip >= 20) {
            color = sf::Color::Red;
        }
		if (*ip == 40) {
			*ip = 0;
		}
        *ip += 1;
        sf::Font font; font.loadFromFile("Assets/geo_1.ttf");
        sf::Text mash; mash.setCharacterSize(70); mash.setFont(font); mash.setFillColor(color); mash.setPosition(500, 300); mash.setString("MASH!");
        window.draw(mash);

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

		if (p1.getXPosition() > 1190) {
            winSeconds = timer.asSeconds();
            return 1;
		}
        if (p2.getXPosition() > 1190) {
            winSeconds = timer.asSeconds();
            return 2;
        }

        timer += clock.restart();

        p1.drawPlayer(window);
        p2.drawPlayer(window);

        window.display();
    }
    return 0;
}

void Game::runMenu(sf::RenderWindow& window) { //runs the menu screen for the game
    float xPosition1, yPosition1, xPosition2, yPosition2;
    xPosition1 = 0; xPosition2 = 0;
    yPosition1 = 170; yPosition2 = 500;

 //   sf::Clock clock;
 //   sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 FPS, can change later if needed                                                                                      _       _
	//sf::Time deltaTime = clock.restart(); //looked up how to fix too many position updates (refresh rate of my monitor was too high for it) and I found out what delta time is   \(^_^)/
   /* if (deltaTime < timePerFrame) {
        sf::sleep(timePerFrame - deltaTime);
    }*/

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

        if (xPosition1 > 1200) { xPosition1 = -70; }
        if (xPosition2 < -70) { xPosition2 = 1270; }

        drawMenuCar(window, &xPosition1, &yPosition1, 2, sf::Color::Red);
        drawMenuCar(window, &xPosition2, &yPosition2, -5, sf::Color::Blue);

        window.display();
    }
}

void Game::runGame() { //encapsulates the Game member functions and uses them to run the entire game and window
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Drag Racers", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    while (window.isOpen())  {
        
        int win = 0;

        win = playGame(window);

		if (win == 1) {
			std::cout << "Player 1 wins in:" << std::endl;
            runWinScreen(window, 1);
		}
		if (win == 2) {
			std::cout << "Player 2 wins in:" << std::endl;
            runWinScreen(window, 2);
		}
    }
}

void Game::runWinScreen(sf::RenderWindow& window, int winner) { //after a "win" this function accepts a player winner (int) and displays a win screen with a timer

    sf::Time timer = sf::seconds(0);
    sf::Clock clock;

    while (window.isOpen() && timer < sf::seconds(5)) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (timer.asSeconds() > 3 && event.type == sf::Event::KeyPressed) {
                return;
            }
        }

        window.clear(sf::Color(100, 100, 100));
        sf::Font font;
        if (!font.loadFromFile("Assets/geo_1.ttf")) {
            return; // Exit the function if the font cannot be loaded
        }

        sf::Text winText;
        winText.setString(""); winText.setFont(font); winText.setCharacterSize(140); winText.setPosition(50, 220); winText.setFillColor(sf::Color::Black);
        if (winner == 1) {
            winText.setFillColor(sf::Color::Blue); winText.setString("Player 1 Wins In:");
        }
        if (winner == 2) {
            winText.setFillColor(sf::Color::Red); winText.setString("Player 2 Wins In:");
        }
        window.draw(winText);


        sf::Text winTextTime;
        std::string winTimeSeconds = std::to_string(winSeconds);
        winTextTime.setString(winTimeSeconds); winTextTime.setFont(font); winTextTime.setCharacterSize(90); winTextTime.setPosition(150, 500);
        if (winner == 1) { winTextTime.setFillColor(sf::Color::Blue); }
        if (winner == 2) { winTextTime.setFillColor(sf::Color::Red); }
        window.draw(winTextTime);

        sf::Text in; in.setString(" Seconds!"); in.setFont(font); in.setCharacterSize(90); in.setPosition(150 + winTextTime.getLocalBounds().width, 500);
        if (winner == 1) { in.setFillColor(sf::Color::Blue); }
        if (winner == 2) { in.setFillColor(sf::Color::Red); }
        window.draw(in);

        timer += clock.restart();

        window.display();
    }
}