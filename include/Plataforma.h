#pragma once
#include "Obstaculo.h"

#define PLATAFORMA_LARGURA 1800.f
#define PLATAFORMA_ALTURA 55.f
#define PLATAFORMA_CAMINHO "assets/obstaculos/red.png"


namespace Entidades {

    namespace Obstaculos {

        class Plataforma :public Obstaculo{

        private:
            bool noChao;
        public:
            Plataforma(sf::Vector2f posicao , sf::Vector2f tamanho,IDs::IDs id);
            ~Plataforma();

            void executar(float dt);
            void inicializar();
            void colidir(Entidade* outraEntidade, sf::Vector2f intercepta);

        };


    }


}

