#include "../include/Gerenciador_Colisoes.h"



namespace Gerenciadores {



	Gerenciador_Colisoes::Gerenciador_Colisoes(Lista::ListaEntidade* listaJogadores,Lista::ListaEntidade* listaInimigos, Lista::ListaEntidade* listaObstaculos):listaJogadores(listaJogadores),
		listaInimigos(listaInimigos),listaObstaculos(listaObstaculos)
	{

	}

	Gerenciador_Colisoes::~Gerenciador_Colisoes()
	{
		listaObstaculos = NULL;
		listaJogadores = NULL;
	}

	void Gerenciador_Colisoes::verificarColisaoAtaque() {
		for (int i = 0; i < listaJogadores->getTamanho(); i++) {
			auto* jogador = dynamic_cast<Entidades::Personagens::Jogador*>((*listaJogadores)[i]);
			if (!jogador) continue;

			sf::FloatRect hitboxAtaque = jogador->getHitBoxAtaque();
			if (hitboxAtaque == sf::FloatRect()) continue;

			for (int j = 0; j < listaInimigos->getTamanho(); j++) {
				auto* inimigo = dynamic_cast<Entidades::Personagens::Inimigos::Inimigo*>((*listaInimigos)[j]);
				if (!inimigo) continue;

				sf::FloatRect hitboxInimigo = inimigo->getHitbox();
				if (hitboxAtaque.intersects(hitboxInimigo)) {
					
					// Aplica o "empurrão"
					sf::Vector2f empurrao = jogador->estaOlhandoEsquerda()
						? sf::Vector2f(-100.f, 0.f)
						: sf::Vector2f(100.f, 0.f);
					inimigo->moverNaColisao(empurrao, inimigo->getPosicao());
				}
			}
		}
	}

	void Gerenciador_Colisoes::colidir()
	{
		colidirPersonagensComObstaculos();
		colidirJogadoresComInimigos();
		verificarColisaoAtaque();
		limpar();
	}


	void Gerenciador_Colisoes::colidirJogadoresComInimigos() {
		Entidades::Entidade* jogador;
		Entidades::Entidade* inimigo;
		sf::Vector2f distancia, intersecao;

		for (int i = 0; i < listaJogadores->getTamanho(); i++) {
			jogador = (*listaJogadores)[i];
			for (int j = 0; j < listaInimigos->getTamanho(); j++) {
				inimigo = (*listaInimigos)[j];

				distancia = jogador->getPosicao() - inimigo->getPosicao();
				intersecao.x = abs(distancia.x) - (jogador->getTamanho().x / 2 + inimigo->getTamanho().x / 2);
				intersecao.y = abs(distancia.y) - (jogador->getTamanho().y / 2 + inimigo->getTamanho().y / 2);

				if (intersecao.x < 0.f && intersecao.y < 0.f) {
					jogador->colidir(inimigo, intersecao);
					inimigo->colidir(jogador, intersecao);
				}
			}
		}
	}
	void Gerenciador_Colisoes::colidirPersonagensComObstaculos() {
		Entidades::Entidade* obst;
		Entidades::Entidade* personagem;
		sf::Vector2f distancia, intersecao;

		for (int i = 0; i < listaObstaculos->getTamanho(); i++) {
			obst = (*listaObstaculos)[i];

			for (int j = 0; j < listaJogadores->getTamanho(); j++) {
				personagem = (*listaJogadores)[j];

				distancia = personagem->getPosicao() - obst->getPosicao();
				intersecao.x = abs(distancia.x) - (personagem->getTamanho().x / 2 + obst->getTamanho().x / 2);
				intersecao.y = abs(distancia.y) - (personagem->getTamanho().y / 2 + obst->getTamanho().y / 2);

				if (intersecao.x < 0.f && intersecao.y < 0.f) {
					personagem->colidir(obst, intersecao);
				}
			}

			for (int j = 0; j < listaInimigos->getTamanho(); j++) {
				personagem = (*listaInimigos)[j];

				distancia = personagem->getPosicao() - obst->getPosicao();
				intersecao.x = abs(distancia.x) - (personagem->getTamanho().x / 2 + obst->getTamanho().x / 2);
				intersecao.y = abs(distancia.y) - (personagem->getTamanho().y / 2 + obst->getTamanho().y / 2);

				if (intersecao.x < 0.f && intersecao.y < 0.f) {
					personagem->colidir(obst, intersecao);
				}
			}
		}
	}


	/*
	
	
	void Gerenciador_Colisoes::colidir()
	{

		Entidades::Entidade* ent1 = NULL;
		Entidades::Entidade* ent2 = NULL;

		sf::Vector2f intercepta;
		sf::Vector2f distanciaCentro;

		int i, j;

		for (i = 0; i < listaObstaculos->getTamanho(); i++) {
			for (j = 0; j < listaJogadores->getTamanho(); j++) {
				

					ent1 = (*listaObstaculos)[i];
					ent2 = (*listaJogadores)[j];

					distanciaCentro.x = ent2->getPosicao().x - ent1->getPosicao().x;
					distanciaCentro.y = ent2->getPosicao().y - ent1->getPosicao().y;

					intercepta.x = abs(distanciaCentro.x) - (ent1->getTamanho().x / 2 + ent2->getTamanho().x / 2);
					intercepta.y = abs(distanciaCentro.y) - (ent1->getTamanho().y / 2 + ent2->getTamanho().y / 2);

					if (intercepta.x < 0.0f && intercepta.y < 0.0f) {
						ent2->colidir(ent1, intercepta);
					}


				
			}


		}

		for (i = 0; i < listaObstaculos->getTamanho(); i++) {
			for (j = 0; j < listaJogadores->getTamanho(); j++) {
				


					ent1 = (*listaObstaculos)[i];
					ent2 = (*listaJogadores)[j];


					distanciaCentro.x = ent2->getPosicao().x - ent1->getPosicao().x;
					distanciaCentro.y = ent2->getPosicao().y - ent1->getPosicao().y;

					intercepta.x = abs(distanciaCentro.x) - (ent1->getTamanho().x / 2 + ent2->getTamanho().x / 2);
					intercepta.y = abs(distanciaCentro.y) - (ent1->getTamanho().y / 2 + ent2->getTamanho().y / 2);

					if (intercepta.x < 0.0f && intercepta.y < 0.0f) {
				
						cout << "COLIDIU" << endl;
						ent2->colidir(ent1, intercepta);
						ent1->colidir(ent1, intercepta);
					}

				

			}


		}

		verificarColisaoAtaque();

		limpar();

	}
	*/

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
	}

}