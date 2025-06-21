#include "../include/Vida.h"

#define PATH_FULL "./assets/vida/HeartFULL.png"
#define PATH_HALF "./assets/vida/HeartHALF.png"
#define PATH_EMPTY "./assets/vida/HeartEMPTY.png"

namespace ElementosGraficos {

    Vida::Vida() {
        vazio = pGG->carregarTextura(PATH_EMPTY);
        metade = pGG->carregarTextura(PATH_HALF);
        cheio = pGG->carregarTextura(PATH_FULL);

        corpo.setTexture(cheio);

        corpo.setOrigin(0, 0);

        corpo.setSize(sf::Vector2f(HEART_SIZE_X, HEART_SIZE_Y));
    }

    Vida::~Vida() {}

    void Vida::atualizar(VidaID id, Math::CoordF posicao) {
        switch (id) {
        case VidaID::vazio:
            corpo.setTexture(vazio);
            break;
        case VidaID::metade:
            corpo.setTexture(metade);
            break;

        case VidaID::cheio:
            corpo.setTexture(cheio);
            break;
        }

        corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));
    }

}