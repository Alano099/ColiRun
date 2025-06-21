#pragma once
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estado.h"
#include "MainMenu.h"
#include "Coliseu.h"
#include "Masmorra.h"

class ColiRun {
private:
    Gerenciadores::Gerenciador_Grafico* pGG;
    Gerenciadores::Gerenciador_Eventos* pGE;
    Gerenciadores::Gerenciador_Estado* pEG;
    Fases::Coliseu fase1;
    Fases::Masmorra fase2;
    Menus::MainMenu main_menu;
    

public:
    ColiRun();
    ~ColiRun();

    void exec();

    void endGame();
};