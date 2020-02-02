/*
** EPITECH PROJECT, 2020
** JAM_sfml_2019
** File description:
** Text
*/

#include "TextBox.hpp"
#include "API/Scene.hpp"

TextBox::TextBox(std::string string, sf::Font &font,
                 sf::Color fillColor, sf::Color outlineColor /* = sf::Color::Transparent,*/,
                 sf::Color boxColor /* = sf::Color::Black */, float scaleFactorX /* = 1 */,
                 float scaleFactorY /*= 1*/, float outlineThickness /* = 0 */,
                 sf::Uint32 style /* = sf::Text::Regular */,
                 float posX /* = 0 */, float posY /* = 0 */,
                 unsigned int charSize /* = 30 */, int longevity /* = 0 */
                 )
    : _text(sf::Text(string, font, charSize)), _longevity(longevity)
{
    _text.setOrigin(posX, posY);
    _text.setStyle(style);
    _text.setFillColor(fillColor);
    _text.setOutlineColor(outlineColor);
    _text.setOutlineThickness(outlineThickness);
    _text.setScale(scaleFactorX, scaleFactorY);
    sf::FloatRect textLocalBounds = _text.getLocalBounds();
    _box = sf::RectangleShape(sf::Vector2f(textLocalBounds.width, textLocalBounds.height));
    _box.setFillColor(boxColor);
    _box.setPosition(textLocalBounds.left, textLocalBounds.top);
}

TextBox::~TextBox()
{
}

/*  shapeRect -> specific color -> text inside */

int TextBox::getLongevity() const
{
    return _longevity;
}

sf::Text const &TextBox::getText() const
{
    return _text;
}

sf::RectangleShape const &TextBox::getBox() const
{
    return _box;
}


std::string TextBox::getString() const
{
    return _text.getString();
}

const sf::Font *TextBox::getFont() const
{
    return _text.getFont();
}

sf::Color const &TextBox::getFillColor() const
{
    return _text.getFillColor();
}

sf::Color const &TextBox::getOutlineColor() const
{
    return _text.getOutlineColor();
}

float TextBox::getOutlineThickness() const
{
    return _text.getOutlineThickness();
}

sf::Uint32 TextBox::getStyle() const
{
    return _text.getStyle();
}

sf::Vector2f TextBox::getPosition() const
{
    return _text.getPosition();
}

sf::Vector2f TextBox::getOrigin() const
{
    return _text.getOrigin();
}

unsigned int TextBox::getCharSize() const
{
    return _text.getCharacterSize();
}

const sf::Vector2f TextBox::getScale() const
{
    return _text.getScale();
}

void TextBox::setString(std::string const &string)
{
    _text.setString(string);
}

void TextBox::setText(sf::Text const &text)
{
    _text = text;
}

void TextBox::setFont(sf::Font const &font)
{
    _text.setFont(font);
}

void TextBox::setFillColor(sf::Color const &color)
{
    _text.setFillColor(color);
}

void TextBox::setOutlineColor(sf::Color const &color)
{
    _text.setOutlineColor(color);
}

void TextBox::setOutlineThickness(float outlineThickness)
{
    _text.setOutlineThickness(outlineThickness);
}

void TextBox::setStyle(sf::Uint32 style)
{
    _text.setStyle(style);
}

void TextBox::setPosition(sf::Vector2f position)
{
    _text.setPosition(position);
}

void TextBox::setCharSize(unsigned int size)
{
    _text.setCharacterSize(size);
}

void TextBox::setScale(sf::Vector2f scale)
{
    _text.setScale(scale);
}
