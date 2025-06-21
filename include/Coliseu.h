#pragma once
#include "Fase.h"

//*************** FASE 01 *******************

namespace Fases {


    class Coliseu : public Fase
    {

    private:
        int finalFase;
       
    public:
        Coliseu();
        ~Coliseu();

        void criarLamas(sf::Vector2f pos);
        void criarMinotauros(sf::Vector2f pos);

        void inicializar();

        void carregarMapa(const std::string& caminho);

		void setFinalFase(int final) { finalFase = 1000; }

        void executar(float dt);
        void desenhar();
        void atualizar(float dt);

        bool getFaseTerminada() const { return faseTerminada; }
        

    };

}


