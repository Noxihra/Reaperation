/*
** EPITECH PROJECT, 2019
** Data
** File description:
** Every data that have to be load at the begining
*/

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>
#include "Config.hpp"
#include "Macro.hpp"
#include "Data.hpp"

Data::Data()
{
    this->window.create(sf::VideoMode::getDesktopMode(), "GameWindow", \
                        sf::Style::Fullscreen);
    this->window.setKeyRepeatEnabled(false);

// ------------------------------------------------------------------ Hitbox
    // Menu
    this->hitbox["menuStartButton"] = sf::FloatRect(965, 735, 225, 125);
    this->hitbox["menuExitButton"] = sf::FloatRect(0, 0, 100, 100);

    // Level1
    this->hitbox["ground"] = sf::FloatRect(0, 500, 15000, 100);
    this->hitbox["plateform"] = sf::FloatRect(-3000, 3425, 5700, 100);

    // Little Death
    this->hitbox["littleDeath"] = sf::FloatRect(40, -20, 80, 160);

// ------------------------------------------------------------------ Texture
    this->texture["none"];

    // Menu
    this->loadTexture("menuBackground", menu::background);

    // Level1
    this->loadTexture("background", env::level1::background);
    this->loadTexture("plateform", env::level1::plateform);
    this->loadTexture("forest_1", env::level1::forest_1);
    this->loadTexture("forest_2", env::level1::forest_2);
    this->loadTexture("forest_3", env::level1::forest_3);
    this->loadTexture("forest_4", env::level1::forest_4);
    this->loadTexture("forest_5", env::level1::forest_5);
    this->loadTexture("forest_6", env::level1::forest_6);

    // Little Death
    this->hitbox["littleDeath"] = sf::FloatRect(40, -20, 80, 160);
    this->loadTexture("littleDeathIdle", littleDeath::idle);
    this->loadTexture("littleDeathTurn", littleDeath::turn);
    this->loadTexture("littleDeathRun", littleDeath::run);
    this->loadTexture("littleDeathRun3", littleDeath::run2);
    this->loadTexture("littleDeathDie", littleDeath::die);

    // Forest level backgrounds

// ------------------------------------------------------------------ Music
    // Menu
    this->loadMusic("menu", LEVEL_MUSIC_PATH);

    // Level1
    this->loadMusic("level1", LEVEL_MUSIC_PATH);
}

void Data::loadTexture(const std::string &index, const std::string &filepath)
{
    if (!this->texture[index].loadFromFile(filepath)) {
        ABORT_CRITICAL_ERROR("probably wrong filepath");
    }
}

void Data::loadMusic(const std::string &index, const std::string &musicPath)
{
    if (!this->music[index].openFromFile(musicPath)) {
        ABORT_CRITICAL_ERROR("probably wrong filepath");
    }
    this->music[index].setLoop(true);
}
