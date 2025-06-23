 #include "../include/Entidade.h"

namespace Entidades {

	Entidade::Entidade(sf::Vector2f position, sf::Vector2f tam, IDs::IDs id):Ente(id),pos(position),tam(tam),remover(false), noChao(false)
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


	

}