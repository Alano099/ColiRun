#include "../include/ConfiguracaoMenu.h"
#include "../include/Gerenciador_Grafico.h"
#include "../include/Fase.h"
#include <fstream>

namespace Menus {

    ConfiguracaoMenu::ConfiguracaoMenu(Fases::Fase* pG) :
        Menu(),
        Estado(dynamic_cast<Gerenciadores::Gerenciador_Estado*>(pG), Estados::estadoID::configuracoes),
        pFase(pG) {
        Gerenciadores::Gerenciador_Grafico* pGG = Gerenciadores::Gerenciador_Grafico::get_instance();
        Menus::Botao* bt = NULL;

        bt = new Menus::Botao(sf::Vector2f(pGG->getTamjanela().x / 2.0f, pGG->getTamjanela().y / 2), "Render distance 30");
        bt->selecionar(true);
        vectorBotao.push_back(bt);

        bt = new Menus::Botao(sf::Vector2f(pGG->getTamjanela().x / 2.0f, pGG->getTamjanela().y / 2 + 100), "Render distance 50");
        vectorBotao.push_back(bt);

        bt = new Menus::Botao(sf::Vector2f(pGG->getTamjanela().x / 2.0f, pGG->getTamjanela().y / 2 + 300), "return");
        vectorBotao.push_back(bt);

        max = 2;

        renderizarDistancia = 30;
    }

    ConfiguracaoMenu::~ConfiguracaoMenu() {}

    void ConfiguracaoMenu::atualizar(float dt) {
        ativado = true;
    }

    /* Menu operation to render all it's objects. */
    void ConfiguracaoMenu::renderizar() {
        atualizarView();
        for (it = vectorBotao.begin(); it != vectorBotao.end(); ++it)
            (*it)->renderizar();
    }

    void ConfiguracaoMenu::exec() {
        if (ativado) {
            ativado = false;
            switch (selecionar) {
            case 0:
                renderizarDistancia = 30;
                break;
            case 1:
                renderizarDistancia = 50;
                break;
            default:
                break;
            }
            resetaEstado();
        }
    }

    void ConfiguracaoMenu::resetaEstado() {
        vectorBotao[selecionar]->selecionar(false);
        selecionar = 2;
        vectorBotao[selecionar]->selecionar(true);
    }


}