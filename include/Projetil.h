#pragma once

#include "Entidade.h"

#define PROJETIL_TAMANHO_X 35.f
#define PROJETIL_TAMANHO_Y 35.f

namespace Entidades {


    class Projetil : public Entidade {
    private:

        sf::RectangleShape corpo;
 
        bool ativo;

    public:
        Projetil(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs id,bool ativo);
        ~Projetil();

    
        void setAtivo(bool ativo);
        bool getAtivo() const;

        void executar(float dt);
        void desenhar();
        void inicializar();
    
        void setDirecao(float dir);

        void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);

        void setDirecaoComAngulo(float anguloGraus, float dir);
        void calcularTrajetoriaParaAlvo(sf::Vector2f alvo, float tempoVoo);

        sf::FloatRect getHitbox() const {
            return corpo.getGlobalBounds();
        }

    };

}
