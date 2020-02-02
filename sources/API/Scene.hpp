/*
** EPITECH PROJECT, 2019
** Scene
** File description:
** A scene is basicly an environement of a game level
*/

#ifndef VISUAL_HPP
#define VISUAL_HPP

#include <list>
#include <functional>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Audio/Music.hpp>
#include "Config.hpp"
#include "Utils/TextBox.hpp"
#include "Utils/FnLooper.hpp"
#include "API/Camera.hpp"

namespace sf {
    class RenderWindow;
    class Sprite;
    class Text;
}
class Object;
class Character;

class Scene {
public:
    Scene(sf::RenderWindow &window, Object &background, sf::Music &music);
    virtual ~Scene();

    // -------------------------------------------------------------- Every process
    bool process();

    // ---------------------------------------------------- Event
    void processEvents();

    virtual void keyPressed() = 0;
    virtual void keyReleased() = 0;
    virtual void mouseButtonPressed() = 0;
    virtual void mouseButtonReleased() = 0;
    virtual void mouseMoved() = 0;

    // ---------------------------------------------------- Display
    void processDisplay();
    void processDisplayHitbox();

    // ---------------------------------------------------- Per
    void processPer(); // calls every process per..

    virtual void processPerSecond() = 0;
    virtual void processPerDecisecond() = 0;
    virtual void processPerCentisecond() = 0;
    virtual void processPerMillisecond() = 0;
    virtual void processPerFrame() = 0;

    // -------------------------------------------------------------- Other
    bool isOver() const; // does _window.isOpen()

    // ---------------------------------------------------- Window
    sf::RenderWindow &getWindow();
    void closeWindow();

    // ---------------------------------------------------- Text
    void addText(TextBox &object);

    // ---------------------------------------------------- Object
    // void addObject(std::reference_wrapper<Object> object);
    void addObject(Object &object);
    void setBackground(Object &background);
    sf::Rect<int> getBackgroundRect() const;
    void addLayerBackground(Object &background);
    void setPlayer(Character *player);

    // ---------------------------------------------------- FnLooper
    void addFnLooper(FnLooper &fn);

    // ---------------------------------------------------- Camera
    virtual void followingPlayerView();

    // ---------------------------------------------------- Gravity
    void applyGravity(Object &obj);
    void applyHorizontalColiding(Object &obj);

    // ---------------------------------------------------- Win / Loose conditions
    bool checkPersoStatus();

    // Place it to 'Public' bc can be checked and modify in main
    bool _isDie = false;
    bool _isLevelCleared = false;

protected:
    sf::Event _event;
    Character *_player;
    Object &_background;

    sf::RenderWindow &_window;

    bool _isOver;

private:

    std::list<TextBox> _listEternalTextBox;
    std::list<TextBox> _listTemporaryTextBox;

    std::list<Object> _listBackGround;
    std::list<Object> _listForeGround;
    std::list<Object> _listEternalObjects;
    std::list<Object> _listTemporaryObjects;

    std::list<FnLooper> _listFnEverySecond;
    std::list<FnLooper> _listFnEveryDecisecond;
    std::list<FnLooper> _listFnEveryCentisecond;
    std::list<FnLooper> _listFnEveryMillisecond;

    // std::list<std::reference_wrapper<Object>> _listEternalObjects;
    // std::list<std::reference_wrapper<Object>> _listTemporaryObjects;
    std::list<TextBox> _listTextBoxes;

    sf::Music &_music;
};

#endif // VISUAL_HPP
