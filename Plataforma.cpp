#include "plataforma.h"

namespace Entidades {

	namespace Obstaculos {


		Plataforma::Plataforma(sf::Vector2f posicao, sf::Vector2f tamanho):Obstaculo(posicao, tamanho, IDs::IDs::plataforma)
		{
			inicializar();
		}

		Plataforma::~Plataforma() {
		}
		
		void Plataforma::atualizar(float dt) {
			
			sprite.atualizar(pos);
		}

		void Plataforma::inicializar() {
			sprite.inicializar(PLATAFORMA_CAMINHO, pos, tam);
 // escala padrão

	

		}

		void Plataforma::colidir(Entidade* outraEntidade, sf::Vector2f intercepta)
		{
		}

	}

}