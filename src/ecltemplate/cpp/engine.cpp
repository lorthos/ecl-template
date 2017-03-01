#include "Engine.h"

Engine::Engine() {
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x, resolution.y), "Simple Game Engine", Style::Fullscreen);

    m_BackgroundTexture.loadFromFile("resources/background.png");

    // Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

}

void Engine::start() {
    Clock clock;

    while (m_Window.isOpen()) {
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();

        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}