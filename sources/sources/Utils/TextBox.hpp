/*
** EPITECH PROJECT, 2020
** JAM_sfml_2019
** File description:
** Text
*/

#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class TextBox
{
public:
    TextBox(std::string string, sf::Font &font,
            sf::Color fillColor, sf::Color outlineColor = sf::Color::Transparent,
            sf::Color boxColor = sf::Color::Black,
            float scaleFactorX  = 1, float scaleFactorY = 1,
            float outlineThickness = 0, sf::Uint32 style = sf::Text::Regular,
            float posX = 0, float posY = 0,
            unsigned int charSize = 30, int longevity = 0);
    ~TextBox();

    int getLongevity() const;
    sf::Text const &getText() const;
    sf::RectangleShape const &getBox() const;
    std::string getString() const;
    const sf::Font *getFont() const;
    sf::Color const &getFillColor() const;
    sf::Color const &getOutlineColor() const;
    float getOutlineThickness() const;
    sf::Uint32 getStyle() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getOrigin() const;
    unsigned int getCharSize() const;
    const sf::Vector2f getScale() const;

    void setString(std::string const &string);
    void setText(sf::Text const &text);
    void setFont(sf::Font const &font);
    void setFillColor(sf::Color const &color);
    void setOutlineColor(sf::Color const &color);
    void setOutlineThickness(float outlineThickness);
    void setStyle(sf::Uint32 style);
    void setPosition(sf::Vector2f position);
    void setOrigin(sf::Vector2f position);
    void setCharSize(unsigned int size);
    void setScale(sf::Vector2f scale);

protected:
private:
    sf::Text _text;
    int _longevity;
    sf::RectangleShape _box;
};
