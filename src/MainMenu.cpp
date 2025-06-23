
/*
#include "../include/MainMenu.h"

namespace Menus
{
    MainMenu::MainMenu() :
        Menu(4, 0, "Colirun"),
        AtualFase(1),
        AtualJogador(0),
        Fase1("Fase 1"),
        Fase2("Fase 2"),
        Jogador1("1 Jogador"),
        Jogador2("2 Jogadores")
    {
        titulo.setTamanho(50);
        titulo.setPosicao(sf::Vector2f(50.f, 25.f));
        titulo.setCor(0);
        Fase1.setPosicao(sf::Vector2f(100.f, 80.f));
        Fase2.setPosicao(sf::Vector2f(100.f, 80.f));

        Jogador1.setPosicao(sf::Vector2f(100.f, 125.f));
        Jogador2.setPosicao(sf::Vector2f(100.f, 125.f));

        Botoes[0]->setNome("Continue");
        Botoes[1]->setNome("Novo Jogo");
        Botoes[2]->setNome("Ranking");
        Botoes[3]->setNome("Sair");

        pMenuObserver = new Observers::MenuObserver;
        pMenuObserver->setMenu(this);

    }

    MainMenu::~MainMenu()
    {
        if(pMenuObserver)
            delete pMenuObserver;

        pMenuObserver = nullptr;
    }

    void MainMenu::selecionar()
    {
        switch (selecionar_indice)
        {
        case 0:
            if (AtualFase == 1)
            {
                if (AtualJogador == 0)
                    pEG->set_AtualEstado(1);
                else
                    pEG->set_AtualEstado(6);

            }
            else
            {
                if (AtualJogador == 0)
                    pEG->set_AtualEstado(2);
                else
                    pEG->set_AtualEstado(5);
            }
            break;
        case 1:
            if (AtualFase == 1)
            {
                if (AtualJogador == 0)
                    pEG->set_AtualEstado(1);
                else
                    pEG->set_AtualEstado(6);
            }
            else
            {
                if (AtualJogador == 0)
                    pEG->set_AtualEstado(2);
                else
                    pEG->set_AtualEstado(5);
            }
            pEG->reseta_AtualEstado();
            break;
        case 2:
        {

            Estados::Estado::pEG->set_AtualEstado(4);
        }
        break;
        case 3:
            pGG->fechajanela();
            break;
        }
    }

    void MainMenu::moverHorizontal(int i)
    {
        if (i == 1)
        {
            if (AtualFase == 1)
            {
                AtualFase = 2;
                //texture = pGM->load_textures("../assets/menu2.png");
                //corpo.setTexture(texture);
            }
            else
            {
                AtualFase = 1;
                //texture = pGM->load_textures("../assets/menu1.png");
                //corpo.setTexture(texture);
            }
        }
        else if (i == 2) {
            AtualJogador = !(AtualJogador);
        }
    }

    void MainMenu::desenhar()
    {
        pGG->desenhar(&(this->corpo));
        titulo.desenhar();
        if (!AtualJogador)
        {
            Jogador1.desenhar();
        }
        else
        {
            Jogador2.desenhar();
        }

        if (AtualFase == 1)
        {
            Fase1.desenhar();
        }
        else
        {
            Fase2.desenhar();
        }
        for (int i = 0; i < Max_Botoes; i++)
        {
            Botoes[i]->desenhar();
        }
    }
}
*/

