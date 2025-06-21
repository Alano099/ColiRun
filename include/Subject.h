#pragma once
#include <list>
#include <map>
#include "Gerenciador_Grafico.h"

namespace Observers {
	class Observer;
}

namespace Gerenciadores {
	class Subject {
	private:
		std::list<Observers::Observer*> lista_observers;
		std::list<Observers::Observer*>::iterator it;

		std::map<sf::Keyboard::Key, std::string> keyMap;

		static Subject* instance;
		Subject();
	public:
		
		virtual ~Subject();
		static Subject* get_instance();

		virtual void detach(Observers::Observer* pObserver);
		virtual void attach(Observers::Observer* pObserver);
		void handleKeyPressed(sf::Keyboard::Key key);

		void handleKeyReleased(sf::Keyboard::Key key);

		std::string getKeyasString(sf::Keyboard::Key key);
	};
}