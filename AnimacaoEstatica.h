#pragma once

#include <SFML/Graphics.hpp>

namespace ElementosGraficos {

	class AnimacaoEstatica
	{
	private:
		sf::Texture* textura;
		sf::RectangleShape corpo;

	public:
		AnimacaoEstatica(const char* caminho, sf::Vector2f posicao, sf::Vector2f tamanho, float escala);
		~AnimacaoEstatica();

		void atualizar(sf::Vector2f posicao);
		void desenhar();
	};

}


