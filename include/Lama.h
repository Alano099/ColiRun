#pragma once

#include "Obstaculo.h"

#define LAMA_TAMANHO_X 32.f
#define LAMA_TAMANHO_Y 32.f

namespace Entidades {


	namespace Obstaculos {

		class Lama :public Obstaculo
		{

		private:
			float cfDesacelerar;

		public:
			Lama(sf::Vector2f posicao, sf::Vector2f tamanho, IDs::IDs id);
			~Lama();
			void executar(float dt);
			void inicializar();
			void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);

		};


	}

}