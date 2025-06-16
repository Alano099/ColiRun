#include "../include/Espinho.h"

namespace Entidades {

	namespace Obstaculos {

		Espinho::Espinho(sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(posicao, tamanho, IDs::IDs::espinho)
		{
			inicializar();
		}


		Espinho::~Espinho() {}

		void Espinho::atualizar(float dt) {
			sprite.atualizar(pos);
		}

		void Espinho::inicializar() {
			sprite.inicializar("assets/obstaculos/espinhos.png", pos, tam);
			
		}

		void Espinho::colidir(Entidade* outraEntidade, sf::Vector2f intercepta)
		{
		}

	}
}