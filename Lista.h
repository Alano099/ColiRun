 #pragma once

#include <iostream>
#include "IDs/IDs.h"

namespace Lista {
	/*template<class TL>
	class Lista
	{
	public:
		// Classe Elemento aninhado na classe Lista
		template<class TE>
		class Elemento {
		private:
			TE* elemento;
			Elemento<TE>* proximo;
		public:
			Elemento() { prox = nullptr; elemento = nullptr; }
			~Elemento() { prox = nullptr; elemento = nullptr; }
			void setElemento(TE* elem) { this->elemento = elem; }
			void setProx(Elemento<TE>* prox) { this->proximo = prox; }
			Elemento<TE>*getProx() const { return (proximo); }
			TE* getElemento() const { return (elemento); }
		};

		//classe Interator
		class Iterator {
		public:
			Iterator(Elemento<TL>* ptr) : current(ptr) {}

			Iterator& operator++() {
				if (current) {
					current = current->getProx();
				}
				return *this;
			}
			bool operator!=(const Iterator& other) const {
				return current != other.current;
			}

			TL* operator*() const {
				if (current) {
					return current->getElemento();
				}
				return nullptr;
			}
		private:
			Elemento<TL>* current;
		};

	private:
		Elemento<TL>* pInicio;
		Elemento<TL>* pFim;
		unsigned int tamanho; // Tamanho da lista
	public:
		Lista();
		~Lista();
		void inserir(TL* elemento);
		void remover(TL* elemento);
		void removerElemento(int pos);
		int getTamanho() const { return static_cast<int>(tamanho); }
		void limpar();
		void operator++() { tamanho++; }
		void operator--() { tamanho--; }
		TL* operator[](int pos);

		//Metodos para obter o iteradores
		Iterator begin() { return Iterator(pInicio); }
		Iterator end() { return Iterator(nullptr); }

	};

	template<class TL>
	Lista<TL>::Lista() : pInicio(nullptr), pFim(nullptr), tamanho(0) {}

	template<class TL>
	Lista<TL>::~Lista() {}

	template<class TL>
	void Lista<TL>::inserir(TL* elemento) {
		if (elemento == nullptr) {
			exit(1); // Não insere elementos nulos
		}
		Elemento<TL>* novo = new Elemento<TL>();
        novo->setElemento(elemento);
        if (pInicio == nullptr) {
            pInicio = novo;
            pFim = novo;
        }
        else {
            pFim->setProx(novo);
            pFim = novo;
        }
        operator++();
    }*/


    template<class TL>
    class Lista {
    public: // Iterator precisa ser público para ser usado fora da classe
        class Iterator {
        public:
            Iterator(class Elemento* ptr) : current(ptr) {}

            Iterator& operator++() {
                if (current)
                    current = current->getProx();
                return *this;
            }

            bool operator!=(const Iterator& other) const {
                return current != other.current;
            }

            TL* operator*() const {
                if (current)
                    return current->getElemento();
                return nullptr;
            }

        private:
            class Elemento* current;
        };

    private:
        class Elemento {
        private:
            TL* elemento;
            Elemento* proximo;
        public:
            Elemento() : elemento(nullptr), proximo(nullptr) {}
            ~Elemento() {
                elemento = nullptr;
                proximo = nullptr;
            }

            void setElemento(TL* elem) { elemento = elem; }
            void setProx(Elemento* prox) { this->proximo = prox; }

            Elemento* getProx() const { return proximo; }
            TL* getElemento() const { return elemento; }
        };

        Elemento* pInicio;
        Elemento* pFim;
        unsigned int tamanho;

    public:
        Lista() : pInicio(nullptr), pFim(nullptr), tamanho(0) {}
        ~Lista() { limpar(); }

        void inserir(TL* elemento) {
            if (!elemento) return;

            Elemento* novo = new Elemento();
            novo->setElemento(elemento);

            if (!pInicio) {
                pInicio = novo;
                pFim = novo;
            }
            else {
                pFim->setProx(novo);
                pFim = novo;
            }

            ++tamanho;
        }

        void removerElemento(int pos) {
            TL* elemento = operator[](pos);
            remover(elemento);
        }

        void remover(TL* elemento) {
            Elemento* anterior = nullptr;
            Elemento* atual = pInicio;

            while (atual && atual->getElemento() != elemento) {
                anterior = atual;
                atual = atual->getProx();
            }

            if (atual && atual->getElemento() == elemento) {
                if (atual == pInicio) {
                    pInicio = atual->getProx();
                }
                else if (atual == pFim) {
                    pFim = anterior;
                    if (anterior) anterior->setProx(nullptr);
                }
                else {
                    if (anterior) anterior->setProx(atual->getProx());
                }

                delete atual;
                --tamanho;
            }
        }

        void limpar() {
            Elemento* aux = pInicio;
            Elemento* aux2 = nullptr;

            while (aux) {
                TL* elemento = aux->getElemento();
                if (elemento) {
                    delete elemento;
                }

                aux2 = aux->getProx();
                delete aux;
                aux = aux2;
            }

            pInicio = nullptr;
            pFim = nullptr;
            tamanho = 0;
        }

        int getTamanho() const { return static_cast<int>(tamanho); }

        TL* operator[](int pos) {
            if (pos < 0 || pos >= static_cast<int>(tamanho)) {
                std::cerr << "Posição inválida na Lista" << std::endl;
                exit(1);
            }

            Elemento* atual = pInicio;
            for (int i = 0; i < pos; ++i)
                atual = atual->getProx();

            return atual->getElemento();
        }

        Iterator begin() { return Iterator(pInicio); }
        Iterator end() { return Iterator(nullptr); }
    };

} // namespace Lista
