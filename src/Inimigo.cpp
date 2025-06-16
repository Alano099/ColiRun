	#include "../include/Inimigo.h"

#include "../include/Animacao.h"

#include "../include/Jogador.h"

namespace Entidades {

	namespace Personagens {

		namespace Inimigos {


			Inimigo::Inimigo(sf::Vector2f pos,sf::Vector2f tamanho, IDs::IDs id)
				: Personagem(pos,tamanho,id),
				pJog(nullptr), perseguindo(0.f), sentido(1), tempoDano(0.f)
			{
				
			}


			Inimigo::~Inimigo() {}



		}

	}

}
