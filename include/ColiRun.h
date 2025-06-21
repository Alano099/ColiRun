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
    Fases::Coliseu coliseu;
    Fases::Masmorra masmorra;
    Fases::Fase* faseAtual;

public:
    ColiRun();
    ~ColiRun();

    void executar();
};