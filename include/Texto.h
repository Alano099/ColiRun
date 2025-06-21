#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Gerenciador_Grafico.h"
#include "Math.h"
#include <string>

#define FONT_PATH "../assets/MainFont.ttf"

namespace Menus
{
    enum TextoAlinhamento {
        esquerda,
        centro,
        direita
    };

    class Texto {
    private:
        std::string info;

        sf::Text texto;

		static Gerenciadores::Gerenciador_Grafico* pGG;

    public:
        Texto(sf::Vector2f posicao = sf::Vector2f(0, 0), std::string info = "", const char* path = FONT_PATH);

        ~Texto();

        void setTextoInfo(std::string info);

        void setPosicao(sf::Vector2f posicao);

        void setTextoCor(const unsigned int R, const unsigned int G, const unsigned int B);

        void setFonteTamanho(const unsigned int tamanho);

        void setTextoAlinhamento(TextoAlinhamento opcao);

        sf::Vector2f getTamanho() const;

        void renderizar();

        std::string getInfo() const;

        sf::Vector2f getPosicao() const;
    };




       

        

    
}
