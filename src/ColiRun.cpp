#include "../include/ColiRun.h"
#include "../include/Menu.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace Fases;

ColiRun::ColiRun()
    : pGG(Gerenciadores::Gerenciador_Grafico::get_instance()),
    p1({ 100.f, 550.f }, true),
    p2({ 100.f, 550.f }, false),
    coliseu(&p1, &p2),
    masmorra(&p1, &p2),menu()
{
    // ======== 1. CRIA MENU ========
   
   

    // ======== 2. PEGA ESCOLHA ========
    int faseEscolhida = menu.getFaseSelecionada();
    int numJogadores = menu.getNumJogadores();

    // ======== 3. SET FASE INICIAL ========
    if (faseEscolhida == 1) {
        faseAtual = &coliseu;

        if (numJogadores == 1)
            faseAtual->setJogadores(&p1, nullptr);
        else
            faseAtual->setJogadores(&p1, &p2);

    }
    else {
        faseAtual = &masmorra;
        if (numJogadores == 1)
            faseAtual->setJogadores(&p1, nullptr);
        else
            faseAtual->setJogadores(&p1, &p2);
    }

    // ======== 4. COMEÇA LOOP ========
    executar();
}

ColiRun::~ColiRun() {}

void ColiRun::executar() {
    float dt;

    while (pGG->abreJanela()) {
        dt = pGG->atualizarTempo();
        pGG->limpar();

        faseAtual->executar(dt);

        // Troca de fase
        if (faseAtual->getFaseTerminada()) {
            if (faseAtual == &masmorra) {
                std::cout << "Todas as fases terminadas!" << std::endl;
                break;
            }
            else {
                std::cout << "Trocando para MASMORRA!" << std::endl;

                faseAtual = &masmorra;
                p1.setPosition({ 100.f, 550.f });
                p2.setPosition({ 100.f, 550.f });

                if (menu.getNumJogadores() == 1)
                    faseAtual->setJogadores(&p1, nullptr);
                else
                    faseAtual->setJogadores(&p1, &p2);


            }
            continue;
        }

            
        sf::Vector2f posCamera;

        if (&p1) {
            posCamera = p1.getPosicao();
            
        }
        else if (&p1 && &p2) {

            posCamera.x = (p1.getPosicao().x + p2.getPosicao().x) / 2.f;
            posCamera.y = (p1.getPosicao().y + p2.getPosicao().y) / 2.f;

        }
       

        // Limites do mapa
        sf::FloatRect limitesMapa(0.f, 0.f, faseAtual->getMapaLargura(), faseAtual->getMapaAltura());

        // Atualiza câmera
        pGG->atualizarCamera(posCamera, limitesMapa);

        pGG->mostrar();
    }
}
