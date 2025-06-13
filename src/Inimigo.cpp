	#include "../include/Inimigo.h"

#include "../include/Animacao.h"

#include "../include/Jogador.h"

namespace Entidades {

	namespace Personagens {

		namespace Inimigos {


			Inimigo::Inimigo(sf::Vector2f pos) :Personagem(pos, sf::Vector2f(JOGADOR_TAMANHO_X, JOGADOR_TAMANHO_Y), IDs::IDs::inimigo, 100)
			{

				inicializar();
				velocidade.x = 100;
				sentido = -1;
				perseguindo = false;

			}

			Inimigo::~Inimigo() {}


			void Inimigo::atualizar(float dt) {

				sf::Vector2f posJog = pJog->getPosicao();
				float distancia = std::hypot(posJog.x - pos.x, posJog.y - pos.y);

				// Persegue se estiver perto
				if (distancia < 200.f) {
					perseguindo = true;
					sf::Vector2f dir = posJog - pos;
					float mag = std::sqrt(dir.x * dir.x + dir.y * dir.y);
					if (mag != 0.f) dir /= mag;
					velocidade.x = dir.x * 100.f;
					olhandoEsquerda = dir.x < 0;
				}
				// Caso contrário, patrulha
				else {
					perseguindo = false;
					velocidade.x = sentido * 60.f;
					if (pos.x > pontoDireita.x || pos.x < pontoEsquerda.x) {
						sentido *= -1;
					}
				}

				pos.x += velocidade.x * dt;
				velocidade.y += GRAVIDADE * dt;
				pos.y += velocidade.y * dt;

				if (perseguindo)
					sprite.atualizar(ElementosGraficos::ID_Animacao::andar, !olhandoEsquerda, pos, dt);
				else
					sprite.atualizar(ElementosGraficos::ID_Animacao::parado, !olhandoEsquerda, pos, dt);

			}

			void Inimigo::inicializar() {

				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/inimigos/soldado_andar.png", 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/inimigos/soldado_parado.png", 3);
			}

			void Inimigo::colidir(Entidade* outraEntidade, sf::Vector2f intercepta) {
				switch (outraEntidade->getID()) {
				case IDs::IDs::plataforma:
					moverNaColisao(intercepta, outraEntidade->getPosicao());
					break;

				default:

					break;
				}

			}

			void Inimigo::definirLimitesDePatrulha(float alcance)
			{
				pontoEsquerda = sf::Vector2f(pos.x - alcance, pos.y);
				pontoDireita = sf::Vector2f(pos.x + alcance, pos.y);
			}


		}

	}

}
