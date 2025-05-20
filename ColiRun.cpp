#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

using namespace std;


void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color) {

	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f);

}

int main() {

	sf::RenderWindow janela(sf::VideoMode(480, 180), "NOME");

	janela.setFramerateLimit(60);

	sf::Vector2f startPos = sf::Vector2f(50, 50);
	sf::RectangleShape playerRect(sf::Vector2f(50, 50));
	initShape(playerRect, startPos, sf::Color::Green);
	sf::RectangleShape targetRect(sf::Vector2f(50, 50));
	initShape(targetRect, sf::Vector2f(400, 50), sf::Color::Blue);
	sf::RectangleShape badRect(sf::Vector2f(50, 100));
	initShape(badRect, sf::Vector2f(200, 50), sf::Color::Red);


	bool moving = false;

	while (janela.isOpen()) {



		//Update scene

		//Sempre andando pra direita
		playerRect.move(1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			playerRect.move(0, -1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			playerRect.move(0, 1);

		//Alvo encontrado vc vence
		if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds()))
			janela.close();
		if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds())) {

			playerRect.setPosition(startPos);
			//playerRect.move(-1, 0);
		}

		//Render cycle 
		janela.clear(sf::Color::Black);

		janela.draw(playerRect);
		janela.draw(targetRect);
		janela.draw(badRect);

		janela.display();




	}

	return 0;

}