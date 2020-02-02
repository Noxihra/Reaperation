/*
** EPITECH PROJECT, 2020
** JAM_sfml_2019
** File description:
** FnLooper.cpp
*/

#include <functional>
#include "FnLooper.hpp"

template<typename Fn, typename... Args>
FnLooper::FnLooper(sf::Time duration, Frequency frequency, Fn &&fn, Args &&...args)
    : _duration(duration), _frequency(frequency)
    ,_fn(std::bind(std::forward(fn), std::forward(args)...))
{}

FnLooper::Frequency FnLooper::getFrequency() const
{
    return this->_frequency;
}

void FnLooper::operator()() const
{
    this->_fn();
}

bool FnLooper::isOver() const
{
    return this->_clock.getElapsedTime() > this->_duration;
}
