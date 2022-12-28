#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "init.h"
#include "release.h"
#include "draw.h"

int main() {
	sf::Window window(sf::VideoMode(700, 700), "MIR tanka", sf::Style::Default, sf::ContextSettings(24));
	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	// Инициализация glew
	glewInit();
	glEnable(GL_DEPTH_TEST);

	Init();

	bool moveLeft = false;
	bool moveRight = false;
	bool moveGo = false;

	double angle = 0.524;
	double radius = 150.0;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::Resized) {
				glViewport(0, 0, event.size.width, event.size.height);
			}
			else if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case (sf::Keyboard::A):
				{
					moveLeft = true;
					break;
				}
				case (sf::Keyboard::D):
				{
					moveRight = true;
					break;
				}
				case(sf::Keyboard::W):
				{
					moveGo = true;
					break;
				}
				
				default: break;
				}
			}
			else if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case (sf::Keyboard::A):
				{
					moveLeft = false;
					break;
				}
				case (sf::Keyboard::D):
				{
					moveRight = false;
					break;
				}
				case (sf::Keyboard::W):
				{
					moveGo = false;
					break;
				}
				default: break;
				}
			}
		}
		if (moveLeft)
		{
			busMove[0] -= 0.05;
			busRotate[1] -= 0.05;
		}
		if (moveRight)
		{
			busMove[0] += 0.05;
			busRotate[1] += 0.05;
		}
		if (moveGo) {
			road1Move[2] -= 0.07;
			road2Move[2] -= 0.07;
			road3Move[2] -= 0.07;


			grassLeft1Move[2] -= 0.07;
			grassLeft2Move[2] -= 0.07;
			grassLeft3Move[2] -= 0.07;
			grassRight1Move[2] -= 0.07;
			grassRight2Move[2] -= 0.07;
			grassRight3Move[2] -= 0.07;
		}

		if (busRotate[1] < -4.95f && std::abs(busRotate[1] + 4.95) > 0.1f)
			busRotate[1] += 0.03f;
		else if (busRotate[1] > -4.95f && std::abs(busRotate[1] + 4.95) > 0.1f)
			busRotate[1] -= 0.03f;
			/*if (busRotate[1] < -3.14f && std::abs(busRotate[1] + 3.14) > 0.1f)
				busRotate[1] += 0.03f;
			else if (busRotate[1] > -3.14f && std::abs(busRotate[1] + 3.14) > 0.1f)
				busRotate[1] -= 0.03f;*/
		
		if (std::abs(road1Move[2] + 10) < 0.1)
			road1Move[2] = 10;
		if (std::abs(road2Move[2] - 10) < 0.1)
			road2Move[2] = 30;
		if (std::abs(road3Move[2] - 30) < 0.1)
			road3Move[2] = 50;

		

		if (std::abs(grassLeft1Move[2] + 10) < 0.1)
			grassLeft1Move[2] = 10;
		if (std::abs(grassLeft2Move[2] - 10) < 0.1)
			grassLeft2Move[2] = 30;
		if (std::abs(grassLeft3Move[2] - 30) < 0.1)
			grassLeft3Move[2] = 50;

		if (std::abs(grassRight1Move[2] + 10) < 0.1)
			grassRight1Move[2] = 10;
		if (std::abs(grassRight2Move[2] - 10) < 0.1)
			grassRight2Move[2] = 30;
		if (std::abs(grassRight3Move[2] - 30) < 0.1)
			grassRight3Move[2] = 50;


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Draw();

		window.display();
	}

	Release();
	return 0;
}

