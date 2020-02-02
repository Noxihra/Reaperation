/*
** EPITECH PROJECT, 2019
** Menu
** File description:
** Menu scene
*/

#include "Flow/Menu.hpp"

Menu::Menu(sf::RenderWindow &window, Object &background, sf::Music &music, \
         Object &startButton, Object &exitButton, Object &creditButton, Object &credit, Object &exitButtonCredit)
    : Scene(window, background, music)
    , _startButton(startButton), _exitButton(exitButton), _creditButton(creditButton), _credit(credit), _exitButtonCredit(exitButtonCredit)
{
    sf::Rect<float> tmp(0, 0, 1920, 1080);
    sf::View _camera(tmp);
    _window.setView(_camera);
    this->addObject(startButton);
    this->addObject(exitButton);
    this->addObject(creditButton);
    this->addObject(exitButtonCredit);
}

void Menu::keyPressed()
{}

void Menu::keyReleased()
{}

void Menu::mouseButtonPressed()
{
    static Object &background_save = _background;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition());
        if (_startButton.getHitbox().contains(position)) {
            _isOver = true;
        } else if (_exitButton.getHitbox().contains(position)) {
            _window.close();
        } else if (_creditButton.getHitbox().contains(position)) {
            _background = _credit;
        } else if (_exitButtonCredit.getHitbox().contains(position)) {
            _background = background_save;
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
