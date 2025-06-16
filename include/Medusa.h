#pragma once
#include "Inimigo.h"

namespace Entidades {

	namespace Personagens {

		namespace Inimigos {

			class Medusa : public Inimigo
			{
			private:
				
			public:
				Medusa(sf::Vector2f pos = { 0.f,0.f });
				~Medusa();
				void atualizar(float dt);
				void inicializar();
				void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);
				void atacar(float dt);
				void definirLimitesDePatrulha(float alcance);
			};
		}
	}
}
