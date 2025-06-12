#include "Botao.h"
#include <iostream>

namespace Menus {
	Gerenciadores::Gerenciador_Grafico* Botao::pGG(Gerenciadores::Gerenciador_Grafico::get_instance());

	Botao::Botao(sf::Vector2f posicao) :
	corpo(sf::Vector2f(BOTAO_X, BOTAO_Y)),
	text()
	{
		corpo.setOrigin(BOTAO_X / 2, BOTAO_Y / 2);
		text.setOrigin(BOTAO_X / 2 - 50, BOTAO_Y / 2 - 50);

		corpo.setFillColor(sf::Color(240, 230, 140));
		corpo.setOutlineThickness(6);
		corpo.setOutlineColor(sf::Color::Black);

		text.setFont(*pGG->getFonte());
		text.setFillColor(sf::Color(65, 130, 190));
		text.setCharacterSize(50);

		corpo.setPosition(posicao);
		text.setPosition(posicao);
		text.setOutlineThickness(3.f);
		text.setOutlineColor(sf::Color::Black);
	}
	Botao::~Botao() {}

	void Botao::desenhar()
	{
		pGG->desenhar(&corpo);
		pGG->desenhar(&text);
	}

	void Botao::escolherCor()
	{
		if (corpo.getFillColor() == sf::Color(240, 230, 140)) {
			corpo.setFillColor(sf::Color(205, 92, 92));
		}
		else {
			corpo.setFillColor(sf::Color(240, 230, 140));
		}
	}
	void Botao::setNome(std::string nome)
	{
		text.setString(nome);
	}
	void Botao::setPosicao(sf::Vector2f posicao)
	{
		corpo.setPosition(posicao);
		text.setPosition(posicao);
	}

}