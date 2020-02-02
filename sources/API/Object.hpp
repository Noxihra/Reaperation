/*
** EPITECH PROJECT, 2020
** getHitboxPosition
** File description:
** Object
*/

/*
** EPITECH PROJECT, 2019
** Object
** File description:
** Every base object
*/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include "defaultValues.hpp"

class Scene;

class Object {
public:
    Object(sf::Texture &texture, sf::Rect<float> &hitbox = sfFloatRect0DefaultValue, \
           float speedX = 0, float speedY = 0, float scaleX = 1, float scaleY = 1, \
           float posX = 0, float posY = 0, float angle = 0, sf::Int32 longevity = 0, \
           sf::Rect<int> &textureRect = sfIntRect0DefaultValue);
    virtual ~Object() = default;

    const sf::Sprite &getSprite() const;
    const sf::Rect<int> &getTextureRect() const;
    const sf::Rect<float> &getHitbox() const;
    const sf::RectangleShape &getHitboxRect() const;
    const sf::Clock &getClock() const;
    sf::Int32 getClockElapsed() const;
    sf::Int32 getLongevity() const;
    const sf::Vector2<float> &getSpeed() const;
    const sf::Vector2<float> getHitboxPosition() const;
    const sf::Vector2<float> getHitboxSize() const;
    const sf::Vector2<float> &getScale() const;
    float getAngle() const;
    bool getDebug() const;

    void setSprite(sf::Sprite &sprite);
    void setSpriteCenter();
    void setTexture(sf::Texture &texture);
    void setTextureRect(sf::Rect<int> &textureRect);
    void setHitbox(sf::Rect<float> &hitbox);
    void setHitboxRect(sf::RectangleShape &hitboxRect);
    void setClock(sf::Clock &clock);
    void setLongevity(sf::Int32 longevity);
    void setSpeed(sf::Vector2<float> &speed);
    void setSpeed(float speedX, float speedY);
    void setScale(sf::Vector2<float> &scale);
    void setScale(float scaleX, float scaleY);
    void setAngle(float angle);
    void setGrounded(bool newState);

    void addSpeed(float x, float y);
    void move();

    bool jump();

protected:
    sf::Sprite _sprite;
    sf::Rect<int> _textureRect;

    sf::Rect<float> _hitbox;
    //sf::RectangleShape _hitboxRect;

    sf::Clock _clock;
    sf::Int32 _longevity;

    sf::Vector2<float> _speed;
    sf::Vector2<float> _scale;
    float _angle;

    sf::Int32 _id;

    bool _isGrounded;
    bool _isDebugging;
};

#endif // OBJECT_HPP
