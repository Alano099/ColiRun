#include "Gerenciador_Colisoes.h"



namespace Gerenciadores {



	Gerenciador_Colisoes::Gerenciador_Colisoes(Lista::ListaEntidade* listaJogadores, Lista::ListaEntidade* listaObstaculos):listaJogadores(listaJogadores),
		listaObstaculos(listaObstaculos)
	{

	}

	Gerenciador_Colisoes::~Gerenciador_Colisoes()
	{
		listaObstaculos = NULL;
		listaJogadores = NULL;
	}

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

		limpar();

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
	}

}