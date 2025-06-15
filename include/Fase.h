#pragma once

#include <SFML/Graphics.hpp>


#include "Entidade.h"
#include "Jogador.h"
//#include "Inimigo.h"
#include "Plataforma.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estado.h"
#include "Estado.h"
#include "AnimacaoEstatica.h"


#include <fstream>
#include <string>
#include <iostream>

namespace Fases
{
	class Fase : public Ente
	{
	protected:

		Lista::ListaEntidade listaObstaculo;
		Lista::ListaEntidade listaInimigos;
		Lista::ListaEntidade listaJogadores;

		Gerenciadores::Gerenciador_Colisoes gerenciadorColisoes;
		Gerenciadores::Gerenciador_Eventos* gerenciador_Eventos;

		Entidades::Personagens::Jogador* p1;

		ElementosGraficos::AnimacaoEstatica fundo;

		//int nao_nasceu;
		//bool carregado;

		//sf::RectangleShape corpo;
	public:
		Fase(IDs::IDs id = IDs::IDs::nulo);
		~Fase();
		void executar();
		Entidades::Personagens::Jogador* getJogador() const;
		void desenhar();
		void atualizar(float dt);
		void inicializar();
		ElementosGraficos::AnimacaoEstatica getFundo()const;

		//void add_Obstaculo(Entidades::Entidade* obstaculo);
		//void add_Inimigo(Entidades::Entidade* inimigo);
		//void add_Jogador(Entidades::Entidade* Jogador);

		//virtual void save() = 0;
		//virtual void load() = 0;
		//virtual void reset() = 0;

		//Entidades::Entidade* criar_inimigo(std::ifstream& file);
		//void cria_cenario(std::string arquivo);
		//void carrega_cenario(std::string cenario);

	};
}