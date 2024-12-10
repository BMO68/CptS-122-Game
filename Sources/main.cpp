#include "../Headers/Game.hpp"
#include "../Headers/Background.hpp"

int main() {
 
    sf::RenderWindow window(sf::VideoMode(1200, 700), "SFML Window");

    
    // Main loop
    while (window.isOpen()) {
        Window bg;
        bg.drawBackground(window);


        
        
        window.display();
    }

    return 0;

}