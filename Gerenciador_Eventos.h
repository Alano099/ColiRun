#pragma once

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Estado.h"

#include <iostream>
#include "Subject.h"

namespace Observadores {
	class Observer;
}

namespace Gerenciadores {
	class Gerenciador_Eventos: public Subject {
	private:
		Gerenciador_Grafico* pGG;
		static Gerenciador_Eventos* instance; //Singleton
		Gerenciador_Eventos();
	public:
		~Gerenciador_Eventos();
		static Gerenciador_Eventos* get_instance();
		void executar();
	};
}