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
				sentido = 1;
				perseguindo = false;
				tempoDano = 0.f;

			}

			Inimigo::~Inimigo() {}


			void Inimigo::atualizar(float dt) {
				if (tempoDano > 0.f)
					tempoDano -= dt;

				sf::Vector2f posJog = pJog->getPosicao();
				float distancia = std::hypot(posJog.x - pos.x, posJog.y - pos.y);

				if (distancia < 200.f) {
					perseguindo = true;

					sf::Vector2f dir = posJog - pos;
					float mag = std::sqrt(dir.x * dir.x + dir.y * dir.y);
					if (mag != 0.f) dir /= mag;

					velocidade.x = dir.x * 100.f;
					olhandoEsquerda = dir.x < 0;
				}
				else {
					perseguindo = false;

					velocidade.x = sentido * 60.f;
				}

				pos.x += velocidade.x * dt;
				velocidade.y += GRAVIDADE * dt;
				pos.y += velocidade.y * dt;

				if (!perseguindo && (pos.x > pontoDireita.x || pos.x < pontoEsquerda.x)) {
					sentido *= -1;

					if (pos.x > pontoDireita.x)
						pos.x = pontoDireita.x;
					else if (pos.x < pontoEsquerda.x)
						pos.x = pontoEsquerda.x;
				}

				sprite.atualizar(ElementosGraficos::ID_Animacao::andar, !(velocidade.x < 0.f), pos, dt);
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

				case IDs::IDs::jogador: {
					Jogador* jogador = dynamic_cast<Jogador*>(outraEntidade);
					if (jogador && jogador->getAtacando() && tempoDano <= 0.f) {
						std::cout << "ATAQUE COLIDIU!\n";
						moverNaColisao(intercepta, jogador->getPosicao());
						tempoDano = 0.5f;
					}
					break;
				}

				default:
					break;
				}
			}
			void Inimigo::definirLimitesDePatrulha(float alcance)
			{
				pontoEsquerda = sf::Vector2f(pos.x - alcance, pos.y);
				pontoDireita = sf::Vector2f(pos.x + alcance, pos.y);
			}


			void Inimigo::atacar(float dt){}

		}

	}

}
