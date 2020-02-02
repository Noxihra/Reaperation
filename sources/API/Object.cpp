/*
** EPITECH PROJECT, 2019
** Object
** File description:
** Every base object
*/

#include <future>
#include <unistd.h>
#include <iostream>
#include <iterator>
#include <list>
#include <functional>
#include "API/Object.hpp"
#include "API/Scene.hpp"
#include "defaultValues.hpp"

Object::Object(sf::Texture &texture, \
               sf::Rect<float> &hitbox /* = sfFloatRect0DefaultValue */, \
               float speedX /* = 0 */, float speedY /* = 0 */, \
               float scaleX /* = 1 */, float scaleY /* = 1 */, \
               float posX /* = 0 */, float posY /* = 0 */, \
               float angle /* = 0 */, sf::Int32 longevity /* = 0 */, \
               sf::Rect<int> &textureRect /* = sfIntRect0DefaultValue */)
    : _textureRect(textureRect), _hitbox(hitbox), _longevity(longevity)
    , _speed(speedX, speedY), _scale(scaleX, scaleY), _angle(angle)
{
    static sf::Int32 id = 0;
    _id = id++;

    this->setTexture(texture);
    _sprite.setScale(_scale);
    _sprite.setRotation(_angle);
    _sprite.setPosition(posX, posY);
    // _hitbox.left -= _hitbox.height / 2;
    // _hitbox.top -= _hitbox.width / 2;
}

const sf::Sprite &Object::getSprite() const
{
    return _sprite;
}

const sf::Rect<int> &Object::getTextureRect() const
{
    return _textureRect;
}

const sf::Rect<float> &Object::getHitbox() const
{
    return _hitbox;
}

const sf::Clock &Object::getClock() const
{
    return _clock;
}

sf::Int32 Object::getClockElapsed() const
{
    return _clock.getElapsedTime().asMilliseconds();
}

sf::Int32 Object::getLongevity() const
{
    return _longevity;
}

const sf::Vector2<float> &Object::getSpeed() const
{
    return _speed;
}

const sf::Vector2<float> Object::getHitboxPosition() const
{
    return sf::Vector2<float>(_hitbox.left, _hitbox.top);
}

const sf::Vector2<float> Object::getHitboxSize() const
{
    return sf::Vector2<float>(_hitbox.width, _hitbox.height);
}

const sf::Vector2<float> &Object::getScale() const
{
    return _scale;
}

float Object::getAngle() const
{
    return _angle;
}

bool Object::getDebug() const
{
    return _isDebugging;
}


void Object::setGrounded(bool newState)
{
    _isGrounded = newState;
}

void Object::setSprite(sf::Sprite &sprite)
{
    _sprite = sprite;

    if (_textureRect != sfIntRect0DefaultValue) {
        _sprite.setTextureRect(_textureRect);
    }
    _sprite.setScale(_scale);
    _sprite.setRotation(_angle);
}

void Object::setSpriteCenter()
{
    auto spriteLocalBounds = _sprite.getLocalBounds();

    _sprite.setOrigin(spriteLocalBounds.width / 2, spriteLocalBounds.height / 2);
}

void Object::setTexture(sf::Texture &texture)
{
    _sprite.setTexture(texture);
    if (_textureRect != sfIntRect0DefaultValue) {
        _sprite.setTextureRect(_textureRect);
    }
}

void Object::setTextureRect(sf::Rect<int> &textureRect)
{
    _sprite.setTextureRect(_textureRect);
    _textureRect = textureRect;
}

void Object::setHitbox(sf::Rect<float> &hitbox)
{
    _hitbox = hitbox;
}

/*void Object::setHitboxRect(sf::RectangleShape &hitboxRect)
{
    _hitboxRect = hitboxRect;
}*/

void Object::setClock(sf::Clock &clock)
{
    _clock = clock;
}

void Object::setLongevity(sf::Int32 longevity)
{
    _longevity = longevity;
}

void Object::setSpeed(sf::Vector2<float> &speed)
{
    _speed = speed;
}

void Object::setSpeed(float speedX, float speedY)
{
    _speed = sf::Vector2<float>(speedX, speedY);
}

void Object::setScale(sf::Vector2<float> &scale)
{
    _scale = scale;
    _sprite.setScale(_scale);
}

void Object::setScale(float scaleX, float scaleY)
{
    _scale = sf::Vector2<float>(scaleX, scaleY);
    _sprite.setScale(_scale);
}

void Object::setAngle(float angle)
{
    _angle = angle;
    _sprite.setRotation(_angle);
}

void Object::setPosition(sf::Vector2f position)
{
    _sprite.setPosition(position);
}

void Object::addSpeed(float x, float y)
{
    _speed.x += x;
    _speed.y += y;
}

void Object::move()
{
    if (_speed != sfVector2f0DefaultValue) {
        _sprite.move(_speed);
        _hitbox.left += _speed.x;
        _hitbox.top += _speed.y;
    }
}

bool Object::jump()
{
    if (_speed.y != 0) {
        return (false);
    }
    addSpeed(0, -20);
    return (true);
}
