#pragma once
#include "Ente.h"

namespace Entidades {

class Entidade :public Ente
{
private:
    sf::RectangleShape corpo;
    sf::Vector2f pos;
    sf::Vector2f tam;
public:
    Entidade(sf::Vector2f tam, sf::Vector2f position, sf::Color cor);

    void mover(float dx, float dy);
    void setPosition(sf::Vector2f position);
    sf::RectangleShape getCorpo() { return corpo; }
    void resetarPosicao();
    void desenhar();
    bool intercepta(const Entidade& outro) const;
    sf::Vector2f getPosition() const;


};



}


