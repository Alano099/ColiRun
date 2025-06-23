#pragma once
#include "Entidade.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Obstaculo.h"
#include "Personagem.h"
#include "Inimigo.h"
#include "Projetil.h"

namespace Gerenciadores {

	class Gerenciador_Colisoes
	{
	private:
		Lista::ListaEntidade* listaJogadores;
		Lista::ListaEntidade* listaObstaculos;
		Lista::ListaEntidade* listaInimigos;
		Lista::ListaEntidade* listaProjetil;
	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();

		void setListaJogadores(Lista::ListaEntidade* lista) { if (lista) { listaJogadores = lista; } };
		void setListaObstaculos(Lista::ListaEntidade* lista) { if (lista) { listaObstaculos = lista; } };
		void setListaInimigos(Lista::ListaEntidade* lista) { if (lista) { listaInimigos = lista; } };
		void setListaProjeteis(Lista::ListaEntidade* lista) { if (lista) { listaProjetil = lista; } };



		void verificarColisaoAtaque();

		void colidir();

		void colidirPersonagensComObstaculos();
		void colidirJogadoresComInimigos();
		void colidirJogadoresProjeteis();

		
			// Implementar lógica de colisão entre jogadores e projéteis
	
		void limpar();

	};


}

