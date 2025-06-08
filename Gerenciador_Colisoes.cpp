#include "Gerenciador_Colisoes.h"

#include "Personagem.h"
#include "Obstaculo.h"

namespace Gerenciadores {



	Gerenciador_Colisoes::Gerenciador_Colisoes(Lista::ListaEntidade* listaPersonagens, Lista::ListaEntidade* listaObstaculos):listaPersonagens(listaPersonagens),
		listaObstaculos(listaObstaculos)
	{

	}

	Gerenciador_Colisoes::~Gerenciador_Colisoes()
	{
		listaObstaculos = NULL;
		listaPersonagens = NULL;
	}

	void Gerenciador_Colisoes::colidir()
	{

		Entidades::Entidade* ent1 = NULL;
		Entidades::Entidade* ent2 = NULL;

		sf::Vector2f intercepta;
		sf::Vector2f distanciaCentro;

		int i, j;

		for (i = 0; i < listaObstaculos->getTamanho(); i++) {
			for (j = 0; j < listaPersonagens->getTamanho(); j++) {
				ent1 = (*listaObstaculos)[i];
				ent2 = (*listaPersonagens)[j];

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
			for (j = 0; j < listaPersonagens->getTamanho(); j++) {

				ent1 = (*listaObstaculos)[i];
				ent2 = (*listaPersonagens)[j];


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

		for (int i = 0; i < listaPersonagens->getTamanho(); i++) {
			pAux = static_cast<Entidades::Personagens::Personagem*>((*listaPersonagens)[i]);

			if (pAux != nullptr) {
				if (!pAux->estaAtivo()) {
					listaPersonagens->removerEnt(i);
					i--; // Ajusta o índice após remover um elemento
				}
			}
		}
	}

}