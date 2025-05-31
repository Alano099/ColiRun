#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>
#include "Ente.h"

using namespace std;


void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color) {

	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f);

}

int main() {

	sf::RenderWindow janela(sf::VideoMode(480, 180), "NOME");

	janela.setFramerateLimit(60);

	Ente jogador({ 50, 50 }, { 50, 50 }, sf::Color::Green);
	Ente alvo({ 50,50 }, { 400,50 }, sf::Color::Blue);
	Ente obstaculo({ 50,100 }, { 200,50 }, { sf::Color::Red });


	bool moving = false;

	while (janela.isOpen()) {



		//Update scene

		//Sempre andando pra direita
		jogador.mover(1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			jogador.mover(0, -1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			jogador.mover(0, 1);

		//Alvo encontrado vc vence
		if (jogador.intercepta(alvo))
			janela.close();
		if (jogador.intercepta(obstaculo)) {

			jogador.resetarPosicao();
			//playerRect.move(-1, 0);
		}

		//Render cycle 
		janela.clear(sf::Color::Black);

		jogador.desenhar(janela);
		obstaculo.desenhar(janela);
		alvo.desenhar(janela);

		janela.display();




	}

	return 0;

}