#pragma once
#include "Inimigo.h"

#define MEDUSA_TAMANHO_X 64.f
#define MEDUSA_TAMANHO_Y 64.f

#define MEDUSA_LIMITE_PATRULHA 50.f

namespace Entidades {

	namespace Personagens {

		namespace Inimigos {

			class Medusa : public Inimigo
			{
			private:
				float alcance;
			public:
				Medusa(sf::Vector2f pos, sf::Vector2f tamanho, IDs::IDs id);
				~Medusa();
				void executar(float dt);
				void inicializar();
				void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);
				void atacar(float dt);
				void definirLimitesDePatrulha(float alcance);
			};
		}
	}
}
