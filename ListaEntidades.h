#pragma once

#include <vector>
#include "Lista.h"
#include "Entidade.h"


using namespace std;

namespace Lista {
	class ListaEntidade {
	private:
		Lista<Entidades::Entidade> objListaEntidade;
		const IDs::IDs ID;
	public:
		ListaEntidade();
		~ListaEntidade();
		void inserirEnt(Entidades::Entidade* ent);
		void removerEnt(int pos);
		const int getTamanho() const { return objListaEntidade.getTamanho(); }
		Entidades::Entidade* operator[](int i) { return objListaEntidade[i]; }
		Entidades::Entidade* getEntidade(const IDs::IDs ID);
		void limparLista();
		void desenharEntidades();
		void executar();
	};
}
