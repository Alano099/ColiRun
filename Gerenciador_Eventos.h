#pragma once

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Estado.h"
#include "Jogador.h"

#include <iostream>
#include "Subject.h"

namespace Observadores {
	class Observer;
}

namespace Gerenciadores {
	class Gerenciador_Eventos: public Subject {
	private:

	/*	Gerenciador_Grafico* pGG;
		static Gerenciador_Eventos* instance; //Singleton
		Gerenciador_Eventos();
	public:
		~Gerenciador_Eventos();
		static Gerenciador_Eventos* get_instance();
		void executar();*/

		sf::Event evento;

		static Gerenciador_Eventos* pGE; //Singleton
		static Gerenciador_Grafico* pGG;

		Gerenciador_Eventos();
	public:
		~Gerenciador_Eventos();
		static Gerenciador_Eventos* getGerEventos();
		void tratarEventoJanela();
		void tratarEventoJogador(Entidades::Personagens::Jogador* p1, Entidades::Personagens::Jogador* p2);
		const sf::Event getEvento() const;
		
	};
}