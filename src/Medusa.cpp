#include "../include/Medusa.h"

namespace Entidades {

	namespace Personagens{

		namespace Inimigos {



			Medusa::Medusa(sf::Vector2f pos,sf::Vector2f tamanho, IDs::IDs id):Inimigo(pos,tamanho,id)
			{
				inicializar();
			}

			Medusa::~Medusa()
			{
			}

			void Medusa::executar(float dt)
			{
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

			void Medusa::inicializar()
			{
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/inimigos/medusa/medusa_andar.png", 13);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/inimigos/medusa/medusa_parado.png", 7);
			}

			void Medusa::colidir(Entidade* outraEntidade, sf::Vector2f intercepta)
			{
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

			void Medusa::atacar(float dt)
			{
			}

			void Medusa::definirLimitesDePatrulha(float alcance)
			{
				pontoEsquerda = sf::Vector2f(pos.x - alcance, pos.y);
				pontoDireita = sf::Vector2f(pos.x + alcance, pos.y);
			}

		}

	}

}