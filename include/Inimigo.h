#pragma once
#include "Personagem.h"
#include "Jogador.h"

#define INIMIGO_TAMANHO_X = 32.0f
#define INIMIGO_TAMANHO_Y = 63.0f

namespace Entidades {

    namespace Personagens {

        namespace Inimigos {


            class Inimigo :public Personagem
            {

            protected:
                Jogador* pJog;
                float perseguindo;

                int sentido;
                sf::Vector2f pontoEsquerda;
                sf::Vector2f pontoDireita;
                float tempoDano;
               

            public:
                Inimigo(sf::Vector2f pos,sf::Vector2f tamanho,IDs::IDs id);

                ~Inimigo();

                void setJogador(Jogador* jog) { pJog = jog; }

                virtual void executar(float dt) = 0;
                
                virtual void inicializar() = 0;

                virtual void colidir(Entidade* outraEntidade, sf::Vector2f intercepta) = 0;

                virtual void atacar(float dt) = 0;

                virtual void definirLimitesDePatrulha(float alcance) = 0;




            };

        }

    }

}



