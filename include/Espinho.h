#pragma once
#include "Obstaculo.h"

#define ESPINHO_TAMANHO_X 32.f
#define ESPINHO_TAMANHO_Y 32.f

namespace Entidades
{

	namespace Obstaculos
	{

		class Espinho : public Obstaculo
		{

		private:
			float dano;
		public:
			Espinho(sf::Vector2f posicao, sf::Vector2f tamanho,IDs::IDs id);
			~Espinho();

			void executar(float dt);
			void inicializar();
			void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);

		};


	}

}


