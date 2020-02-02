/*
** EPITECH PROJECT, 2019
** Data
** File description:
** Every data that have to be load at the begining
*/

#ifndef DATA_HPP
#define DATA_HPP

#include <SFML/Audio/Music.hpp>
#include <unordered_map>
#include <memory>
#include <string>

namespace sf {
    class RenderWindow;
    class Texture;
    class Music;
}

class Data {
public:
    Data();
    ~Data() = default;

    void loadTexture(const std::string &index, const std::string &filepath);
    void loadMusic(const std::string &index, const std::string &filepath);

    sf::RenderWindow window;
    std::unordered_map<std::string, sf::Texture> texture;
    std::unordered_map<std::string, sf::FloatRect> hitbox;
    std::unordered_map<std::string, sf::Music> music;
};

#endif // DATA_HPP
