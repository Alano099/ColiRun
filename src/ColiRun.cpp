#include "../include/ColiRun.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace Fases;

ColiRun::ColiRun()
    : pGG(Gerenciadores::Gerenciador_Grafico::get_instance()),
    pGE(Gerenciadores::Gerenciador_Eventos::get_instance()),
    coliseu() // inicializa fase com todos objetos
{
    faseAtual = &coliseu;
    executar();
}

ColiRun::~ColiRun() {
    
    
}

void ColiRun::executar() {
    float dt; 



    while (pGG->abreJanela()) {
        dt = pGG->atualizarTempo();
        pGG->limpar();


        faseAtual->executar(dt);
       
        if (faseAtual->getFaseTerminada()) {
            if (faseAtual == &coliseu) {
                std::cout << "Trocando para MASMORRA!" << std::endl;
                faseAtual = &masmorra;
            }
            else {
                std::cout << "Todas as fases terminadas!" << std::endl;
                break; // ou voltar pro menu
            }
            continue;
        }

        sf::Vector2f posJogador = faseAtual->getJogador()->getPosicao();
        sf::FloatRect limitesMapa(0.f, 0.f, faseAtual->getMapaLargura(), coliseu.getMapaAltura());
        pGG->atualizarCamera(faseAtual->getJogador()->getPosicao(), limitesMapa);

        pGG->atualizarCamera(posJogador, limitesMapa);


        pGG->mostrar();
      
    }
}