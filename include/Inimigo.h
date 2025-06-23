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
                Jogador* pJog2;
                float perseguindo;

                int sentido;
                sf::Vector2f pontoEsquerda;
                sf::Vector2f pontoDireita;
                float tempoDano;
                float tempoInvulneravel;
                float alcanceVisao;
                float rangeAtaque;

            public:
                Inimigo(sf::Vector2f pos,sf::Vector2f tamanho,IDs::IDs id,int vida);

                ~Inimigo();

                void setJogador(Jogador* jog1, Jogador* jog2) { pJog = jog1; if (jog2) { pJog2 = jog2; } }

                virtual void executar(float dt) = 0;
                
                virtual void inicializar() = 0;

                virtual void colidirAtaque(Entidade* outraEntidade, sf::Vector2f intercepta) = 0;

                virtual void atacar(float dt) = 0;

                virtual void definirLimitesDePatrulha(float alcance) = 0;

                void setSentido(int s) { sentido = s; }

				int getSentido() const { return sentido; }

				bool getPerseguindo() const { return perseguindo; }

				void setPerseguindo(bool p) { perseguindo = p; }

                float getTempoDano() { return tempoDano; }
                void setTempoDano(float t) { tempoDano = t; }

                float getTempoInvulneravel() const { return tempoInvulneravel; }
                void setTempoInvulneravel(float t) { tempoInvulneravel = t; }


            };

        }

    }

}



