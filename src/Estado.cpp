#include "../include/Estado.h"

#include "../include/Gerenciador_Estado.h"

namespace Estados 
{
	Gerenciadores::Gerenciador_Estado *Estado::pEG(Gerenciadores::Gerenciador_Estado::get_instance());

	Estado::Estado(int id) : id_estado(id)
	{
		pEG->add_estado(this);
	}

	Estado::~Estado()
	{
		pEG = nullptr;
	}

	void Estado::setGerenciadorEstado(Gerenciadores::Gerenciador_Estado* p)
	{
		pEG = p;
	}

	int Estado::getId() const
	{
		return id_estado;
	}

	const bool Estado::get_ativo()
	{
		return (id_estado == pEG->get_AtualEstadoID() ? true : false);
	}

}