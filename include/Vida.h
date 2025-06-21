#pragma once
#include "Animacao.h"

#define HEART_SIZE_X 25
#define HEART_SIZE_Y 21.5

namespace ElementosGraficos{

    enum VidaID {
        vazio = 0,
        metade,
        cheio
    };

    class Vida : public Animacao {
    private:
        sf::Texture* vazio;
        sf::Texture* metade;
        sf::Texture* cheio;

    public:
        Vida();
        ~Vida();

        void atualizar(VidaID id, sf::Vector2f posicao);
    };

}