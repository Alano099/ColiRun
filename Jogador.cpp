#include "jogador.h"

#include "Animacao.h"

namespace Entidades {

	namespace Personagens {

		

		Jogador::Jogador(sf::Vector2f pos, bool ehJogador1):Personagem(pos, sf::Vector2f(39.0f, 96.0f), IDs::IDs::jogador,100),
			ehJogador1(ehJogador1)
		{
			inicializar();
			tempo = 0;
			velocidade.x = 100;
		}

		Jogador::~Jogador(){}

		

		void Jogador::atualizar(float dt) {

			tempo += dt;
							

			pos.x = pos.x + velocidade.x * dt;
			
			velocidade.y = 300 * dt + velocidade.y;

			pos.y = velocidade.y * dt + pos.y;

			olhandoEsquerda = velocidade.x >= 0.0f ? true : false;

			if (velocidade.x > 0) {
				sprite.atualizar(ElementosGraficos::ID_Animacao::andar, estaOlhandoEsquerda(), pos, dt);
			}

			else
				sprite.atualizar(ElementosGraficos::ID_Animacao::parado, estaOlhandoEsquerda(), pos, dt);

			
			


		}

		void Jogador::inicializar() {

			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/jogador_parado.png", 4);
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/jogador_andar.png", 6);
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::ataque, "assets/jogador_ataque.png", 6);
		}

		void Jogador::colidir(Entidade* outraEntidade, sf::Vector2f intercepta)
		{
			switch (outraEntidade->getID()) {
			case IDs::IDs::plataforma:
				moverNaColisao(intercepta, outraEntidade->getPosicao());
				break;

			default:

				break;
			}
		}

		

	}

}