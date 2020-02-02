/*
** EPITECH PROJECT, 2019
** Scene
** File description:
** A scene is basicly an environement of a game level
*/

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Text.hpp>
#include "API/Scene.hpp"
#include "API/Object.hpp"
#include "Character.hpp"
#include "Macro.hpp"
#include "Object.hpp" // Maybe not opti

Scene::Scene(sf::RenderWindow &window, Object &background, sf::Music &music)
    : _player(nullptr), _background(background), _window(window), _isOver(false), _camera(_window), _music(music)
{
    _music.play();
    processPer();
}

Scene::~Scene()
{}

// ------------------------------------------------------------------ Every process

bool Scene::process()
{
    processEvents();
    processPer();
    processDisplay();
    if ((_isDie || _isLevelCleared) && checkPersoStatus())
        return (true);
    return (false);
}

// -------------------------------------------------------- Event
void Scene::processEvents()
{
    while (_window.pollEvent(_event)) {
        switch (_event.type) {
        case sf::Event::Closed: _window.close(); break;
        case sf::Event::KeyPressed: keyPressed(); break;
        case sf::Event::KeyReleased: keyReleased(); break;
        case sf::Event::MouseButtonPressed: mouseButtonPressed(); break;
        case sf::Event::MouseButtonReleased: mouseButtonReleased(); break;
        case sf::Event::MouseMoved: mouseMoved(); break;
        }
    }
}

// -------------------------------------------------------- Display
void Scene::processDisplay()
{
    static sf::Clock clockDisplay;
    static sf::Clock clockFPS;
    static uint_fast16_t fps = 0;

    if (clockFPS.getElapsedTime().asMilliseconds() >= 1000) {
        clockFPS.restart();
        // std::cout << "fps: " << fps << std::endl;
        fps = 0;
    }
    if (clockDisplay.getElapsedTime().asMilliseconds() >= (1000 / FPS)) {
        clockDisplay.restart();
        fps++;
        _window.clear();
        _window.draw(_background.getSprite());
        for (auto it : _listBackGround) {
            _window.draw(it.getSprite());
        }
        for (auto it : _listEternalObjects) {
            _window.draw(it.getSprite());
        }
        for (auto it : _listEternalObjects) {
            _window.draw(it.getSprite());
        }
        for (auto it : _listTemporaryObjects) {
            _window.draw(it.getSprite());
        }
        for (auto it : _listEternalTextBox) {
            _window.draw(it.getBox());
            _window.draw(it.getText());
        }
        for (auto it : _listTemporaryTextBox) {
            _window.draw(it.getBox());
            _window.draw(it.getText());
        }
        if (_player) {
            _window.draw(_player->getSprite());
        }
        for (auto it : _listForeGround) {
            _window.draw(it.getSprite());
        }
        processDisplayHitbox();
        _window.display();
        processPerFrame();
    }
}

void Scene::processDisplayHitbox()
{
#ifdef DEBUG
    for (auto it : _listEternalObjects) {
        sf::RectangleShape tmprectangle;
        tmprectangle.setSize(sf::Vector2f(it.getHitboxSize().x, it.getHitboxSize().y));
        tmprectangle.setPosition(sf::Vector2f((it.getHitboxPosition().x), (it.getHitboxPosition().y)));
        tmprectangle.setOutlineThickness(2);
        tmprectangle.setOutlineColor(sf::Color::Red);
        tmprectangle.setFillColor(sf::Color::Transparent);
        _window.draw(tmprectangle);
    }
    if (_player) {
        sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(_player->getHitboxSize().x, _player->getHitboxSize().y));
        rectangle.setPosition(sf::Vector2f((_player->getHitboxPosition().x), (_player->getHitboxPosition().y)));
        rectangle.setOutlineThickness(2);
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setFillColor(sf::Color::Transparent);
        _window.draw(rectangle);
    }
#endif
}

// -------------------------------------------------------- Per
static void callFnLoops(std::list<FnLooper> &list)
{
    for (auto it = list.begin(); it != list.end(); it++) {
        if (it->isOver()) {
            it = list.erase(it);
        } else {
            (*it)();
        }
    }
}

