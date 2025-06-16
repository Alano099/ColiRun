	#include "../include/Inimigo.h"

#include "../include/Animacao.h"

#include "../include/Jogador.h"

namespace Entidades {

	namespace Personagens {

		namespace Inimigos {


			Inimigo::Inimigo(sf::Vector2f pos)
				: Personagem(pos, sf::Vector2f(32.f, 63.f), IDs::IDs::nulo), // Ajuste o ID conforme necessário
				pJog(nullptr), perseguindo(0.f), sentido(1), tempoDano(0.f)
			{
				
			}


			Inimigo::~Inimigo() {}



		}

	}

}
