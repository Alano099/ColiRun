#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Ente.h"
#include "Gerenciador_Eventos.h"
#include "MenuObserver.h"
#include "Botao.h"


namespace Menus
{
	class Menu : public Ente
	{
	protected:
		std::vector<Botao*> vectorBotao;
		std::vector<Botao*>::iterator it;
		int selecionar;
		int min;
		int max;

		Observers::MenuObserver menuOb;
		bool ativado;
		
	public:
		Menu();
		virtual ~Menu();
		virtual void exec() = 0;
		void atualizarView();
		void selecionarBaixo();
		void selecionarCima();
	};
}