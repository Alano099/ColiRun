#pragma once
#include "Inimigo.h"

#define SOLDADO_TAMANHO_X 50.f
#define SOLDADO_TAMANHO_Y 50.f

#define SOLDADO_LIMITE_PATRULHA 150.f

namespace Entidades {

    namespace Personagens {

        namespace Inimigos {


            class Soldado : public Inimigo
            {

            private:
                float forca;

            public:
                Soldado(sf::Vector2f pos, sf::Vector2f tamanho,IDs::IDs id);
                ~Soldado();

                void executar(float dt);
                void inicializar();
                void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);
                void atacar(float dt);
                void definirLimitesDePatrulha(float alcance);
            };

        }


    }

}



