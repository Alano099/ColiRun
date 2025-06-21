#pragma once

#include "Observer.h"

namespace Menus {
	class Menu;
}

namespace Observers {
	class MenuObserver: public Observer
	{
	private:
		Menus::Menu* pMenu;
	public:
		MenuObserver(Menus::Menu* pM = NULL);
		~MenuObserver();

		void notifyPressed(std::string key);

		void notifyReleased(std::string key);
		void setMenu(Menus::Menu* pM);

	};
}