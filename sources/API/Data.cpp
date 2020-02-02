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
    // Level1
    this->hitbox["ground"] = sf::FloatRect(-3000, 3625, 5700, 100);
    this->hitbox["plateform"] = sf::FloatRect(-3000, 3425, 5700, 100);

    // Little Death
    this->hitbox["littleDeath"] = sf::FloatRect(40, -20, 80, 160);

// ------------------------------------------------------------------ Texture
    this->texture["none"];

    // Menu
    this->loadTexture("menuBackground", menu::background);

    // Level1
    this->loadTexture("background", env::background);
    this->loadTexture("plateform", env::plateform);

    // Little Death
    this->hitbox["littleDeath"] = sf::FloatRect(40, -20, 80, 160);
    this->loadTexture("littleDeathIdle", littleDeath::idle);
    this->loadTexture("littleDeathRun", littleDeath::run);
    this->loadTexture("littleDeathRun3", littleDeath::run2);
    this->loadTexture("littleDeathDie", littleDeath::die);

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
