#pragma once
#include "Entidade.h"
#include "AnimacaoEstatica.h"
#include "IDs/IDs.h"

namespace Entidades {

	namespace Obstaculos {

		class Obstaculo : public Entidade
		{
		protected:
			ElementosGraficos::AnimacaoEstatica sprite;

		public:
			Obstaculo(sf::Vector2f posicao = { 0.f,0.f }, sf::Vector2f tamanho = {0.f,0.f}, IDs::IDs id = IDs::IDs::nulo);
			~Obstaculo();

			void desenhar();

			virtual void atualizar(float dt) = 0;
			virtual void inicializar() = 0;
			virtual void colidir(Entidade* outraEntidade, sf::Vector2f intercepta) = 0;

			sf::Vector2f getPosicao()const;



		};
	}




}
