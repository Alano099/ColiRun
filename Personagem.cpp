#include "Personagem.h"

namespace Entidades {

	namespace Personagens {
		Personagem::~Personagem()
		{
		}
		
		Personagem::Personagem(sf::Vector2f pos, bool jogador1) :Entidade(sf::Vector2f(PLAYER_SIZE_X, PLAYER_SIZE_Y),pos,IDs::IDs::jogador),jogador1(jogador1){}

		void Personagem::atualizar(float dt){ }

		void Personagem::inicializar() {
			exit(1);
		}

	}

}