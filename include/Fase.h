#pragma once
#include "Inimigo.h"
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
#include "Soldado.h"
#include "Medusa.h"
#include "Minotauro.h"
#include "Espinho.h"
#include "Lama.h"


#include <fstream>
#include <string>
#include <iostream>
#include "Fundo.h"

#define MAX_INIMIGOS 6
#define TAMANHO_TILE 86.f
#define TAMANHO_PLATAFORMA_X 100.f
#define TAMANHO_PLATAFORMA_Y 80.f



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
		Entidades::Personagens::Jogador* p2;

		ElementosGraficos::Fundo fundo;

		float mapaLargura;
		float mapaAltura;

		sf::RectangleShape chao;

		//int nao_nasceu;
		//bool carregado;

		//sf::RectangleShape corpo;
	public:
		Fase(IDs::IDs id = IDs::IDs::nulo);
		~Fase();

		void executar(float dt);
		void desenhar();
		void atualizar(float dt);
		virtual void inicializar() = 0;
		virtual void carregarMapa(const std::string& caminho) = 0;

	
		Entidades::Personagens::Jogador* getJogador() const;
		

		void criarPlataformas(sf::Vector2f pos, sf::Vector2f tam);
		void criarSoldados(sf::Vector2f pos);

		virtual void criarInimigos() = 0;
		virtual void criarObstaculos() = 0;


		float getMapaLargura() const { return mapaLargura; }
		float getMapaAltura() const { return mapaAltura; }

		void gerenciar_colisoes();

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