#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.h"
#include "Estado.h"

namespace Fases
{
	class Fase;
}

namespace Menus
{
	class MainMenu : public Menu, public Estados::Estado
	{
	private:
		Fases::Fase* pFase;
		Menus::Texto* titulo;
	public:
		MainMenu(Fases::Fase* pF = nullptr);
		~MainMenu();
		void Atualizar(const float dt);

		void renderizar();

		void resetaEstado();

		void exec();
	};
}
