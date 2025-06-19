#include "../include/lama.h"

namespace Entidades {

	namespace Obstaculos {

		Lama::Lama(sf::Vector2f posicao, sf::Vector2f tamanho, IDs::IDs id) :Obstaculo(posicao, tamanho, id) {
		
			inicializar();
		}

		Lama::~Lama() {}

		void Lama::executar(float dt) {
		
			sprite.executar(pos);
		
		}

		void Lama::inicializar() {
		
			sprite.inicializar("assets/obstaculos/lama.png", pos, tam);
		
		}

		void Lama::colidir(Entidade* outraEntidade, sf::Vector2f intercepta) {}

	}


}