#pragma once
#include "Ente.h"
#include "Animacao.h"

namespace Entidades {

    class Entidade :public Ente
    {
    protected:
        
        sf::Vector2f pos;
        sf::Vector2f tam;

        bool remover;

    public:
        Entidade(sf::Vector2f tam = { 0.f,0.f }, sf::Vector2f position = { 0.f,0.f }, IDs::IDs id = IDs::IDs::nulo);

        ~Entidade();

        void setPosition(sf::Vector2f position);

        virtual sf::Vector2f getPosicao() const;

        void setTamanho(sf::Vector2f t) { tam = t; }

        sf::Vector2f getTamanho() const;
        

        void podeRemover() { remover = true; }
        bool getRemover() { return remover; }

        virtual void desenhar() = 0;
        virtual void atualizar(float dt) = 0;
        virtual void inicializar() = 0;
        virtual void colidir(Entidade* outraEntidade, sf::Vector2f intercepta) = 0;
    };



}
