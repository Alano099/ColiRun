#include "../include/lama.h"

namespace Entidades {

	namespace Obstaculos {

		Lama::Lama(sf::Vector2f posicao, sf::Vector2f tamanho, IDs::IDs id) :Obstaculo(posicao, tamanho, id), cfDesacelerar(0.1) {
		
			inicializar();
		}

		Lama::~Lama() {}

		void Lama::executar(float dt) {
		
			sprite.executar(pos);
		
		}

		void Lama::inicializar() {
		
			sprite.inicializar("assets/obstaculos/lama.png", pos, tam);
		
		}

		void Lama::obstacular(Entidade* outraEntidade, sf::Vector2f intercepta)
		{
			if (outraEntidade->getID() == IDs::IDs::jogador) {
				auto* jogador = dynamic_cast<Entidades::Personagens::Jogador*>(outraEntidade);
				if (jogador) {
					if (jogador->getAndando()) {
						sf::Vector2f vel = jogador->getVelocidade();

						
						const float MAX_VEL_LAMA = 50.f; 

						if (vel.x > MAX_VEL_LAMA)
							vel.x = MAX_VEL_LAMA;
						else if (vel.x < -MAX_VEL_LAMA)
							vel.x = -MAX_VEL_LAMA;

						jogador->setVelocidade(vel);

						
					}
				}
			}
		}



	}


}