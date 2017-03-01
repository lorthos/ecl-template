#include "bob.h"
 
Bob::Bob()
{
    // movement speed
    m_Speed = 400;

    m_Texture.loadFromFile("resources/bob.png");
    m_Sprite.setTexture(m_Texture);     
 
    // starting pos
    m_Position.x = 500;
    m_Position.y = 800;
 
}
 
// Make the private spite available to the draw() function
Sprite Bob::getSprite()
{
    return m_Sprite;
}
 
void Bob::moveLeft()
{
    m_LeftPressed = true;
}
 
void Bob::moveRight()
{
    m_RightPressed = true;
}
 
void Bob::stopLeft()
{
    m_LeftPressed = false;
}
 
void Bob::stopRight()
{
    m_RightPressed = false;
}
 
// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Bob::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }
 
    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }
 
    // Now move the sprite to its new position
    m_Sprite.setPosition(m_Position);   
 
}