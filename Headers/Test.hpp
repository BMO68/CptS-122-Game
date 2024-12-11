#pragma once
#include "Game.hpp"
#include "Player.hpp"

class Test {
public:
	Test() {}
	~Test() {}

    void TestTest(); //lol

    int testMenu(sf::RenderWindow &window);

    int testWinScreen(sf::RenderWindow &window);

    int testCar(sf::RenderWindow &window);

    int testRules(sf::RenderWindow &window);

    int testDrawMenuCar(sf::RenderWindow &window, float* xPosition, float* yPosition, float speed, sf::Color color);
};

void Test::TestTest() {
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Drag Racers TEST", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
    int choice = 0;
    for (;;) {
        std::cout << "TEST Menu Guide: " << std::endl;
        std::cout << "1) TEST MENU && MENUCARS" << std::endl;
        std::cout << "2) TEST WINSCREEN" << std::endl;
        std::cout << "3) TEST CAR" << std::endl;
        std::cout << "4) TEST RULES" << std::endl;
        std::cout << "5) TESTTEST EXIT" << std::endl;

        std::cin >> choice;
        
        switch (choice) {
		    case 1:
			    testMenu(window);
			    break;
			case 2:
				testWinScreen(window);
				break;
			case 3:
				testCar(window);
                break;
            case 4:
                testRules(window);
                break;
            case 5: 
                window.close();
                return;
                break;
			default:
                break;
        }
    }
}

int Test::testMenu(sf::RenderWindow &window) {
    float xPosition1, yPosition1, xPosition2, yPosition2;
    xPosition1 = 0; xPosition2 = 0;
    yPosition1 = 170; yPosition2 = 500;

    //sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 FPS, can change later if needed                                                                                      _       _
    //sf::Time deltaTime = clock.restart(); //looked up how to fix too many position updates (refresh rate of my monitor was too high for it) and I found out what delta time is   \(^_^)/
    //nvm sfml has a framerate limiter

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Tilde) {
    
                    return 0;
                }
            }
        }

        window.clear(sf::Color(100, 100, 100));

        sf::Font font;
        if (!font.loadFromFile("Assets/geo_1.ttf")) {
            return 1; // Exit the function if the font cannot be loaded
        }

        sf::RectangleShape yellowLine(sf::Vector2f(15, 5));
        yellowLine.setFillColor(sf::Color::Yellow);
        yellowLine.setPosition(10, 350);
        for (int i = 0; i < 35; i++) {
            yellowLine.setPosition(0.0f + i * 45.0f, 350.0f);
            window.draw(yellowLine);
        }

        sf::Text menu;
        menu.setString("TEST Drag Racers");
        menu.setFont(font);
        menu.setCharacterSize(150);
        menu.setPosition(180, 200);
        menu.setFillColor(sf::Color::Black);
        window.draw(menu);

        sf::Text option1; option1.setString("TEST 1) Rules"); option1.setFont(font); option1.setFillColor(sf::Color::Black); option1.setCharacterSize(40); option1.setPosition(350, 390); window.draw(option1);
        sf::Text option2; option2.setString("TEST 2) Play"); option2.setFont(font); option2.setFillColor(sf::Color::Black); option2.setCharacterSize(40); option2.setPosition(350, 440); window.draw(option2);

        if (xPosition1 > 1200) { xPosition1 = -70; }
        if (xPosition2 < -70) { xPosition2 = 1270; }

        testDrawMenuCar(window, &xPosition1, &yPosition1, 2, sf::Color::Red);
        testDrawMenuCar(window, &xPosition2, &yPosition2, -4, sf::Color::Blue);

        window.display();
    }
    return 0;
}

