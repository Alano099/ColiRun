#include "../include/Jogador.h"

#include "../include/Animacao.h"

namespace Entidades {

	namespace Personagens {

		

		Jogador::Jogador(sf::Vector2f pos, bool ehJogador1) :Personagem(pos, sf::Vector2f(JOGADOR_TAMANHO_X, JOGADOR_TAMANHO_Y), IDs::IDs::jogador, 100),
			ehJogador1(ehJogador1), pulando(false), andando(false)
		{
			inicializar();
			tempo = 0;
			velocidade.x = 100;
			noChao = true;
			podeAtacar = true;
			tempoAtaque = 0.f;
			ataqueCooldown = 0.0f;
		}

		Jogador::~Jogador(){}

		

		void Jogador::executar(float dt) {

			if (ehJogador1)
			{
				tempo += dt;

				andando = false;

				float velPulo = getVelPulo();


				velocidade.y += GRAVIDADE * dt;


				

				if (emKnockback) {
					tempoKnockback -= dt;
					if (tempoKnockback <= 0.f) {
						emKnockback = false;
						velocidade.x = 0.f;
					}
				}

				else {

					velocidade.x = 0.f;

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						velocidade.x = +200.f;
						andando = true;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						velocidade.x = -200.f;
						andando = true;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && noChao) {
						velocidade.y = -velPulo;
						noChao = false;
						pulando = true;
					}

				}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
						if (!estaAtacando && podeAtacar && ataqueCooldown <= 0.f) {
							atacar(dt);
							estaAtacando = true;
							ataqueCooldown = 0.5f;  // cooldown de meio segundo
						}
					}
					else {
						estaAtacando = false;
					}
				
				

					// Atualiza posi��o com velocidade
					pos.x += velocidade.x * dt;

					pos.y += velocidade.y * dt;

					if (pos.y >= CHAO) {
						pos.y = CHAO;
						velocidade.y = 0.f;
						noChao = true;
						pulando = false;
					}
				

					if (!podeAtacar) {


						if (olhandoEsquerda) {
							ataque.setPosition(pos.x + 30.f, pos.y - 20.f);
						}
						else {
							ataque.setPosition(pos.x - 30.f, pos.y - 20.f);
						}
					}

					if (ataqueCooldown > 0.f)
						ataqueCooldown -= dt;

					// Atualiza anima��o

					if (!podeAtacar) {
						tempoAtaque -= dt;
						sprite.atualizar(ElementosGraficos::ID_Animacao::ataque, estaOlhandoEsquerda(), pos, dt);
						if (tempoAtaque <= 0.f) podeAtacar = true;
					}
					else {
						if (emKnockback) {
							sprite.atualizar(ElementosGraficos::ID_Animacao::dano, estaOlhandoEsquerda(), pos, dt);
						}
						else if (velocidade.x > 0.f && noChao) {
							olhandoEsquerda = true;
							sprite.atualizar(ElementosGraficos::ID_Animacao::andar, estaOlhandoEsquerda(), pos, dt);
						}
						else if (velocidade.x < 0.0f && noChao) {
							olhandoEsquerda = false;
							sprite.atualizar(ElementosGraficos::ID_Animacao::andar, estaOlhandoEsquerda(), pos, dt);
						}
						else if (pulando) {
							sprite.atualizar(ElementosGraficos::ID_Animacao::pulo, estaOlhandoEsquerda(), pos, dt);
						}
						else {
							sprite.atualizar(ElementosGraficos::ID_Animacao::parado, estaOlhandoEsquerda(), pos, dt);
						}
					}
				
				

			}
			if (!ehJogador1)
			{
				tempo += dt;

				float tempoPulo = 1.f;

				float alturaPulo = ((tempoPulo * tempoPulo) * GRAVIDADE) / 5;
				float velPulo = sqrt(2 * GRAVIDADE * alturaPulo);


				velocidade.y += GRAVIDADE * dt;


				if (emKnockback) {
					tempoKnockback -= dt;
					if (tempoKnockback <= 0.f) {
						emKnockback = false;
						velocidade.x = 0.f;
					}
				}

				else {

					velocidade.x = 0.f;

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						velocidade.x = +200.f;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
						velocidade.x = -200.f;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && noChao) {
						velocidade.y = -velPulo;
						noChao = false;
						pulando = true;
					}

				}

