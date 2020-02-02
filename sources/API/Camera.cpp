/*
** EPITECH PROJECT, 2020
** JAM_sfml_2019
** File description:
** Camera
*/

#include "API/Camera.hpp"
#include "include/Config.hpp"

Camera::Camera(sf::RenderWindow &window)
    : _vecView(0, 0), _speedView(0, 0)
{
    sf::Vector2f vecf(window.getSize());
    _view.setSize(vecf);
    vecf.x /= 2;
    _view.setCenter(vecf);
}

Camera::~Camera()
{
}

// -------------------------------------------------------- View
void Camera::followingPlayerView(Object *player, sf::RenderWindow &window)
{
    sf::Rect<int> rectHitbox(player->getTextureRect());
    sf::Rect<float> hitboxPlayer(player->getHitbox());
    sf::Sprite playerSprite = player->getSprite();
    sf::Vector2<float> spritePos = playerSprite.getPosition();
    spritePos.x += hitboxPlayer.width  / 2 + _vecView.x;
    spritePos.y += hitboxPlayer.height / 2 + _vecView.y;
#ifndef DEBUG
    if (spritePos.x < -MIDDLEX + rectHitbox.width)
        spritePos.x = -MIDDLEX + rectHitbox.width;
    if (spritePos.x > MIDDLEX - rectHitbox.width)
        spritePos.x = MIDDLEX - rectHitbox.width;
    if (spritePos.y < -MIDDLEY + rectHitbox.height)
        spritePos.y = -MIDDLEY + rectHitbox.height;
    if (spritePos.y > MIDDLEY - rectHitbox.height)
        spritePos.y = MIDDLEY - rectHitbox.height;
#endif // DEBUG
    _view.setCenter(spritePos);
    moveView(spritePos);
    progressiveResetViewToPlayer();
    window.setView(_view);
}

void Camera::progressiveResetViewToPlayer()
{
    if (_isMoving) { // No reset while in move (can have bug)
        if (_vecView.x == 0 && _speedView.x) { // Secure reset x
            setSpeedView(0, _speedView.y);
        }
        if (_vecView.y == 0 && _speedView.y) { // Secure reset y
            setSpeedView( _speedView.x, 0);
        }
        if (_vecView.x < 0 && -250 <= _speedView.x + _vecView.x) { // Left
            _vecView.x += _speedView.x;
            if (_vecView.x >= 0) {
                setSpeedView(0, _speedView.y);
                _vecView.x = 0;
            }
        } else if (_vecView.x > 0  && _speedView.x + _vecView.x <= 250) { // Right
            _vecView.x += _speedView.x;
            if (_vecView.x <= 0) {
                setSpeedView(0, _speedView.y);
                _vecView.x = 0;
            }
        }
        if (_vecView.y < 0  && -250 <= _speedView.y + _vecView.y) { // Up [2]
            _vecView.y += _speedView.y;
            if (_vecView.y >= 0) {
                setSpeedView(_speedView.x, 0);
                _vecView.y = 0;
            }
        } else if (_vecView.y > 0  && _speedView.y + _vecView.y <= 50) { // Down [3]
            _vecView.y += _speedView.y;
            if (_vecView.y <= 0) {
                setSpeedView(_speedView.x, 0);
                _vecView.y = 0;
            }
        }
    }
}

void Camera::moveView(sf::Vector2f &playerPos [[ gnu::unused ]])
{
#ifndef DEBUG
    if (-250 <= _speedView.x + _vecView.x && _speedView.x + _vecView.x <= 250)
#endif // DEBUG
        _vecView.x += _speedView.x;
#ifndef DEBUG
    if (-250 <= _speedView.y + _vecView.y && _speedView.y + _vecView.y <= 50)
#endif // DEBUG
        _vecView.y += _speedView.y;
#ifndef DEBUG
    if (playerPos.x > -MIDDLEX && playerPos.x < MIDDLEX)
#endif // DEBUG
        _view.move(_speedView.x, 0);
#ifndef DEBUG
    if (playerPos.y > -MIDDLEY && playerPos.y < MIDDLEY)
#endif // DEBUG
        _view.move(0, _speedView.y);
}

void Camera::setSpeedView(float speedX, float speedY)
{
    _speedView = sf::Vector2<float> (speedX, speedY);
}

void Camera::setMoving(bool isMoving)
{
    _isMoving = isMoving;
}

void Camera::setZoom(float zoom)
{
    _view.zoom(zoom);
}

const sf::Vector2<float> &Camera::getVecView()
{
    return (_vecView);
}
