#ifndef ECL_TEMPLATE_ENGINE_H
#define ECL_TEMPLATE_ENGINE_H

#include <SFML/Graphics.hpp>
#include "Bob.h"

using namespace sf;

class Engine
{
private:

    // A regular RenderWindow
    RenderWindow m_Window;

    // Declare a sprite and a Texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;

    // An instance of Bob
    Bob m_Bob;

    // Private functions for internal use only
    void input();
    void update(float dtAsSeconds);
    void draw();

public:
    // The Engine constructor
    Engine();

    // start will call all the private functions
    void start();

};

#endif //ECL_TEMPLATE_ENGINE_H
