/*
** EPITECH PROJECT, 2019
** Menu
** File description:
** Menu scene
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "API/Scene.hpp"
#include "API/Object.hpp"

class Menu : public Scene {
public:
    Menu(sf::RenderWindow &window, Object &background, sf::Music &music, \
         Object &startButton, Object &exitButton, Object &creditButton, Object &credit, Object &exitButtonCredit);
    ~Menu() = default;

    void keyPressed();
    void keyReleased();
    void mouseButtonPressed();
    void mouseButtonReleased();
    void mouseMoved();

    void processPerSecond();
    void processPerDecisecond();
    void processPerCentisecond();
    void processPerMillisecond();
    void processPerFrame();

private:
    Object &_startButton;
    Object &_exitButton;
    Object &_creditButton;
    Object &_credit;
    Object &_exitButtonCredit;
};

#endif // MENU_HPP
