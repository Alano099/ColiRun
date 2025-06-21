#include "../include/hub.h"

#include "../include/Jogador.h"

#include <string>

namespace ElementosGraficos {

    Hud::Hud(Entidades::Personagens::Jogador* pJogador) :
        Ente(),
        pJogador(pJogador),
        pGG(Gerenciadores::Gerenciador_Grafico::get_instance())
    {
        allVida = new ElementosGraficos::Vida[5];

        executar();
    }

    Hud::~Hud() {
        // delete (allHeart);
    }

    void Hud::renderizar() {
        for (int i = 0; i < 5; i++)
            allVida[i].desenhar();
    }

    void Hud::atualizar(const float dt) {
        posicao = pGG->getTopLeftPosition();

        AtualizarVidas();

    }

    void Hud::executar() {

    }


    void Hud::AtualizarVidas() {
        int VidasJogador = pJogador->getVida();

        for (int i = 0; i < 5; i++) {
            if (VidasJogador / 10 >= 1) {
                allVida[i].atualizar(VidaID::cheio, sf::Vector2f(posicao.x + 5 + 1 * i + HEART_SIZE_X * i, posicao.y + 17));
                VidasJogador -= 10;
            }

            else if (VidasJogador % 10 == 5) {
                allVida[i].atualizar(VidaID::metade, sf::Vector2f(posicao.x + 5 + 1 * i + HEART_SIZE_X * i, posicao.y + 17));
                VidasJogador -= 5;
            }

            else {
                allVida[i].atualizar(VidaID::vazio, sf::Vector2f(posicao.x + 5 + 1 * i + HEART_SIZE_X * i, posicao.y + 17));
            }
        }
    }


    void Hud::setJogador(Entidades::Personagens::Jogador* pJogador) {
        this->pJogador = pJogador;
    }

}