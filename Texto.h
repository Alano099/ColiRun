#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Gerenciador_Grafico.h"

namespace Menus
{
	class Texto
	{
	private:
		sf::Text text;
		static Gerenciadores::Gerenciador_Grafico* pGG;
	public:
		Texto(std::string n = "");
		~Texto();

		void setPosicao(sf::Vector2f posicao);
		void setTamanho(int t);
		void setNome(std::string n);
		void desenhar();
		void setCor(int c);

	};
}
