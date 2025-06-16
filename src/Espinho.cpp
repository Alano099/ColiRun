#include "../include/Espinho.h"

namespace Entidades {

	namespace Obstaculos {

		Espinho::Espinho(sf::Vector2f posicao, sf::Vector2f tamanho, IDs::IDs id) : Obstaculo(posicao, tamanho,id)
		{
			inicializar();
		}


		Espinho::~Espinho() {}

		void Espinho::executar(float dt) {
			sprite.executar(pos);
		}

		void Espinho::inicializar() {
			sprite.inicializar("assets/obstaculos/espinhos.png", pos, tam);
			
		}

		void Espinho::colidir(Entidade* outraEntidade, sf::Vector2f intercepta)
		{
		}

	}
}