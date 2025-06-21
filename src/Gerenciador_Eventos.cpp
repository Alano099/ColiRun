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

	Gerenciador_Eventos::Gerenciador_Eventos():
		pGG(Gerenciadores::Gerenciador_Grafico::get_instance()),
		pSubject(Gerenciadores::Subject::get_instance())
	{
		
	}

	Gerenciador_Eventos::~Gerenciador_Eventos() 
	{
		pGG = nullptr;
		pSubject = nullptr;
	}
	
	void Gerenciador_Eventos::executar()
	{
		sf::Event event;

		while(pGG->getJanela()->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				pGG->fechajanela();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				pSubject->notify((event.key.code));
			}
			
			
		}
	}

}