#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Animacao.h"

namespace ElementosGraficos {

	class AnimacaoEstatica : public Animacao
	{
	private:
		sf::Texture* textura;

	public:
		AnimacaoEstatica();
		~AnimacaoEstatica();

		void setScale(sf::Vector2f esc);

		sf::Vector2f getPosicao() const {
			return corpo.getPosition();
		}
		sf::Texture* getTextura() const;

		void executar(sf::Vector2f posicao);
	
		void inicializar(const char* caminho, sf::Vector2f posicao, sf::Vector2f tamanho);
	};

}


