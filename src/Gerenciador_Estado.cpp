#include "../include/Gerenciador_Estado.h"
#include <iostream>

namespace Gerenciadores
{
	
	Gerenciador_Estado::Gerenciador_Estado() 
	{
	}

	Gerenciador_Estado::~Gerenciador_Estado()
	{
		std::map<Estados::estadoID, Estados::Estado*>::iterator it;
		for (it = mapEstado.begin(); it != mapEstado.end(); ++it)
		{
			delete (it->second); // Libera a memória alocada para o estado
		}
	}

	void Gerenciador_Estado::mudarAtualEstado(Estados::estadoID id)
	{
		AtualEstadoID = id;
		mapEstado[AtualEstadoID]->resetarEstado();
	}

	void Gerenciador_Estado::executarAtualEstado(const float dt)
	{
		mapEstado[AtualEstadoID]->atualizar(dt);
		mapEstado[AtualEstadoID]->renderizar();
	}

	Estados::estadoID Gerenciador_Estado::getAtualEstadoID() const
	{
		return AtualEstadoID;
	}

	void Gerenciador_Estado::inserirEstado(Estados::Estado* pE)
	{
		if (pE == nullptr)
		{
			std::cout << "Erro: Estado nulo não pode ser inserido." << std::endl;
			exit(1);
		}
		mapEstado.insert(std::pair<Estados::estadoID, Estados::Estado*>(pE->getID(), pE));
	}
	
}