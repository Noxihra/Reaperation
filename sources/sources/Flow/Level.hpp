/*
** EPITECH PROJECT, 2019
** Level
** File description:
** every level of the game
*/

#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "API/Scene.hpp"

class Level : public Scene {
public:
    Level(sf::RenderWindow &window, Object &background, sf::Music &music);
    ~Level() = default;

    void keyPressed() final;
    void keyReleased() final;
    void mouseButtonPressed() final;
    void mouseButtonReleased() final;
    void mouseMoved() final;

    void processPerSecond() final;
    void processPerDecisecond() final;
    void processPerCentisecond() final;
    void processPerMillisecond() final;
    void processPerFrame() final;
    /*
    void followingPlayerView() final;
    void moveView(sf::Vector2f &);
    void progressiveResetViewToPlayer();
    void setSpeedView(float speedX, float speedY);*/
private:
};

#endif // LEVEL_HPP
