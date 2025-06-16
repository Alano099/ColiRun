#pragma once
#include "Inimigo.h"

namespace Entidades {

    namespace Personagens {

        namespace Inimigos {


            class Soldado : public Inimigo
            {

            private:
                float forca;

            public:
                Soldado(sf::Vector2f pos = {0.f,0.f});
                ~Soldado();

                void atualizar(float dt);
                void inicializar();
                void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);
                void atacar(float dt);
                void definirLimitesDePatrulha(float alcance);
            };

        }


    }

}



