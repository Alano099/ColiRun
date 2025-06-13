#pragma once
#include "Obstaculo.h"

#define PLATAFORMA_LARGURA 500.f
#define PLATAFORMA_ALTURA 55.f
#define PLATAFORMA_CAMINHO "assets/obstaculos/red.png"


namespace Entidades {

    namespace Obstaculos {

        class Plataforma :public Obstaculo{

        private:

        public:
            Plataforma(sf::Vector2f posicao , sf::Vector2f tamanho);
            ~Plataforma();

            void atualizar(float dt);
            void inicializar();
            void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);

        };


    }


}

