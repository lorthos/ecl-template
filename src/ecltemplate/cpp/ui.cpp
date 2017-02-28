#include "ui.h"

int ogl_w(std::stringstream *result_ss) {
    sf::RenderWindow window(sf::VideoMode(640,480,32),"Hello SFML");
    sf::Font font;

    font.loadFromFile("resources/OpenSans-Bold.ttf");

    sf::Text text((*result_ss).str(),font,11);
    text.setCharacterSize(32);
    text.setPosition(window.getSize().x/2 - text.getGlobalBounds().width/2,
                     window.getSize().y/2 - text.getGlobalBounds().height/2);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            window.clear(sf::Color::Black);
            window.draw(text);
            window.display();
        }
    }
    return 0;
}