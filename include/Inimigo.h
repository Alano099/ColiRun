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

            private:
                Jogador* pJog;
                int sentido;
                sf::Vector2f pontoEsquerda;
                sf::Vector2f pontoDireita;
                float perseguindo;

            public:
                Inimigo(sf::Vector2f pos = { 0.f,0.f });

                ~Inimigo();

                void setJogador(Jogador* jog) { pJog = jog; }

                void atualizar(float dt);
                
                void inicializar();

                void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);

                void definirLimitesDePatrulha(float alcance);




            };

        }

    }

}



