/*
** EPITECH PROJECT, 2020
** JAM_sfml_2019
** File description:
** FnLooper.cpp
*/

#include <functional>
#include "FnLooper.hpp"

FnLooper::~FnLooper()
{
    this->_lastFn();
}

FnLooper::Frequency FnLooper::getFrequency() const
{
    return this->_frequency;
}

void FnLooper::operator()() const
{
    this->_loopFn();
}

bool FnLooper::isOver() const
{
    return this->_clock.getElapsedTime() > this->_duration;
}
