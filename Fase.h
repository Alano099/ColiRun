#pragma once

#define WIDTH 800
#define HEIGHT 600

#include <SFML/Graphics.hpp>


#include "Entidade.h"
#include "Personagem.h"
#include "ListaEntidades.h"
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
		Lista::ListaEntidade Personagens;


		Gerenciadores::Gerenciador_Eventos* gerenciador_Eventos;

		int nao_nasceu;
		bool carregado;

		sf::RectangleShape corpo;
	public:
		Fase(int id = -1);
		virtual ~Fase();
		void virtual executa() = 0;
		void desenha();

		
		void add_Jogador(Entidades::Entidade* player);

		virtual void save() = 0;
		virtual void load() = 0;
		virtual void reset() = 0;

		
		void cria_cenario(std::string file, std::string save);
		void carrega_cenario(std::string save_scenario_file);

	};
}