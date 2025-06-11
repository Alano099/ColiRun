#include "Estado.h"

#include "Gerenciador_Estado.h"

namespace Estados 
{
	Gerenciadores::Gerenciador_Estado *Estado::pGE(Gerenciadores::Gerenciador_Estado::get_instance());

	Estado::Estado(int id) : id_estado(id)
	{
		pGE->add_estado(this);
	}

	Estado::~Estado()
	{
		pGE = nullptr;
	}

	void Estado::setGerenciadorEstado(Gerenciadores::Gerenciador_Estado* p)
	{
		pGE = p;
	}

	int Estado::getId() const
	{
		return id_estado;
	}

	const bool Estado::get_ativo()
	{
		return (id_estado == pGE->get_AtualEstadoID() ? true : false);
	}

}