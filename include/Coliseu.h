#pragma once
#include "Fase.h"

//*************** FASE 01 *******************

namespace Fases {


    class Coliseu : public Fase
    {

    private:
        int finalFase;
    public:
        Coliseu();
        ~Coliseu();

        void criarInimigos();
        void criarObstaculos();
        void inicializar();

		void setFinalFase(int final) { finalFase = 1000; }
    };

}


