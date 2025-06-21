#pragma once
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Fase.h"
#include "Coliseu.h"
#include "Masmorra.h"

class ColiRun {
private:
    Gerenciadores::Gerenciador_Grafico* pGG;
    Gerenciadores::Gerenciador_Eventos* pGE;
    //Fases::Fase* fase;

public:
    ColiRun();
    ~ColiRun();

    void executar();
};