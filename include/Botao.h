#pragma once

#include <SFML/Graphics.hpp>

#include "Gerenciador_Grafico.h"
#include "Animacao.h"
#include "Texto.h"

namespace Menus{
	class Botao : public ElementosGraficos::Animacao
	{
	private:
        Texto textoInfo;
        sf::Texture* defaultTextura;
        sf::Texture* selecionarTextura;

    public:
        Botao(sf::Vector2f posicao = sf::Vector2f(0, 0), std::string info = "");

        ~Botao();

        void selecionar(const bool ehSelecionado);

        void renderizar();
	};
	

}
