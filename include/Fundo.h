#pragma once
#include <SFML/Graphics.hpp>

namespace ElementosGraficos {


	class Fundo
	{
	private:
		sf::Texture textura;
		sf::Sprite sprite;
		float offset;

	public:
		Fundo();
		~Fundo();
		bool inicializar(const std::string& caminho, sf::Vector2f tamanho);
		void atualizar(float dt, float movimentoX);
		void desenhar(sf::RenderWindow* janela);

	};


}


