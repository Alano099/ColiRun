#pragma once

#include "Personagem.h"


#define JOGADOR_TAMANHO_Y 58.0f
#define JOGADOR_TAMANHO_X 32.0f
#define JOGADOR_VIDA 100

namespace Entidades {

	namespace Personagens {

		class Jogador:public Personagem
		{

		private:
			const bool ehJogador1;
			float tempo;
			bool pulando;
			bool andando;

			
		public:

			Jogador(sf::Vector2f pos = { 0.f,0.f }, bool ehJogador1 = true);
			~Jogador();

			void executar(float dt);
			void inicializar();
			void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);
			void atacar(float dt);
			void desenharAtaque();
			void setPulando(bool p) { pulando = p; }
			bool getPulando() const { return pulando; }
			bool getAndando() const { return andando; }
			float getVelPulo() const;

			sf::FloatRect getHitBoxAtaque()const
			{ return (!podeAtacar ? ataque.getGlobalBounds() : sf::FloatRect()); }

		};


	}

}


