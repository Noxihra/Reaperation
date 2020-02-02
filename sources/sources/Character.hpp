/*
** EPITECH PROJECT, 2019
** Character
** File description:
** Every character
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "API/Object.hpp"

class Character : public Object {
public:
    Character(sf::Texture &textureIdle, sf::Texture &textureTurn, \
              sf::Texture &textureWalk, sf::Texture &textureRun, \
              sf::Texture &textureJump, sf::Texture &textureFall, \
              sf::Texture &textureDie, \
              sf::Rect<float> &hitbox = sfFloatRect0DefaultValue, \
              float speedX = 0, float speedY = 0, float scaleX = 1, \
              float scaleY = 1, float posX = 0, float posY = 0, float angle = 0, \
              sf::Rect<int> &textureRect = sfIntRect0DefaultValue);
    ~Character() = default;

    enum Direction {
        None = 0,
        Left,
        Right
    };

    void idle(Direction direction);
    void turn(Direction direction);
    void walk(Direction direction);
    void run(Direction direction);
    void jump();
    void fall(Direction direction);

    // Return bool to wait die animation
    bool anime(bool isDie = false);

    bool dieAnim();

private:
    sf::Texture &_textureIdle;
    sf::Texture &_textureTurn;
    sf::Texture &_textureWalk;
    sf::Texture &_textureRun;
    sf::Texture &_textureJump;
    sf::Texture &_textureFall;
    sf::Texture &_textureDie;

    bool _isLeftPressed;
    bool _isRightPressed;
    Direction _currentDirection;
};

#endif // CHARACTER_HPP
