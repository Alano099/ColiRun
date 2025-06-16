#pragma once
#include "Entidade.h"
#include "AnimacaoEstatica.h"
#include "../IDs/IDs.h"

namespace Entidades {

	namespace Obstaculos {

		class Obstaculo : public Entidade
		{
		protected:
			ElementosGraficos::AnimacaoEstatica sprite;
			bool danoso;

		public:
			Obstaculo(sf::Vector2f posicao, sf::Vector2f tamanho,IDs::IDs id);
			~Obstaculo();

			void desenhar();

			virtual void executar(float dt) = 0;
			virtual void inicializar() = 0;
			virtual void colidir(Entidade* outraEntidade, sf::Vector2f intercepta) = 0;

			sf::Vector2f getPosicao()const;



		};
	}




}
