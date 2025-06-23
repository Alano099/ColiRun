#pragma once
#include "Obstaculo.h"

#define PLATAFORMA_LARGURA 1800.f
#define PLATAFORMA_ALTURA 80.f
#define PLATAFORMA_CAMINHO "assets/obstaculos/plataforma.jpg"
#define IMPULSO_TRAMPOLIM 1000.f

namespace Entidades {

    namespace Obstaculos {

        class Plataforma :public Obstaculo{

        private:
            bool noChao;
            bool trampolim;
        public:
            Plataforma(sf::Vector2f posicao , sf::Vector2f tamanho,IDs::IDs id,bool ehTrampolim);
            ~Plataforma();

            void executar(float dt);
            void inicializar();
            void obstacular(Entidade* outraEntidade, sf::Vector2f intercepta);

            void setTrampolim(bool t) { trampolim = t; }
            bool getTrampolim() const { return trampolim; }

        };


    }


}

