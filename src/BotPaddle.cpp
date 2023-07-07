#include "../include/BotPaddle.h"

void BotPaddle::initPaddleProperties()
{
    m_paddleMoveSpeed = 7;
    m_paddleDirectionY = 0.f;
}

BotPaddle::BotPaddle(float startX, float startY)
{
    this->initPaddleProperties();

    m_position.x = startX;
    m_position.y = startY;

    m_paddleShape.setSize(sf::Vector2f(15.f, 150.f));
    m_paddleShape.setFillColor(sf::Color::White);
    m_paddleShape.setOrigin(m_paddleShape.getSize().x / 2, m_paddleShape.getSize().y /2);
    m_paddleShape.setPosition(m_position);

    m_originPoint.setSize(sf::Vector2f(10,10));
    m_originPoint.setFillColor(sf::Color::Red);
    m_originPoint.setPosition(m_paddleShape.getOrigin());
    m_originPoint.setOrigin(m_originPoint.getSize().x /2, m_originPoint.getSize().y /2);

}

sf::FloatRect BotPaddle::getPosition()
{
    return m_paddleShape.getGlobalBounds();
}

sf::RectangleShape BotPaddle::getShape()
{
    return m_paddleShape;
}

void BotPaddle::update(float deltaTime, float ballYVelocity, sf::Vector2f ballPosition)
{
    m_position.y = ballPosition.y;
    m_paddleShape.setPosition(m_position);

    m_originPoint.setPosition(m_paddleShape.getPosition());

}

void BotPaddle::render(sf::RenderTarget &target)
{
    target.draw(m_paddleShape);
    target.draw(m_originPoint);
}
