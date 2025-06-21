#include "../include/ColiRun.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>


using namespace std;
using namespace Fases;

ColiRun::ColiRun()
    : pGG(Gerenciadores::Gerenciador_Grafico::get_instance()),
    pGE(Gerenciadores::Gerenciador_Eventos::get_instance())
    
{
    
    exec();
}

ColiRun::~ColiRun() {
    
}

void ColiRun::exec() {
   
    float dt;
    while (pGG->abreJanela()) {

        pGE->executar();

        dt = pGG->atualizarTempo();
        pGG->limpar();


        fase->executar(dt);
       

        pGG->mostrar();
        
    }
}
