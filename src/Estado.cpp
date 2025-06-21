#include "../include/Estado.h"

#include "../include/Gerenciador_Estado.h"

namespace Estados 
{

	Estado::Estado(Gerenciadores::Gerenciador_Estado* pEG, Estados::estadoID id) :pEG(pEG), id(id)
	{
		
	}

	Estado::~Estado()
	{
		pEG = nullptr;
	}

	void Estado::setGerenciadorEstado(Gerenciadores::Gerenciador_Estado* pEG)
	{
		this->pEG = pEG;
	}

	void Estado::mudarEstado(Estados::estadoID id)
	{
		pEG->mudarAtualEstado(id);
	}

	Estados::estadoID Estado::getID() const
	{
		return id;
	}

}