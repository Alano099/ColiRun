#pragma once

#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estado.h"
#include "Gerenciador_Grafico.h"

#include <SFML/Graphics.hpp>

namespace Observers
{
	class Observer
	{
	protected:
		Gerenciadores::Gerenciador_Eventos* pGE;
		Gerenciadores::Gerenciador_Estado* pEG;
		Gerenciadores::Gerenciador_Grafico* pGG;

	public:
		Observer();
		virtual ~Observer();

		virtual void executar(sf::Keyboard::Key key_code) = 0;
	};
}