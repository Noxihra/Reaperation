/*
** EPITECH PROJECT, 2019
** Character
** File description:
** Every character
*/

#include "Character.hpp"
#include "Config.hpp"
#include <iostream>

Character::Character(sf::Texture &textureIdle, sf::Texture &textureTurn, \
                     sf::Texture &textureWalk, sf::Texture &textureRun, \
                     sf::Texture &textureJump, sf::Texture &textureFall, \
                     sf::Texture &textureDie, \
                     sf::Rect<float> &hitbox, float speedX, float speedY, \
                     float scaleX, float scaleY, float posX, float posY, \
                     float angle, sf::Rect<int> &textureRect)
    : Object(textureIdle, hitbox, speedX, speedY, scaleX, scaleY, posX, posY, \
             angle, 0, textureRect)
    , _textureIdle(textureIdle)
    , _textureTurn(textureTurn)
    , _textureWalk(textureWalk)
    , _textureRun(textureRun)
    , _textureJump(textureJump)
    , _textureFall(textureFall)
    , _textureDie(textureDie)
    , _isLeftPressed(false)
    , _isRightPressed(false)
    , _currentDirection(Right)
{
    this->setSpriteCenter();
}

void Character::idle(Direction direction, Scene &scene)
{
    if (direction == Left) {
        _isLeftPressed = false;
        if (_isRightPressed) {
            run(Right, scene);
        } else {
            this->setTexture(_textureIdle);
            this->setSpeed(0, _speed.y);
        }
    } else if (direction == Right) {
        _isRightPressed = false;
        if (_isLeftPressed) {
            run(Left, scene);
        } else {
            this->setTexture(_textureIdle);
            this->setSpeed(0, _speed.y);
        }
    }
}

void Character::turn(Direction direction, Scene &scene)
{
    scene.addFnLooper(FnLooper(sf::seconds(.12), FnLooper::EveryMillisecond,
                               []{}, [&]{ this->setTexture(_textureIdle); }));

    this->setTexture(_textureTurn);
    this->setScale(-_scale.x, _scale.y);
    _currentDirection = direction;

}

void Character::walk(Direction direction [[gnu::unused]], Scene &scene [[gnu::unused]])
{
}

void Character::run(Direction direction, Scene &scene)
{
    if (direction == Left) {
        if (_currentDirection != direction) {
            this->turn(direction, scene);
        } else {
            this->setTexture(_textureRun);
        }
        _isLeftPressed = true;
        this->setSpeed(-5, _speed.y);
    } else if (direction == Right) {
        if (_currentDirection != direction) {
            this->turn(direction, scene);
        } else {
            this->setTexture(_textureRun);
        }
        _isRightPressed = true;
        this->setSpeed(5, _speed.y);
    }
}

void Character::jump()
{
    if (_speed.y == 0) {
        this->addSpeed(0, -15);
    }
}

void Character::fall(Direction direction [[gnu::unused]], Scene &scene [[gnu::unused]])
{
}

bool Character::anime(bool isDie)
{
    const sf::Vector2<unsigned> spriteSize = _sprite.getTexture()->getSize();

    _textureRect.top += _textureRect.height;
    if (isDie && _textureRect.top >= (int)spriteSize.y)
        return (true);
    if (_textureRect.top >= (int)spriteSize.y) {
        _textureRect.left = 0;
        _textureRect.top = 0;
    }
    _sprite.setTextureRect(_textureRect);
    return (false);
}

bool Character::dieAnim()
{
    static int dieOnce = 0;

    if (!dieOnce) {
        this->setTexture(_textureDie);
        _isLeftPressed = false;
        _isRightPressed = false;
        _textureRect.left = 0;
        _textureRect.top = 0;
    }
    dieOnce++;
    //std::cout << dieOnce << "**\n";
    //if ((dieOnce % (20 * FPS * FPS)) == 1)
    //    return (this->anime(true));
    return (false);
}