int Test::testWinScreen(sf::RenderWindow &window) {

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Tilde) { //test escape key
                    return 1;
                }
            }
        }
        window.clear(sf::Color(100, 100, 100));

        sf::Font font;
        if (!font.loadFromFile("Assets/geo_1.ttf")) {
            return 1; // Exit the function if the font cannot be loaded
        }

        sf::Text winText;
        winText.setString(""); winText.setFont(font); winText.setCharacterSize(140); winText.setPosition(50, 220); winText.setFillColor(sf::Color::Black);
        winText.setFillColor(sf::Color::Blue); winText.setString("Player # Wins In:");
        window.draw(winText);


        sf::Text winTextTime;
        std::string winTimeSeconds = "#####";
        winTextTime.setString(winTimeSeconds); winTextTime.setFont(font); winTextTime.setCharacterSize(90); winTextTime.setPosition(150, 500);
        window.draw(winTextTime);

        sf::Text in; in.setString(" Seconds!"); in.setFont(font); in.setCharacterSize(90); in.setPosition(150 + winTextTime.getLocalBounds().width, 500);
        window.draw(in);

        window.display();
    }
    return 0;
}

int Test::testCar(sf::RenderWindow &window) {

    Player p1;
    sf::Event event;
    while (window.isOpen()) {
  
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Tilde) { //test escape key
                    return 0;
                }
                if (event.key.code == sf::Keyboard::Up) {
                    p1.increaseSpeed();
                    std::cout << "TEST Up is pressed" << std::endl;
                }
            }

            window.clear(sf::Color(100, 100, 100));

           p1.drawPlayer(window);
        
           window.display();
       
        }
    }
    
    return 0;
}

int Test::testRules(sf::RenderWindow &window) {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				return 0;
			}
		}
		window.clear(sf::Color(100, 100, 100));
		sf::Font font;
		if (!font.loadFromFile("Assets/geo_1.ttf")) {
			return 1; // Exit the function if the font cannot be loaded
		}
		sf::Text rules; rules.setString("TEST Rules"); rules.setFont(font); rules.setCharacterSize(150); rules.setPosition(180, 200); rules.setFillColor(sf::Color::Black); window.draw(rules);
		sf::Text rule1; rule1.setString("TEST Player 1: Press W to increase speed"); rule1.setFont(font); rule1.setCharacterSize(40); rule1.setPosition(330, 390); rule1.setFillColor(sf::Color::Black); window.draw(rule1);
		sf::Text rule2; rule2.setString("TEST Player 2: Press Up to increase speed"); rule2.setFont(font); rule2.setCharacterSize(40); rule2.setPosition(330, 440); rule2.setFillColor(sf::Color::Black); window.draw(rule2);
		sf::Text rule3; rule3.setString("TEST First to reach the end of the track first to wins!"); rule3.setFont(font); rule3.setCharacterSize(40); rule3.setPosition(330, 490); rule3.setFillColor(sf::Color::Black); window.draw(rule3);
		
        sf::RectangleShape yellowLine(sf::Vector2f(15, 5));
		yellowLine.setFillColor(sf::Color::Yellow);
		yellowLine.setPosition(10, 350);
		for (int i = 0; i < 35; i++) {
			yellowLine.setPosition(0.0f + i * 45.0f, 350.0f);
			window.draw(yellowLine);
		}
		
        window.display();
	}
	return 0;

}

int Test::testDrawMenuCar(sf::RenderWindow &window, float* xPosition, float* yPosition, float speed, sf::Color color) {
    sf::RectangleShape vehicleBody(sf::Vector2f(76, 46)); vehicleBody.setFillColor(color); vehicleBody.setOutlineColor(sf::Color::Black); vehicleBody.setOutlineThickness(2);
    sf::RectangleShape vehicleRoof(sf::Vector2f(56, 43)); vehicleRoof.setFillColor(sf::Color::Black);
    *xPosition += speed;
    vehicleBody.setPosition(*xPosition, *yPosition); window.draw(vehicleBody);
    vehicleRoof.setPosition(*xPosition + 10, *yPosition + 1); window.draw(vehicleRoof);
    return 0;
}