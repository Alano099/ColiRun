#pragma once

#include "Fase.h"

namespace Fases {


    class Masmorra :public Fase
    {

    private:
        int inimigosVivos;
        Lista::ListaEntidade listaProjetil;
    public:
        Masmorra();
		~Masmorra();

		void executar(float dt);
		void desenhar();
		void atualizar(float dt);

        void carregarMapa(const std::string& caminho);

        void criarEspinhos(sf::Vector2f pos);

        void  criarMedusas(sf::Vector2f pos);

        void inicializar();

		int getInimigosVivos() const { return inimigosVivos; }
		void setInimigosVivos(int inimigos) { inimigosVivos = inimigos; }
        bool getFaseTerminada() const { return faseTerminada; }

        Entidades::Projetil* criarProjetil(sf::Vector2f pos);


    };


}
