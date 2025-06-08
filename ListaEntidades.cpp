#include "ListaEntidades.h"

namespace Lista {
	ListaEntidade::ListaEntidade() : objListaEntidade(), ID() {}

	ListaEntidade::~ListaEntidade() {}

	void ListaEntidade::inserirEnt(Entidades::Entidade* ent) { objListaEntidade.inserir(ent); }

	void ListaEntidade::removerEnt(int pos) { objListaEntidade.removerElemento(pos); }

	Entidades::Entidade* ListaEntidade::getEntidade(IDs::IDs ID) {
		std::vector<Entidades::Entidade*> entidades;
		for (int i = 0; i < objListaEntidade.getTamanho(); i++) {
			if (objListaEntidade[i]->getID() == ID) {
				return objListaEntidade[i];
			}
		}
		return nullptr;
	}

	void ListaEntidade::limparLista() { objListaEntidade.limpar(); }

	void ListaEntidade::desenharEntidades() {
		Entidades::Entidade* aux = nullptr;
		for (Lista<Entidades::Entidade>::Iterator it = objListaEntidade.begin(); it != objListaEntidade.end(); ++it) {
			aux = *it;
			if (aux != nullptr) {
				aux->desenhar();
			}
		}
	}

	void ListaEntidade::executar(float dt) {
		int tam = objListaEntidade.getTamanho();
		Entidades::Entidade* aux = nullptr;
		for (int i = tam - 1; i >= 0; i--) {
			aux = objListaEntidade.operator[](i);
			if (aux != nullptr) {
				if (aux->getRemover()) {
					removerEnt(i);
					aux = nullptr;
				}
				else {
					aux->atualizar(dt);
				}
			}
		}
	}

	
}