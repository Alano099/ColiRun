#pragma once

#define WIDTH 800
#define HEIGHT 600

#include <SFML/Graphics.hpp>


#include "Entidade.h"
//#include "Jogador.h"
//#include "Inimigo.h"
//#include "Plataforma.h"
#include "ListaEntidades.h"
//#include "Gerenciador_Colisao.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estado.h"
#include "Estado.h"


#include <fstream>
#include <string>
#include <iostream>

namespace Fases
{
	class Fase : public Ente, public Estados::Estado
	{
	protected:
		
		//Lista::ListaEntidade* obstaculos;
		//Lista::ListaEntidade* inimigos;
		Lista::ListaEntidade* jogadores;

		//Gerenciadores::Gerenciador_Colisao* gerenciador_Colisoes;
		Gerenciadores::Gerenciador_Eventos* gerenciador_Eventos;

		int nao_nasceu;
		bool carregado;

		sf::RectangleShape corpo;
	public:
		Fase(int id = -1);
		virtual ~Fase();
		void virtual executa() = 0;
		void desenha();

		//void add_Obstaculo(Entidades::Entidade* obstaculo);
		//void add_Inimigo(Entidades::Entidade* inimigo);
		void add_Jogador(Entidades::Entidade* player);

		//virtual void save() = 0;
		//virtual void load() = 0;
		//virtual void reset() = 0;

		//Entidades::Entidade* criar_inimigo(std::ifstream& file);
		void cria_cenario(std::string file, std::string save);
		void carrega_cenario(std::string save_scenario_file);

	};
}