#pragma once

#include "Personagem.h"

#define JOGADOR_TAMANHO_Y 85.0f
#define JOGADOR_TAMANHO_X 32.0f
#define JOGADOR_VIDA 100

namespace Entidades {

	namespace Personagens {

		class Jogador:public Personagem
		{

		private:
			const bool ehJogador1;
			float tempo;

		public:

			Jogador(sf::Vector2f pos = { 0.f,0.f }, bool ehJogador1 = true);
			~Jogador();

			void mover(float dx, float dy);

			void atualizar(float dt);
			void inicializar();
			void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);

		};


	}

}


