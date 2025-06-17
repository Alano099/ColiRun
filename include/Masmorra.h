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
        void inicializar();

		int getInimigosVivos() const { return inimigosVivos; }
		void setInimigosVivos(int inimigos) { inimigosVivos = inimigos; }

    };


}
