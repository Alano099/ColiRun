#pragma once
#include "Obstaculo.h"

namespace Entidades
{

	namespace Obstaculos
	{

		class Espinho : public Obstaculo
		{

		private:

		public:
			Espinho(sf::Vector2f posicao, sf::Vector2f tamanho);
			~Espinho();

			void atualizar(float dt);
			void inicializar();
			void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);

		};


	}

}


