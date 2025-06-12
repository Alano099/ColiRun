#include "Menu.h"

namespace Menus
{
	Menu::Menu(int n_botoes, int id, std::string t) :
		Ente(static_cast<IDs::IDs>(id)),
		Estado(id),
		Max_Botoes(n_botoes),
		Botoes(),
		selecionar_indice(0),
		titulo(t)
	{
		for (int i = 0; i < Max_Botoes; i++)
		{
			Botoes.push_back(new Botao(sf::Vector2f(ALTURA / 2, (i + 2) * (20 + LARGURA))));
		}
		Botoes[0]->escolherCor();

		corpo.setSize(sf::Vector2f(800.f, 600.f));
		//texture = pGM->load_textures("../assets/menu1.png");
		//body.setTexture(texture);
	}
	Menu::~Menu()
	{
		for (int i = 0; i < Max_Botoes; i++)
		{
			delete Botoes[i];
		}
	}

    void Menu::desenhar()
    {
        for (int i = 0; i < Max_Botoes; i++)
        {
            Botoes[i]->desenhar();
        }
    }
    void Menu::mCima()
    {
        if (selecionar_indice > 0)
        {
            Botoes[selecionar_indice]->escolherCor();
            selecionar_indice;
            Botoes[selecionar_indice]->escolherCor();
        }
    }
    void Menu::mBaixo()
    {
        if (selecionar_indice < Max_Botoes - 1)
        {
            Botoes[selecionar_indice]->escolherCor();
            selecionar_indice++;
            Botoes[selecionar_indice]->escolherCor();
        }
    }
    void Menu::executar()
    {
        desenhar();
    }
    void Menu::mudarNome(std::string nome)
    {
        titulo.setNome(nome);
    }
}