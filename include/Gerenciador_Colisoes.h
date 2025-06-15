#pragma once
#include "Entidade.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Obstaculo.h"
#include "Personagem.h"
#include "Inimigo.h"

namespace Gerenciadores {

	class Gerenciador_Colisoes
	{
	private:
		Lista::ListaEntidade* listaJogadores;
		Lista::ListaEntidade* listaObstaculos;
		Lista::ListaEntidade* listaInimigos;
	public:
		Gerenciador_Colisoes(Lista::ListaEntidade* listaJogadores, Lista::ListaEntidade* listaInimigos, Lista::ListaEntidade* listaObstaculos);
		~Gerenciador_Colisoes();

		//void setListaJogadores(Lista::ListaEntidade* lista) { if (lista) { listaJogadores = lista; } };
		//void setListaObstaculos(Lista::ListaEntidade* lista) { if (lista) { listaObstaculos = lista; } };
		//void setListaInimigos(Lista::ListaEntidade* lista);

		void verificarColisaoAtaque();

		void colidir();

		void colidirPersonagensComObstaculos();
		void colidirJogadoresComInimigos();

		void limpar();

	};


}

