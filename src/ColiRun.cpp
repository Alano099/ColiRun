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
    fase(new Coliseu()) // inicializa fase com todos objetos
{
    executar();
}

ColiRun::~ColiRun() {
    delete fase;
    fase = nullptr;
}

void ColiRun::executar() {
    float dt;

    while (pGG->abreJanela()) {
        dt = pGG->atualizarTempo();
        pGG->limpar();


        fase->executar(dt);
       
        sf::Vector2f posJogador = fase->getJogador()->getPosicao();
        sf::FloatRect limitesMapa(0.f, 0.f, fase->getMapaLargura(), fase->getMapaAltura());
        pGG->atualizarCamera(fase->getJogador()->getPosicao(), limitesMapa);

        pGG->atualizarCamera(posJogador, limitesMapa);


        pGG->mostrar();
      
    }
}