#pragma once

#include "Personagem.h"

#define JOGADOR_TAMANHO_Y 40.0f
#define JOGADOR_TAMANHO_X 32.0f
#define JOGADOR_VIDA 100

namespace Entidades {

	namespace Personagens {

		class Jogador:public Personagem
		{

		private:
			const bool ehJogador1;
			float tempo;
			bool noChao;

			/*
			bool	podeAtacar;
			float tempoAtaque;
			bool estaAtacando;
			sf::RectangleShape ataque;
			float ataqueCooldown;
			
			*/

		public:

			Jogador(sf::Vector2f pos = { 0.f,0.f }, bool ehJogador1 = true);
			~Jogador();

			void atualizar(float dt);
			void inicializar();
			void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);
			void atacar(float dt);
			void desenharAtaque();

			sf::FloatRect getHitBoxAtaque()const
			{ return (!podeAtacar ? ataque.getGlobalBounds() : sf::FloatRect()); }

		};


	}

}


