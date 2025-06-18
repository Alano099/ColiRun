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
       

        pGG->mostrar();
        sf::Vector2f centroFundo = sf::Vector2f(
            static_cast<float>(pGG->getJanela()->getSize().x) / 2.f,
            static_cast<float>(pGG->getJanela()->getSize().y) / 2.f
        );
        pGG->centralizarView(sf::Vector2f(fase->getJogador()->getPosicao().x,fase->getJogador()->getPosicao().y));
    }
}