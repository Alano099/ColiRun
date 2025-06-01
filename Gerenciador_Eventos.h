#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Personagem.h"



namespace Gerenciadores {
	class Gerenciador_Eventos {
	private:
		sf::Event evento;

		static Gerenciador_Eventos* pGE; //Singleton
		static Gerenciador_Grafico* pGG;

		Gerenciador_Eventos();
	public:
		~Gerenciador_Eventos();
		static Gerenciador_Eventos* getGerEventos();
		void tratarEventoJanela();
		void tratarEventoJogador(Entidades::Personagens::Personagem* p1, Entidades::Personagens::Personagem* p2);
		const sf::Event getEvento() const;
		
	};
}