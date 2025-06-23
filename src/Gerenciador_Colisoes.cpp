//adaptado em sua maioria de github.com/MatheusBurda/Desert

#include "../include/Gerenciador_Colisoes.h"



namespace Gerenciadores {



	Gerenciador_Colisoes::Gerenciador_Colisoes()
	{

	}

	Gerenciador_Colisoes::~Gerenciador_Colisoes()
	{
		listaObstaculos = NULL;
		listaJogadores = NULL;
	}

	void Gerenciador_Colisoes::verificarColisaoAtaque() {
		// =============== ATAQUE DO JOGADOR → INIMIGOS ===============
		for (int i = 0; i < listaJogadores->getTamanho(); i++) {
			auto* jogador = dynamic_cast<Entidades::Personagens::Jogador*>((*listaJogadores)[i]);
			if (!jogador) continue;

			sf::FloatRect hitboxAtaque = jogador->getHitBoxAtaque();

			// Se hitbox de ataque estiver vazia → não está atacando → skip
			if (hitboxAtaque == sf::FloatRect()) continue;

			for (int j = 0; j < listaInimigos->getTamanho(); j++) {
				auto* inimigo = dynamic_cast<Entidades::Personagens::Inimigos::Inimigo*>((*listaInimigos)[j]);
				if (!inimigo) continue;

				sf::FloatRect hitboxInimigo = inimigo->getHitbox();

				if (hitboxAtaque.intersects(hitboxInimigo) && inimigo->getTempoDano() <= 0.f) {

					// Só aplica se não estiver invulnerável
					if (inimigo->getTempoInvulneravel() <= 0.f) {

						std::cout << "Jogador acertou INIMIGO com ataque!\n";

						// Dano + empurrão
						float dano = 20.f;
						inimigo->tomarDano(dano);

						sf::Vector2f empurrao = !(jogador->estaOlhandoEsquerda())
							? sf::Vector2f(-300.f, -100.f)
							: sf::Vector2f(300.f, -100.f);

						inimigo->setVelocidade(empurrao);
						inimigo->setEmKnockback(true);
						inimigo->setTempoKnockback(0.4f);

					
						inimigo->setTempoInvulneravel(0.5f);
					}
				}
			}
		}

		// =============== ATAQUE DO INIMIGO → JOGADORES ===============
		for (int j = 0; j < listaInimigos->getTamanho(); j++) {
			auto* inimigo = dynamic_cast<Entidades::Personagens::Inimigos::Inimigo*>((*listaInimigos)[j]);
			if (!inimigo) continue;

			sf::FloatRect hitboxAtaque = inimigo->getAtaqueHitbox();
			if (!(inimigo->getAtacando())) continue; // se não estiver atacando

			for (int i = 0; i < listaJogadores->getTamanho(); i++) {
				auto* jogador = dynamic_cast<Entidades::Personagens::Jogador*>((*listaJogadores)[i]);
				if (!jogador) continue;

				sf::FloatRect hitboxJogador = jogador->getHitbox();
				if (hitboxAtaque.intersects(hitboxJogador)) {
					

					sf::Vector2f delta = inimigo->getPosicao() - jogador->getPosicao();

					// chama colidir passando delta como "direção"
					inimigo->colidirAtaque(jogador, delta);
				}
			}
		}
	}


	void Gerenciador_Colisoes::colidir()
	{
		colidirPersonagensComObstaculos();
		colidirJogadoresComInimigos();
		verificarColisaoAtaque();
		colidirJogadoresProjeteis();
		limpar();
	}


