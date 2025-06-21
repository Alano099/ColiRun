#include "../include/Botao.h"
#include <iostream>

#define BUTTON_PATH_DEFAULT "../assets/botao/Selected_light.png"
#define BUTTON_PATH_SELECTED "../assets/botao/Selected.png"
#define BUTTON_HEIGHT 80
#define BUTTON_WIDTH 300
#define BUTTON_TEXT_COLOR 77.6, 68.2, 44.3 // R, G, B
#define FONT_SIZE 30


namespace Menus {

    Botao::Botao(sf::Vector2f posicao, std::string info) :
        textoInfo(posicao, info),
        defaultTextura(nullptr),
        selecionarTextura(nullptr) {
        
        defaultTextura = pGG->carregarTextura(BUTTON_PATH_DEFAULT);
        selecionarTextura = pGG->carregarTextura(BUTTON_PATH_SELECTED);

        corpo.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));

        corpo.setOrigin(sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2));

        corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));

        corpo.setTexture(defaultTextura);

        textoInfo.setFonteTamanho(FONT_SIZE);

        textoInfo.setTextoAlinhamento(TextoAlinhamento::centro);

        textoInfo.setTextoCor(BUTTON_TEXT_COLOR);

        textoInfo.setPosicao(sf::Vector2f(posicao.x, posicao.y));
    }

    Botao::~Botao() {}

    void Botao::selecionar(const bool ehSelecionado) {
        if (ehSelecionado)
            corpo.setTexture(selecionarTextura);
        else
            corpo.setTexture(defaultTextura);
    }

    void Botao::renderizar() {
        pGG->desenhar(&corpo);

        textoInfo.renderizar();
    }

}