#include "Personagem.h"
#include "Animacao.h"

namespace Entidades {

	namespace Personagens {
		Personagem::~Personagem()
		{
		}
		
		Personagem::Personagem(sf::Vector2f pos, bool jogador1) :
			Entidade(sf::Vector2f(PLAYER_SIZE_X, PLAYER_SIZE_Y)
			,pos,IDs::IDs::jogador),jogador1(jogador1)
		{
		
			inicializar();
			tempo = 0;
				
		}



		void Personagem::atualizar(float dt){
		
			tempo += dt;
			if (tempo < 3) {

				sprite.atualizar(ElementosGraficos::ID_Animacao::andar, true, pos, dt);
				pos.x = pos.x + 200 * dt;

			}

			else if (tempo < 6)
				sprite.atualizar(ElementosGraficos::ID_Animacao::parado, true, pos, dt);

			else
				sprite.atualizar(ElementosGraficos::ID_Animacao::ataque, true, pos, dt);

		}

		void Personagem::inicializar() {
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/jogador_parado.png", 4);
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/jogador_andar.png", 6);
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::ataque, "assets/jogador_ataque.png", 6);
		}

	}

}