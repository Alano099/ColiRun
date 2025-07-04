#pragma once
#include "Ente.h"
#include "Animacao.h"

constexpr float GRAVIDADE = 900.f;
#define CHAO 600.f


namespace Entidades {
    #define LIMITE_ESQUERDA 50.f
    class Entidade :public Ente
    {
    protected:
        
        sf::Vector2f pos;
        sf::Vector2f tam;
        sf::Vector2f velocidade;
        bool noChao;


        static float gravidade;
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
        virtual void executar(float dt) = 0;
        virtual void inicializar() = 0;
        

        void setNochao(bool c) { noChao = c; /*cout << "em cima"; */ }

        const sf::Vector2f getVelocidade() { return velocidade; }

        void setVelocidade(sf::Vector2f v) { velocidade = v; }

    };



}

