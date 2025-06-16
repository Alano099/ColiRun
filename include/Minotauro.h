#pragma once
#include "Inimigo.h"

#define MINOTAURO_TAMANHO_X 64.0f
#define MINOTAURO_TAMANHO_Y 94.0f

#define MINOTAURO_LIMITE_PATRULHA 50.f

namespace Entidades
{

    namespace Personagens {

        namespace Inimigos {

            class Minotauro :
                public Inimigo
            {

            private:
                bool enfurecido;
            public:
				Minotauro(sf::Vector2f pos,sf::Vector2f tamanho, IDs::IDs id);
				~Minotauro();
				void colidir(Entidade* outraEntidade, sf::Vector2f intercepta) override;
				void executar(float dt);
				void inicializar();
				void atacar(float dt) override;
				void definirLimitesDePatrulha(float alcance);

            };

        }

    }

}


