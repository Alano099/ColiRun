#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Jogador.h"



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
		void tratarEventoJogador(Entidades::Personagens::Jogador* p1, Entidades::Personagens::Jogador* p2);
		const sf::Event getEvento() const;
		
	};
}