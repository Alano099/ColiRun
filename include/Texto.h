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
        Texto(Math::CoordF posicao = Math::CoordF(0, 0), std::string info = "", const char* path = FONT_PATH);

        ~Texto();

        void setTextoInfo(std::string info);

        void setPosicao(Math::CoordF posicao);

        void setTextoCor(const unsigned int R, const unsigned int G, const unsigned int B);

        void setFonteTamanho(const unsigned int tamanho);

        void setTextoAlinhamento(TextoAlinhamento opcao);

        Math::CoordF getTamanho() const;

        void renderizar();

        std::string getInfo() const;

        Math::CoordF getPosicao() const;
    };




       

        

    
}
