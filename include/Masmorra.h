#pragma once

#include "Fase.h"

namespace Fases {


    class Masmorra :public Fase
    {

    private:
        int inimigosVivos;
    public:
        Masmorra();
		~Masmorra();


		void criarInimigos();
		void criarObstaculos();


        void criarEspinhos(sf::Vector2f pos);

        void  criarMedusas(sf::Vector2f pos);

        void inicializar();

        void carregarMapa(const std::string& caminho);

		int getInimigosVivos() const { return inimigosVivos; }
		void setInimigosVivos(int inimigos) { inimigosVivos = inimigos; }

    };


}
