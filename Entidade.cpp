#include "Entidade.h"

namespace Entidades {

	Entidade::Entidade(sf::Vector2f tam, sf::Vector2f position, IDs::IDs id):Ente(id),pos(pos),tam(tam)
	{
	}

	Entidade::~Entidade(){}

	void Entidade::setPosition(sf::Vector2f position)
	{
		this->pos = position;
	}

	sf::Vector2f Entidade::getPosicao() const
	{
		return pos;
	}

	sf::Vector2f Entidade::getTamanho() const
	{
		return tam;
	}

	void Entidade::desenhar()
	{
	}

	

}