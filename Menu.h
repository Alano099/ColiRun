#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Ente.h"
#include "Gerenciador_Eventos.h"
#include "MenuObserver.h"
#include "Botao.h"
#include "Texto.h"
#include "Estado.h"

namespace Menus
{
	class Menu : public Ente, public Estados::Estado
	{
	protected:
		const int Max_Botoes;
		std::vector<Botao*> Botoes;
		int selecionar_indice;
		sf::RectangleShape corpo;
		Texto titulo;
	public:
		Menu(int n_botoes = 0, int id = -1, std::string t = "0");
		~Menu();
		virtual void desenhar();
		void mCima();
		void mBaixo();
		virtual void selecionar() = 0;
		void executar();
		void mudarNome(std::string nome);
	};
}