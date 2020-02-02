/*
** EPITECH PROJECT, 2019
** Menu
** File description:
** Menu scene
*/

#include "Flow/Menu.hpp"

Menu::Menu(sf::RenderWindow &window, Object &background, sf::Music &music, \
           Object &startButton, Object &exitButton)
    : Scene(window, background, music) \
    , _startButton(startButton), _exitButton(exitButton)
{
    sf::Rect<float> tmp(0, 0, 1920, 1080);
    sf::View _camera(tmp);
    _window.setView(_camera);
    this->addObject(startButton);
    this->addObject(exitButton);
}

void Menu::keyPressed()
{}

void Menu::keyReleased()
{}

void Menu::mouseButtonPressed()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition());
        if (_startButton.getHitbox().contains(position)) {
            _isOver = true;
        } else if (_exitButton.getHitbox().contains(position)) {
            _window.close();
        }
    }
}

void Menu::mouseButtonReleased()
{
    if (_event.mouseButton.button == sf::Mouse::Left) {
    } else if (_event.mouseButton.button == sf::Mouse::Right) {
    }
}

void Menu::mouseMoved()
{
    sf::Vector2i position [[ gnu::unused ]] = sf::Mouse::getPosition();
}

void Menu::processPerSecond()
{}

void Menu::processPerDecisecond()
{}

void Menu::processPerCentisecond()
{}

void Menu::processPerMillisecond()
{}

void Menu::processPerFrame()
{}
