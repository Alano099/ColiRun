#include "../include/Gerenciador_Eventos.h"
#include "../include/Observer.h"

namespace Gerenciadores {
	Gerenciador_Eventos* Gerenciador_Eventos::instance = nullptr;

	Gerenciador_Eventos* Gerenciador_Eventos::get_instance() {
		if (instance == nullptr) {
			instance = new Gerenciador_Eventos();
		}
		return instance;
	}

	Gerenciador_Eventos::Gerenciador_Eventos() : Subject()
	{
		pGG = Gerenciador_Grafico::get_instance();
	}

	Gerenciador_Eventos::~Gerenciador_Eventos() {
	
	}
	
	void Gerenciador_Eventos::executar()
	{
		sf::Event event;

		while(pGG->getJanela()->pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed)
			{
				notify((event.key.code));
			}
			else if (event.type == sf::Event::Closed)
			{
				pGG->fechajanela();
			}
			
		}
	}

}