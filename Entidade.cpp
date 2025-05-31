#include "Entidade.h"

namespace Entidades {



	Entidade::Entidade(sf::Vector2f tam, sf::Vector2f position, sf::Color cor):Ente(ID),pos(position)
	{
		corpo.setFillColor(cor);
		corpo.setSize(tam);
		corpo.setPosition(position);
		corpo.setOrigin(tam * 0.5f);
	}

	void Entidade::mover(float dx, float dy)
	{
		corpo.move(dx, dy);
	}

	void Entidade::setPosition(sf::Vector2f position)
	{
		corpo.setPosition(position);
	}

	void Entidade::resetarPosicao()
	{
		corpo.setPosition(pos);
	}

	void Entidade::desenhar()
	{
		
	}

	bool Entidade::intercepta(const Entidade& outro) const
	{
		return corpo.getGlobalBounds().intersects(outro.corpo.getGlobalBounds());
	}


	sf::Vector2f Entidade::getPosition() const
	{
		return corpo.getPosition();
	}

}