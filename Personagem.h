#pragma once
#include "Entidade.h"

#define PLAYER_SIZE_X 100.f
#define PLAYER_SIZE_Y 100.f

namespace Entidades {

	namespace Personagens {

	class Personagem :public Entidade
	{
	protected:
		const bool jogador1;
		
	public:

		~Personagem();

		Personagem(sf::Vector2f pos = {0.f,0.f},bool jogador1 = true);

		void atualizar(float dt);

		void inicializar();

	};



	}
}