void Scene::processPer()
{
    static sf::Clock clockPerSecond;
    static sf::Clock clockPerDecisecond;
    static sf::Clock clockPerCentisecond;
    static sf::Clock clockPerMillisecond;

    if (clockPerSecond.getElapsedTime().asMilliseconds() >= 1000) {
        callFnLoops(_listFnEverySecond);
        processPerSecond();
        clockPerSecond.restart();
    }
    if (clockPerDecisecond.getElapsedTime().asMilliseconds() >= 100) {
        callFnLoops(_listFnEveryDecisecond);
        if (_player && _player->anime(_isDie))
            _isLevelCleared = true;
        clockPerDecisecond.restart();
    }
    if (clockPerCentisecond.getElapsedTime().asMilliseconds() >= 10) {
        callFnLoops(_listFnEveryCentisecond);
        for (auto it = _listTemporaryObjects.begin(); it != _listTemporaryObjects.end(); it++) {
            if (it->getLongevity() <= it->getClockElapsed()) {
                it = _listTemporaryObjects.erase(it);
            }
        }
        for (auto &it : _listTemporaryObjects) {
            it.move();
        }
        for (auto &it : _listEternalObjects) {
            it.move();
        }
        processPerCentisecond();
        clockPerCentisecond.restart();
    }
    if (clockPerMillisecond.getElapsedTime().asMilliseconds() >= 1) {
        callFnLoops(_listFnEveryMillisecond);
        processPerSecond();
        clockPerMillisecond.restart();
    }
}

// -------------------------------------------------------- Others
bool Scene::isOver() const
{
    if (!_window.isOpen()) {
        return true;
    }
    return _isOver;
}

sf::RenderWindow &Scene::getWindow()
{
    return _window;
}

void Scene::closeWindow()
{
    _window.close();
}

// -------------------------------------------------------- Text
void Scene::addText(TextBox &textBox)
{
    if (!textBox.getLongevity()) {
        _listEternalTextBox.push_back(textBox);
    } else {
        _listTemporaryTextBox.push_back(textBox);
    }
}
// -------------------------------------------------------- Object
void Scene::addObject(Object &object)
{
    if (!object.getLongevity()) {
        _listEternalObjects.push_back(object);
    } else {
        _listTemporaryObjects.push_back(object);
    }
}

sf::Rect<int> Scene::getBackgroundRect() const
{
    return _background.getSprite().getTextureRect();
}

void Scene::setBackground(Object &background)
{
    _background = background;
}

// -------------------------------------------------------- FnLooper
void Scene::addFnLooper(FnLooper &fn)
{
    switch (fn.getFrequency()) {
    case FnLooper::EverySecond : _listFnEverySecond.push_back(fn); break;
    case FnLooper::EveryDecisecond : _listFnEveryDecisecond.push_back(fn); break;
    case FnLooper::EveryCentisecond : _listFnEveryCentisecond.push_back(fn); break;
    case FnLooper::EveryMillisecond : _listFnEveryMillisecond.push_back(fn); break;
    }
}

void Scene::setPlayer(Character *player)
{
    _player = player;
}

// -------------------------------------------------------- View
void Scene::followingPlayerView()
{}

//--------------------------------------------------------- Gravity & coliding
bool isColliding(const Object &a, const Object &b)
{
    if ((a.getHitboxPosition().x + a.getSpeed().x) <= (b.getHitboxPosition().x + b.getHitboxSize().x + b.getSpeed().x) && \
        (a.getHitboxPosition().x + a.getHitboxSize().x + a.getSpeed().x) >= (b.getHitboxPosition().x + b.getSpeed().x) && \
        (a.getHitboxPosition().y + a.getSpeed().y) <= (b.getHitboxPosition().y + b.getHitboxSize().y + b.getSpeed().y) && \
        (a.getHitboxPosition().y + a.getHitboxSize().y + a.getSpeed().y) >= (b.getHitboxPosition().y + b.getSpeed().y)) {
        return true;
    } else {
        return false;
    }
}

void Scene::applyGravity(Object &obj)
{
    obj.addSpeed(0, 0.5001);
    for (auto obj2 : _listEternalObjects) {
        if (isColliding(obj, obj2)) {
            obj.setSpeed(obj.getSpeed().x, 0);
            break;
        }
    }
}

void Scene::applyHorizontalColiding(Object &obj)
{
    for (auto obj2 : _listEternalObjects) {
        if (isColliding(obj, obj2)) {
            obj.setSpeed(0, obj.getSpeed().y);
            break;
        }
    }
}

// ---------------------------------------------------- Win / Loose conditions
bool Scene::checkPersoStatus()
{
    if (_player && _isDie) {
        //_isLevelCleared = ();
        _player->dieAnim();
        return (_isLevelCleared);
    } else if (_isLevelCleared) {

    }
    return false;
}
