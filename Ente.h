#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

class Ente
{

	protected:
	sf::RectangleShape rect;
	sf::Vector2f pos;

	public:

		Ente(sf::Vector2f tam, sf::Vector2f position, sf::Color cor);
		
		void mover(float dx, float dy);
		void setPosition(sf::Vector2f position);
		void resetarPosicao();
		void desenhar(sf::RenderWindow& janela);
		bool intercepta(const Ente& outro) const;
		sf::Vector2f getPosition() const;
};

