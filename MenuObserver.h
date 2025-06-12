#pragma once

#include "Observer.h"

namespace Menus {
	class MainMenu;
}

namespace Observers {
	class MenuObserver: public Observer
	{
	private:
		Menus::MainMenu* pMenu;
	public:
		MenuObserver();
		~MenuObserver();

		void atualizar(sf::Keyboard::Key key_code);
		void setMenu(Menus::MainMenu* pM) { pMenu = pM; }

	};
}