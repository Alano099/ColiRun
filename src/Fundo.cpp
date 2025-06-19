#include "../include/Fundo.h"
#include <iostream>

namespace ElementosGraficos {

	Fundo::Fundo():offset(0.f){}

	Fundo::~Fundo()
	{
	}

	bool Fundo::inicializar(const std::string& caminho, sf::Vector2f tamanho)
	{
		if (!textura.loadFromFile(caminho)) {
			std::cerr << "Erro ao carregar textura de fundo parallax.\n";
			return false;
		}

		textura.setRepeated(true);

		sprite.setTexture(textura);
		sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(tamanho.x),textura.getSize().y));

		return true;
	}

	void Fundo::atualizar(float dt, float movimentoX)
	{
		offset += dt * movimentoX;
		sprite.setTextureRect(sf::IntRect(static_cast<int>(offset), 0, sprite.getTextureRect().width, sprite.getTextureRect().height));
	}

	void Fundo::desenhar(sf::RenderWindow* janela)
	{
		janela->draw(sprite);
	}



}