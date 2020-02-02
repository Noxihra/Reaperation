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

    template<typename LoopFn, typename... LoopArgs,
             typename LastFn, typename... LastArgs>
    FnLooper(sf::Time duration, Frequency frequency,
             LoopFn &&loopFn, LoopArgs &&...loopArgs,
             LastFn &&lastFn = []{}, LastArgs &&...lastArgs);

    ~FnLooper();

    Frequency getFrequency() const;

    void operator()() const;
    bool isOver() const;

private:
    sf::Clock _clock;
    sf::Time _duration;
    Frequency _frequency;
    std::function<void()> _loopFn, _lastFn;
};

template<typename LoopFn, typename... LoopArgs,
         typename LastFn, typename... LastArgs>
FnLooper::FnLooper(sf::Time duration, Frequency frequency,
                   LoopFn &&loopFn, LoopArgs &&...loopArgs,
                   LastFn &&lastFn, LastArgs &&...lastArgs)
    : _duration(duration), _frequency(frequency) \
    , _loopFn(std::bind(loopFn, std::forward(loopArgs)...)) \
    , _lastFn(std::bind(lastFn, std::forward(lastArgs)...))
{
    this->_loopFn();
}

#endif
