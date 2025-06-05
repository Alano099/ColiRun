#pragma once

#include "Estado.h"
#include <stdexcept>
#include <vector>


namespace Gerenciadores
{
	class Gerenciador_Estado
	{
	private:
		int AtualEstado;
		std::vector<Estados::Estado*> vector_estados;
		static Gerenciador_Estado* instance;
		Gerenciador_Estado();
	public:
		~Gerenciador_Estado();

		static Gerenciador_Estado* get_instance();
		void set_AtualEstado(int i);
		int get_AtualEstadoID();
		void add_estado(Estados::Estado* pEstado);
		void reseta_AtualEstado();
		void executar();

	};
}