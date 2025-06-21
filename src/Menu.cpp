#include "../include/Menu.h"
#include "../include/Gerenciador_Grafico.h"

namespace Menus
{
	Menu::Menu() :
		Ente(),
        min(0),
        max(2),
        selecionar(0),
        menuOb(this),
        ativado(false)	
	{
        Gerenciadores::Gerenciador_Grafico* pGG = Gerenciadores::Gerenciador_Grafico::get_instance();

	}
	Menu::~Menu()
	{
        Menus::Botao* bt = NULL;
        while (vectorBotao.size() != 0) {
            bt = vectorBotao.back();
            delete (bt);
            vectorBotao.pop_back();
        }
        vectorBotao.clear();
    }
    void Menu::atualizarView() {
        Gerenciadores::Gerenciador_Grafico::get_instance()->centralizarView(sf::Vector2f(Gerenciadores::Gerenciador_Grafico::get_instance()->getTamjanela().x / 2, Gerenciadores::Gerenciador_Grafico::get_instance()->getTamjanela().y / 2));
    }

    /* Make the menu selection go Down */
    void Menu::selecionarBaixo() {
        if (ativado) {
            vectorBotao[selecionar]->selecionar(false);
            selecionar++;
            if (selecionar > max)
                selecionar = min;
            vectorBotao[selecionar]->selecionar(true);
        }
    }

    /* Make the menu selection go Up */
    void Menu::selecionarCima() {
        if (ativado) {
            vectorBotao[selecionar]->selecionar(false);
            selecionar--;
            if (selecionar < min)
                selecionar = max;
            vectorBotao[selecionar]->selecionar(true);
        }
    }

}