#include "../include/plataforma.h"

namespace Entidades {

	namespace Obstaculos {


		Plataforma::Plataforma(sf::Vector2f posicao, sf::Vector2f tamanho,IDs::IDs id):Obstaculo(posicao, tamanho,id)
		{
			inicializar();
		}

		Plataforma::~Plataforma() {
		}
		
		void Plataforma::executar(float dt) {
			
			sprite.executar(pos);
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