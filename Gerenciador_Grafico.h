#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

using namespace std;

namespace Gerenciadores {

	class Gerenciador_Grafico
	{
	private:
		sf::RenderWindow* janela;

		static Gerenciador_Grafico* instance;
		Gerenciador_Grafico();
	public:

		~Gerenciador_Grafico();
		static Gerenciador_Grafico* get_instance();
		sf::RenderWindow* getJanela();
		void desenhar(sf::RectangleShape corpo);
		void desenhar(sf::CircleShape corpo);
		void mostrar();
		void limpar();
		void fechajanela();
		const bool abreJanela();
	};


}

