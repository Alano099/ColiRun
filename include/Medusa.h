#pragma once
#include "Inimigo.h"
#include "Projetil.h"

#define MEDUSA_TAMANHO_X 64.f
#define MEDUSA_TAMANHO_Y 64.f

#define MEDUSA_LIMITE_PATRULHA 50.f

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {

            class Medusa : public Inimigo
            {
            private:
                Projetil* projetil;
                sf::Vector2f pontoEsquerda, pontoDireita;
                sf::Vector2f ultimoAlvo;

                float tempoCooldownTiro;

            public:
                Medusa(sf::Vector2f pos, sf::Vector2f tamanho, IDs::IDs id,int vida);
                ~Medusa();

                void executar(float dt) override;
                void inicializar() override;
                void colidirAtaque(Entidade* outraEntidade, sf::Vector2f intercepta) override;
                void atacar(float dt) override;

                void definirLimitesDePatrulha(float alcance);
                void setProjetil(Projetil* p) { projetil = p; }
            };

        }
    }
}