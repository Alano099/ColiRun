#pragma once

#include "Ente.h"
#include "Texto.h"
#include "Vida.h"


namespace Entidades{
    namespace Personagens {
        class Jogador;
	}
} 

namespace ElementosGraficos {

    class Hud : public Ente {
    private:
        Entidades::Personagens::Jogador* pJogador;
        
        Gerenciadores::Gerenciador_Grafico* pGG;
        Vida* allVida;

    public:
        Hud(Entidades::Personagens::Jogador* pJogador = nullptr);

        ~Hud();

        void renderizar();

        void atualizar(const float dt);

        void executar();

        void AtualizarVidas();

        void setJogador(Entidades::Personagens::Jogador* pJogador);
    };

}