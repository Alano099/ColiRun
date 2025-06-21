//Codigo adaptado do monitor matheus Burda https://www.youtube.com/watch?v=KJJo9QPY8kI&t || https://github.com/MatheusBurda/Desert

#pragma once

#include "Gerenciador_Grafico.h"
#include "../stdafx/stdafx.h"
#include "Math.h"
#include "../IDs/IDs.h"

#include <map>


namespace ElementosGraficos{


	class Animacao{
		
	protected:
		sf::RectangleShape corpo;
		static Gerenciadores::Gerenciador_Grafico* pGG;
			
	public:
		Animacao();
		~Animacao();

		void desenhar();

	};


}


