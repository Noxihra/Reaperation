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
    Object menuCredit(data.texture["menuCredit"]);
    Object startButton(data.texture["none"], data.hitbox["menuStartButton"]);
    Object exitButton(data.texture["none"], data.hitbox["menuExitButton"]);
    Object creditButton(data.texture["none"], data.hitbox["menuCreditButton"]);
    Object exitButtonCredit(data.texture["none"], data.hitbox["menuExitButtonCredit"]);
    Menu menu(data.window, menuBackground, data.music["menu"], startButton, exitButton, creditButton, menuCredit, exitButtonCredit);

// ------------------------------------------------------------------ Level1
    Object background(data.texture["background"]);
    Object ground(data.texture["none"], data.hitbox["ground"]);
    Character player(data.texture["littleDeathIdle"], data.texture["littleDeathTurn"], \
                     data.texture["littleDeathWalk"], data.texture["littleDeathRun3"], \
                     data.texture["littleDeathJump"], data.texture["littleDeathFall"], \
                     data.texture["littleDeathDie"], \
                     data.hitbox["littleDeath"], 0, 0, 0.4, 0.4, 0, 0, 0, littleDeath::textureRect);
    Object backgroundFirstLayer(data.texture["forest_1"], sfFloatRect0DefaultValue, 0, 0, 0, 1, 1, 0, 0, 0);
    Object backgroundSecondLayer(data.texture["forest_2"], sfFloatRect0DefaultValue, 0, 0, 1, 1, 0, 0, 0);
    Object backgroundThirdLayer(data.texture["forest_3"], sfFloatRect0DefaultValue, 0, 0, 1, 1, 0, 0, 0);
    Object backgroundFourthLayer(data.texture["forest_4"], sfFloatRect0DefaultValue, 0, 0, 1, 1, 0, 0, 0);
    Object backgroundFifthLayer(data.texture["forest_5"], sfFloatRect0DefaultValue, 0, 0, 1, 1, 0, 0, 0);
    Object backgroundSixthLayer(data.texture["forest_6"], sfFloatRect0DefaultValue, 0, 0, 1, 1, 0, 0, 0);
    Level forestLevel(data.window, backgroundSixthLayer, data.music["level1"]);
    forestLevel.addBackground(backgroundSixthLayer);
    forestLevel.addBackground(backgroundFifthLayer);
    forestLevel.addBackground(backgroundFourthLayer);
    forestLevel.addBackground(backgroundThirdLayer);
    forestLevel.addBackground(backgroundSecondLayer);
    forestLevel.addBackground(backgroundFirstLayer);
    forestLevel.addObject(ground);
    forestLevel.setPlayer(&player);

// ------------------------------------------------------------------ Loop Menu
    while (!menu.isOver()) {
        menu.process();
    }

// ------------------------------------------------------------------ Loop Level1

    while (!forestLevel.isOver()) {
        if (forestLevel.process())
            if (forestLevel._isDie) {
                forestLevel.closeWindow();
        }
    }
}
