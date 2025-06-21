#pragma once

#include "Menu.h"
#include "Estado.h"

namespace Fases {
    class Fase;
}

namespace Menus {

    class ConfiguracaoMenu : public Menu, public Estados::Estado {
    private:
        Fases::Fase* pGame;
        unsigned int renderizarDistancia;

    public:
        ConfiguracaoMenu(Fases::Fase* pG = nullptr);

        ~ConfiguracaoMenu();

        void atualizar(const float dt);

        void renderizar();

        void resetaEstado();

        void exec();

    };

}