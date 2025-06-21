#pragma once

#include "Gerenciador_Grafico.h"

#include <iostream>
#include "Subject.h"


namespace Gerenciadores {
	class Gerenciador_Eventos{
	private:
		Gerenciador_Grafico* pGG;
		Subject* pSubject; //Subject para notificar eventos

		static Gerenciador_Eventos* instance; //Singleton
		Gerenciador_Eventos();
	public:
		~Gerenciador_Eventos();
		static Gerenciador_Eventos* get_instance();
		
		void setSubject(Subject* subject);
		void executar();

	};
}