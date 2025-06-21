#pragma once

#include "Estado.h"
#include <stdexcept>
#include <map>


namespace Gerenciadores
{
	class Gerenciador_Estado
	{
	private:
		Estados::estadoID AtualEstadoID;

		std::map<Estados::estadoID, Estados::Estado*> mapEstado;
	public:
		Gerenciador_Estado();
		virtual ~Gerenciador_Estado();

		void mudarAtualEstado(Estados::estadoID id);
		void executarAtualEstado(const float dt);

		Estados::estadoID getAtualEstadoID() const;

		void inserirEstado(Estados::Estado* pE);

	};
}