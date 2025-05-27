#include "Ente.h"

Ente::Ente(sf::Vector2f tam, sf::Vector2f position, sf::Color cor):pos(position)
{

	rect.setFillColor(cor);
	rect.setSize(tam);
	rect.setPosition(position);
	rect.setOrigin(tam * 0.5f);

}

void Ente::mover(float dx, float dy)
{
	rect.move(dx, dy);
}

void Ente::setPosition(sf::Vector2f position)
{
	rect.setPosition(position);
}

void Ente::resetarPosicao()
{
	rect.setPosition(pos);
}

void Ente::desenhar(sf::RenderWindow& janela)
{
	janela.draw(rect);
}

bool Ente::intercepta(const Ente& outro) const
{
	return rect.getGlobalBounds().intersects(outro.rect.getGlobalBounds());
}


sf::Vector2f Ente::getPosition() const
{
	return rect.getPosition();
}
