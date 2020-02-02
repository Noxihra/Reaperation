/*
** EPITECH PROJECT, 2019
** main
** File description:
** mains are fun
*/

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "API/Object.hpp"
#include "API/Data.hpp"
#include "Flow/Menu.hpp"
#include "Flow/Level.hpp"
#include "defaultValues.hpp"
#include "Character.hpp"

int main()
{
    Data data;

// ------------------------------------------------------------------ Menu
    // Menu menu(data.window);
    Object menuBackground(data.texture["menuBackground"]);
    Object startButton(data.texture["none"], data.hitbox["ground"]);
    Object exitButton(data.texture["none"], data.hitbox["ground"]);
    Menu menu(data.window, menuBackground, data.music["menu"], startButton, exitButton);

// ------------------------------------------------------------------ Level1
    Object background(data.texture["background"]);
    Object ground(data.texture["none"], data.hitbox["ground"]);
    Character player(data.texture["littleDeathIdle"], data.texture["littleDeathTurn"], \
                     data.texture["littleDeathWalk"], data.texture["littleDeathRun3"], \
                     data.texture["littleDeathJump"], data.texture["littleDeathFall"], \
                     data.texture["littleDeathDie"], \
                     data.hitbox["littleDeath"], 0, 0, 0.4, 0.4, 0, 0, 0, littleDeath::textureRect);
                     //data.hitbox["ground"], 0, 0, 0.4, 0.4, 0, 0, 0, littleDeath::textureRect);

    Level startingZone(data.window, background, data.music["level1"]);
    startingZone.addObject(ground);
    startingZone.setPlayer(&player);

// ------------------------------------------------------------------ Loop Menu
    while (!menu.isOver()) {
        menu.process();
    }

// ------------------------------------------------------------------ Loop Level1

    while (!startingZone.isOver()) {
        if (startingZone.process())
            if (startingZone._isDie) {
                break;
            }
    }
}
