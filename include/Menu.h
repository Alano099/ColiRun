#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Ente.h"


class Menu:public Ente {
private:
    
    sf::Font fonte;
    sf::Text titulo;
    sf::Text opcao1;
    sf::Text opcao2;
    sf::Text textoNumJogadores;
    sf::Text instrucoes;

    int faseSelecionada; // 1 = masmorra, 2 = coliseu
    int numJogadores;    // 1 ou 2

public:
    Menu();
    ~Menu();

    void executar(float dt);
    virtual void desenhar();
    virtual void inicializar();

    int getFaseSelecionada() const { return faseSelecionada; }
    int getNumJogadores() const { return numJogadores; }
};
