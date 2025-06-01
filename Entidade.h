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
        Entidade(sf::Vector2f tam = { 0.f,0.f }, sf::Vector2f position = { 0.f,0.f }, IDs::IDs id = IDs::IDs::nulo);

        ~Entidade();

        void setPosition(sf::Vector2f position);

        sf::Vector2f getPosicao() const;

        sf::Vector2f getTamanho() const;

        sf::RectangleShape getCorpo() { return corpo; }

        virtual void desenhar();
        virtual void atualizar(float dt) = 0;
        virtual void inicializar() = 0;

    };



}