	void Gerenciador_Colisoes::colidirPersonagensComObstaculos()
	{
		for (int i = 0; i < listaObstaculos->getTamanho(); i++) {

			auto* obst = dynamic_cast<Entidades::Obstaculos::Obstaculo*>((*listaObstaculos)[i]);
			if (!obst)
				continue;

			// Primeiro: Jogadores
			for (int j = 0; j < listaJogadores->getTamanho(); j++) {

				Entidades::Personagens::Personagem* personagem = dynamic_cast<Entidades::Personagens::Personagem*>((*listaJogadores)[j]);
				if (!personagem)
					continue;

				sf::Vector2f distancia = personagem->getPosicao() - obst->getPosicao();
				sf::Vector2f intersecao;

				intersecao.x = fabs(distancia.x) - (personagem->getTamanho().x / 2.f + obst->getTamanho().x / 2.f);
				intersecao.y = fabs(distancia.y) - (personagem->getTamanho().y / 2.f + obst->getTamanho().y / 2.f);

				if (intersecao.x < 0.f && intersecao.y < 0.f) {
					obst->obstacular(personagem, intersecao);
				}
			}

			// Segundo: Inimigos
			for (int k = 0; k < listaInimigos->getTamanho(); k++) {

				Entidades::Personagens::Personagem* personagem = dynamic_cast<Entidades::Personagens::Personagem*>((*listaInimigos)[k]);
				if (!personagem)
					continue;

				sf::Vector2f distancia = personagem->getPosicao() - obst->getPosicao();
				sf::Vector2f intersecao;

				intersecao.x = fabs(distancia.x) - (personagem->getTamanho().x / 2.f + obst->getTamanho().x / 2.f);
				intersecao.y = fabs(distancia.y) - (personagem->getTamanho().y / 2.f + obst->getTamanho().y / 2.f);

				if (intersecao.x < 0.f && intersecao.y < 0.f) {
					obst->obstacular(personagem, intersecao);
				}
			}
		}
	}

	void Gerenciador_Colisoes::colidirJogadoresComInimigos() {
		
	}

	void Gerenciador_Colisoes::colidirJogadoresProjeteis()
	{
	
		if (listaProjetil == nullptr) return; // Se não tiver jogadores, não faz nada	

		for (int i = 0; i < listaProjetil->getTamanho(); i++) {
			auto* projetil = dynamic_cast<Entidades::Projetil*>((*listaProjetil)[i]);
			if (!projetil) continue;
			if (!projetil->getAtivo()) continue;

			for (int j = 0; j < listaJogadores->getTamanho(); j++) {
				auto* jogador = dynamic_cast<Entidades::Personagens::Jogador*>((*listaJogadores)[j]);
				if (!jogador) continue;

				sf::FloatRect hitboxProj = projetil->getHitbox();
				sf::FloatRect hitboxJog = jogador->getHitbox();

				if (hitboxProj.intersects(hitboxJog)) {
					std::cout << "PROJETIL acertou jogador!\n";
					// Aplica knockback no jogador
					sf::Vector2f empurrao = (jogador->getPosicao().x > projetil->getPosicao().x)
						? sf::Vector2f(50.f, 0.f)
						: sf::Vector2f(-50.f, 0.f);

					jogador->setVelocidade(empurrao);
					jogador->setEmKnockback(true);
					jogador->setTempoKnockback(0.4f);
					jogador->tomarDano(3.f); // Aplica dano
					// Desativa projetil
					projetil->setAtivo(false);
				}
			}
		}
		
	}
	

	void Gerenciador_Colisoes::limpar() {
		Entidades::Personagens::Personagem* pAux = NULL;

		for (int i = 0; i < listaJogadores->getTamanho(); i++) {
			pAux = static_cast<Entidades::Personagens::Personagem*>((*listaJogadores)[i]);

			if (pAux != nullptr) {
				if (!pAux->estaAtivo()) {
					listaJogadores->removerEnt(i);
					i--; // Ajusta o índice após remover um elemento
				}
			}
		}

		for (int i = 0; i < listaInimigos->getTamanho(); i++) {
			pAux = static_cast<Entidades::Personagens::Personagem*>((*listaInimigos)[i]);

			if (pAux != nullptr) {
				if (!pAux->estaAtivo()) {
					listaInimigos->removerEnt(i);
					i--;
				}
			}
		}

	}

}