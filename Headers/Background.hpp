#include <SFML/Graphics.hpp>

class Window {
public:
    Window() {}
    ~Window() {}

    void drawBackground(sf::RenderWindow &window) {
        window.clear(sf::Color(36, 255, 36));

        sf::RectangleShape road(sf::Vector2f(1200, 200));
        road.setFillColor(sf::Color(50, 50, 50));
        road.setPosition(0, 250);
        window.draw(road);

        sf::RectangleShape yellowLine(sf::Vector2f(15, 5));
        yellowLine.setFillColor(sf::Color::Yellow);
        yellowLine.setPosition(10, 350);
        for (int i = 0; i < 35; i++) {
            yellowLine.setPosition(0 + i * 45, 350);
            window.draw(yellowLine);
        }

        drawHouse(50, 500, window);

        drawPond(600, 100, window);

        drawTree(580, 100, window);
        drawTree(100, 20, window);
        drawTree(800, 500, window);

        drawEnd(window);
    }

    void drawTree(float x, float y, sf::RenderWindow &window) {
        sf::CircleShape treeTop(30);
        sf::Color forestGreen(34, 139, 34);
        treeTop.setFillColor(forestGreen);
        treeTop.setPosition(x, y);
        window.draw(treeTop);
    }

    void drawPond(float x, float y, sf::RenderWindow &window) {
        sf::CircleShape pond(60);
        pond.setFillColor(sf::Color::Blue);
        pond.setPosition(x, y);
        window.draw(pond);
    }

    void drawHouse(float x, float y, sf::RenderWindow& window) {
        sf::RectangleShape house(sf::Vector2f(120, 120));
        sf::RectangleShape driveway(sf::Vector2f(30, 50));
        driveway.setFillColor(sf::Color(50, 50, 50));
        house.setFillColor(sf::Color(250, 20, 20));
        house.setPosition(x, y);
        window.draw(house);
        driveway.setPosition(x + 45, y - 50);
        window.draw(driveway);
    }

    void drawEnd(sf::RenderWindow& window) {
        sf::RectangleShape whiteSquare(sf::Vector2f(20, 20));
        whiteSquare.setFillColor(sf::Color::White);
        sf::RectangleShape blackSquare(sf::Vector2f(20, 20));
        blackSquare.setFillColor(sf::Color::Black);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 10; j++) {
                if ((i + j) % 2 == 0) {
                    whiteSquare.setPosition(1150 + i * 20, 250 + j * 20);
                    window.draw(whiteSquare);
                } else {
                    blackSquare.setPosition(1150 + i * 20, 250 + j * 20);
                    window.draw(blackSquare);
                }
            }
        }
    }

    void drawText(std::string& text, float x, float y,int charSize, sf::Color color, sf::RenderWindow& window) {
        sf::Font font;
        if (!font.loadFromFile("Assets/OPTITimes-Roman.otf")) {
            // Handle error
        }
        sf::Text sfText;
        sfText.setFont(font);
        sfText.setString(text);
        sfText.setCharacterSize(charSize);
        sfText.setFillColor(color);
        sfText.setPosition(x, y);
        window.draw(sfText);
    }

private:

};