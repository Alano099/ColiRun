#include "../include/Gerenciador_Estado.h"
#include <iostream>

namespace Gerenciadores
{
	Gerenciador_Estado* Gerenciador_Estado::instance = nullptr;

	Gerenciador_Estado* Gerenciador_Estado::get_instance()
	{
		if (instance == nullptr)
		{
			instance = new Gerenciador_Estado();
		}
		return instance;
	}

	Gerenciador_Estado::Gerenciador_Estado() : 
	AtualEstado(0)
	{
		vector_estados.resize(8);
	}

	Gerenciador_Estado::~Gerenciador_Estado()
	{
		for (int i = 0; i < vector_estados.size(); i++)
		{
			delete vector_estados[i];
		}
	}
	void Gerenciador_Estado::set_AtualEstado(int i)
	{
		AtualEstado = i;
	}

	int Gerenciador_Estado::get_AtualEstadoID()
	{
		return AtualEstado;
	}

	void Gerenciador_Estado::add_estado(Estados::Estado* pEstado)
	{
		try
		{
			vector_estados.at(pEstado->getId()) = pEstado;
		}
		catch (const std::out_of_range& oor)
		{
			std::cerr << "Erro: ID do estado fora do intervalo permitido." << std::endl;
		}
	}

	void Gerenciador_Estado::reseta_AtualEstado()
	{
		vector_estados[AtualEstado]->reiniciar();
	}

	void Gerenciador_Estado::executar()
	{
		vector_estados[AtualEstado]->executar();
	}
}