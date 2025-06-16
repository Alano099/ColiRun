#pragma once
#include "Inimigo.h"

namespace Entidades
{

    namespace Personagens {

        namespace Inimigos {

            class Minotauro :
                public Inimigo
            {

            private:

            public:
				Minotauro(sf::Vector2f pos = { 0.f,0.f });
				~Minotauro();
				void colidir(Entidade* outraEntidade, sf::Vector2f intercepta) override;
				void atualizar(float dt);
				void inicializar();
				void atacar(float dt) override;
				void definirLimitesDePatrulha(float alcance);

            };

        }

    }

}


