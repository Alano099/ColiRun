#pragma once
#include "Entidade.h"
#include "ListaEntidades.h"

namespace Gerenciadores {

	class Gerenciador_Colisoes
	{
	private:
		Lista::ListaEntidade* listaPersonagens;
		Lista::ListaEntidade* listaObstaculos;

	public:
		Gerenciador_Colisoes(Lista::ListaEntidade* listaPersonagens, Lista::ListaEntidade* listaObstaculos);
		~Gerenciador_Colisoes();

		void colidir();
		void limpar();

	};


}

