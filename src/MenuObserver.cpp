#include "../include/MenuObserver.h"
#include "../include/Menu.h"

namespace Observers {
	MenuObserver::MenuObserver(Menus::Menu* pM) : Observer()
	{
		pMenu = pM;
	}
	MenuObserver::~MenuObserver()
	{
		pMenu = NULL;
	}

    void MenuObserver::notifyPressed(std::string key) {
        if (pMenu == NULL) {
            std::cout << "ERROR pointer to Menu NULL on MenuControl::notify()." << std::endl;
            exit(1);
        }

        if (key == "Down")
            pMenu->selecionarBaixo();
        if (key == "Up")
            pMenu->selecionarCima();
        if (key == "Enter")
            pMenu->exec();
   
           
    }

    void MenuObserver::notifyReleased(std::string key) {}
	void MenuObserver::setMenu(Menus::Menu* p) 
	{
		pMenu = p;
	}
}