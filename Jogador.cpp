#include "jogador.h"

#include "Animacao.h"

namespace Entidades {

	namespace Personagens {

		

		Jogador::Jogador(sf::Vector2f pos, bool ehJogador1):Personagem(pos, sf::Vector2f(JOGADOR_TAMANHO_X, JOGADOR_TAMANHO_Y), IDs::IDs::jogador,100),
			ehJogador1(ehJogador1)
		{
			inicializar();
			tempo = 0;
			velocidade.x = 100;
		}

		Jogador::~Jogador(){}

		

		void Jogador::atualizar(float dt) {

			tempo += dt;

			// Zera a velocidade horizontal
			velocidade.x = 0.f;

			// Movimento horizontal com teclado
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				velocidade.x = +200.f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				velocidade.x = -200.f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				velocidade.y = -200.f;
			}
			// Atualiza posição com velocidade
			pos.x += velocidade.x * dt;

			
			velocidade.y += 300 * dt;
			pos.y += velocidade.y * dt;

			// Atualiza animação
			if (velocidade.x > 0.f) {
				olhandoEsquerda = true;
				sprite.atualizar(ElementosGraficos::ID_Animacao::andar, estaOlhandoEsquerda(), pos, dt);
			}
			else if (velocidade.x < 0.0f) {
				olhandoEsquerda = false;
				sprite.atualizar(ElementosGraficos::ID_Animacao::andar, estaOlhandoEsquerda(), pos, dt);
			}

			else {
				
				sprite.atualizar(ElementosGraficos::ID_Animacao::parado, estaOlhandoEsquerda(), pos, dt);
			}

		}

		void Jogador::inicializar() {

			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/jogador_parado.png", 4);
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/jogador_andar.png", 6);
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::ataque, "assets/jogador_ataque.png", 6);
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::pulo, "assets/jogador_pulo.png", 3);
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