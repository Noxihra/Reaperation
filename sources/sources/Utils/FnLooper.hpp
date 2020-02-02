/*
** EPITECH PROJECT, 2020
** JAM_sfml_2019
** File description:
** FnLooper.hpp
*/

#ifndef FNLOOPER_HPP
#define FNLOOPER_HPP

#include <functional>
#include <SFML/System/Clock.hpp>

class FnLooper {
public:
    enum Frequency {
        EverySecond,
        EveryDecisecond,
        EveryCentisecond,
        EveryMillisecond,
    };

    template<typename Fn, typename... Args>
    FnLooper(sf::Time duration, Frequency frequency, Fn&& fn, Args&&... args);

    Frequency getFrequency() const;

    void operator()() const;
    bool isOver() const;

private:
    std::function<void()> _fn;
    Frequency _frequency;
    sf::Time _duration;
    sf::Clock _clock;
};

#endif
