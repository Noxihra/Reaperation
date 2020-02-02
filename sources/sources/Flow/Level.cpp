/*
** EPITECH PROJECT, 2019
** Level
** File description:
** every level of the game
*/

#include <iostream>
#include "Flow/Level.hpp"
#include "API/Object.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Character.hpp"

Level::Level(sf::RenderWindow &window, Object &background, sf::Music &music)
    : Scene(window, background, music)
{}

void Level::keyPressed()
{
    switch (_event.key.code) {

// -------------------------------------------------------- Movement
    case sf::Keyboard::D:
        if (!_isDie) {
            _player->run(Character::Direction::Right, *this);
            _camera.setSpeedView((!!_camera.getVecView().x) * 5 *(1 - 2 * (_camera.getVecView().x > 0)), (!!_camera.getVecView().y) * 5 *(1 - 2 * (_camera.getVecView().y > 0)));
            _camera.setMoving(true);
        }
        break;
    case sf::Keyboard::Q:
        if (!_isDie) {
            _player->run(Character::Direction::Left, *this);
            _camera.setSpeedView((!!_camera.getVecView().x) * 5 *(1 - 2 * (_camera.getVecView().x > 0)), (!!_camera.getVecView().y) * 5 *(1 - 2 * (_camera.getVecView().y > 0)));
            _camera.setMoving(true) ;
        }
        break;
    case sf::Keyboard::Space: _player->jump(); break;

// -------------------------------------------------------- View
    case sf::Keyboard::Left: _camera.setSpeedView(-5, 0); break;
    case sf::Keyboard::Right: _camera.setSpeedView(5, 0); break;
    case sf::Keyboard::Up: _camera.setSpeedView(0, -5); break;
    case sf::Keyboard::Down: _camera.setSpeedView(0, 5); break;
    case sf::Keyboard::P: _isDie = true; break;
    }
    if (_isDie) {
        _player->setSpeed(0, 0);
    }
}

void Level::keyReleased()
{
    switch (_event.key.code) {

// -------------------------------------------------------- Movement
    case sf::Keyboard::D: if (!_isDie) {_player->idle(Character::Direction::Right, *this); _camera.setSpeedView(0, 0); _camera.setMoving(false);} break;
    case sf::Keyboard::Q: if (!_isDie) {_player->idle(Character::Direction::Left, *this); _camera.setSpeedView(0, 0); _camera.setMoving(false);} break;

// -------------------------------------------------------- View
    case sf::Keyboard::Left:
    case sf::Keyboard::Right:
    case sf::Keyboard::Up: // fallthrough
    case sf::Keyboard::Down: _camera.setSpeedView(0, 0); break;

// -------------------------------------------------------- Debug
#ifdef DEBUG
    case sf::Keyboard::Add: _camera.setZoom(0.8); break;
    case sf::Keyboard::Subtract: _camera.setZoom(1.2); break;
#endif
    }
    if (_isDie) {
        _player->setSpeed(0, 0);
    }
}

void Level::mouseButtonPressed()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i position [[ gnu::unused ]] = sf::Mouse::getPosition();
    } else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        sf::Vector2i position [[ gnu::unused ]] = sf::Mouse::getPosition();
    }
}

void Level::mouseButtonReleased()
{
    if (_event.mouseButton.button == sf::Mouse::Left) {
    } else if (_event.mouseButton.button == sf::Mouse::Right) {
    }
}

void Level::mouseMoved()
{
    sf::Vector2i position [[ gnu::unused ]] = sf::Mouse::getPosition();
}

void Level::processPerSecond()
{}

void Level::processPerDecisecond()
{

}

void Level::processPerCentisecond()
{
    _camera.followingPlayerView(_player, _window);
    applyGravity(*_player);
    applyHorizontalColiding(*_player);
    if (_player) {
        _player->move();
    }
}

void Level::processPerMillisecond()
{}

void Level::processPerFrame()
{}
