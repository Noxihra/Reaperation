/*
** EPITECH PROJECT, 2019
** Config
** File description:
** Config of the project
*/

#ifndef CONFIG
#define CONFIG

// --------------------------------------------------------- Filepath

// Texture
#define BACKGROUND_PATH "assets/visual/test_background.png"
#define PLAYER_PATH "assets/visual/black.png"
#define TEST_PATH "assets/visual/blue.png"

#include <SFML/Graphics/Rect.hpp>

// Environement
namespace menu {
    static const std::string background("assets/visual/background/menu/menu.png");
}

// Environement
namespace env {
    static const std::string background("assets/visual/background/01.png");
    static const std::string plateform("assets/visual/plateformes/plateforme.png");
}

// LittleDeath
namespace littleDeath {
    static sf::Rect<int> textureRect(0, 0, 512, 512);
    static const std::string idle("assets/visual/littleDeath/idle.png");
    static const std::string run("assets/visual/littleDeath/run.png");
    static const std::string run2("assets/visual/littleDeath/run3.png");
    static const std::string die("assets/visual/littleDeath/death.png");
}

// Font
#define DEFAULT_FONT_PATH "assets/textual/font.ttf"

// Music
#define MENU_MUSIC_PATH "assets/audio/menu_music.flac"
#define LEVEL_MUSIC_PATH "assets/audio/level_music.flac"

// --------------------------------------------------------- Others

#define FPS 100

#define MIDDLEX 2680
#define MIDDLEY 1227

//#define DEBUG true

#endif // CONFIG
