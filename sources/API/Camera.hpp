/*
** EPITECH PROJECT, 2020
** JAM_sfml_2019
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "API/Object.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Camera {
	public:
        Camera(sf::RenderWindow &window);
		~Camera();
        void followingPlayerView(Object *player, sf::RenderWindow &window);
        void progressiveResetViewToPlayer();
        void moveView(sf::Vector2f &playerPos);

        void setSpeedView(float speedX, float speedY);
        void setMoving(bool isMoving);
        void setZoom(float zoom);

        const sf::Vector2<float> &getVecView();
	protected:
	private:
        sf::View _view;
        sf::Vector2<float> _vecView;
        sf::Vector2<float> _speedView;
        bool _isMoving;
};

#endif /* !CAMERA_HPP_ */