				// Movimento horizontal com teclado
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					if (!estaAtacando && podeAtacar && ataqueCooldown <= 0.f) {
						atacar(dt);
						estaAtacando = true;
						ataqueCooldown = 0.5f;  // cooldown de meio segundo
					}
				}
				else {
					estaAtacando = false;
				}


				// Atualiza posi��o com velocidade
				pos.x += velocidade.x * dt;

				pos.y += velocidade.y * dt;



				if (pos.y >= CHAO) {
					pos.y = CHAO;
					velocidade.y = 0.f;
					noChao = true;
					pulando = false;
				}
				

				if (!podeAtacar) {


					if (olhandoEsquerda) {
						ataque.setPosition(pos.x + 30.f, pos.y - 20.f);
					}
					else {
						ataque.setPosition(pos.x - 30.f, pos.y - 20.f);
					}
				}

				if (ataqueCooldown > 0.f)
					ataqueCooldown -= dt;

				// Atualiza anima��o

				if (!podeAtacar) {
					tempoAtaque -= dt;
					sprite.atualizar(ElementosGraficos::ID_Animacao::ataque, estaOlhandoEsquerda(), pos, dt);
					if (tempoAtaque <= 0.f) podeAtacar = true;
				}
				else {

					if (emKnockback) {
						sprite.atualizar(ElementosGraficos::ID_Animacao::dano, estaOlhandoEsquerda(), pos, dt);
					}

					else if (velocidade.x > 0.f && noChao) {
						olhandoEsquerda = true;
						sprite.atualizar(ElementosGraficos::ID_Animacao::andar, estaOlhandoEsquerda(), pos, dt);
					}
					else if (velocidade.x < 0.0f && noChao) {
						olhandoEsquerda = false;
						sprite.atualizar(ElementosGraficos::ID_Animacao::andar, estaOlhandoEsquerda(), pos, dt);
					}
					else if (pulando) {
						sprite.atualizar(ElementosGraficos::ID_Animacao::pulo, estaOlhandoEsquerda(), pos, dt);
					}
					else {
						sprite.atualizar(ElementosGraficos::ID_Animacao::parado, estaOlhandoEsquerda(), pos, dt);
					}
				}




			}



		}

		void Jogador::inicializar() {

			if (ehJogador1)
			{
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/jogador/jogador_parado.png", 4);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/jogador/jogador_andar.png", 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::ataque, "assets/jogador/jogador_ataque.png", 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::pulo, "assets/jogador/jogador_pulo.png", 3);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::dano, "assets/jogador/jogador_machucado.png", 7);
			}
			if (!ehJogador1)
			{
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/jogador/jogador2_parado.png", 4);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/jogador/jogador2_andar.png", 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::ataque, "assets/jogador/jogador2_ataque.png", 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::pulo, "assets/jogador/jogador2_pulo.png", 3);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::dano, "assets/jogador/jogador_machucado.png", 7);
			}
		}

		void Jogador::colidir(Entidade* outraEntidade, sf::Vector2f intercepta)
		{
			
		}

		void Jogador::atacar(float dt)
		{
			podeAtacar = false;
			tempoAtaque = 0.7f;

			ataque.setSize(sf::Vector2f(15.f, 15.f));

		
		}

		void Jogador::desenharAtaque()
		{
			if (!podeAtacar) {
				ataque.setFillColor(sf::Color::Transparent);
				ataque.setOutlineColor(sf::Color::Red);
				ataque.setOutlineThickness(1.f);
				Gerenciadores::Gerenciador_Grafico::get_instance()->getJanela()->draw(ataque);
			}
		}

		float Jogador::getVelPulo() const
		{
			float tempoPulo = 1.f;
			float alturaPulo = ((tempoPulo * tempoPulo) * GRAVIDADE) / 10;
			return sqrt(2 * GRAVIDADE * alturaPulo);
		}

	
		

	}

}