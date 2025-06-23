#include "../include/Menu.h"
#include <iostream>

Menu::Menu():Ente(IDs::IDs::nulo),
faseSelecionada(1), numJogadores(1)
{
   
    inicializar();
    executar(0.f);

}

Menu::~Menu() {}

void Menu::executar(float dt) {
    while (pGG->abreJanela()) {
        sf::Event evento;
        while (pGG->getJanela()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                pGG->getJanela()->close();

            if (evento.type == sf::Event::KeyPressed) {
                if (evento.key.code == sf::Keyboard::Up || evento.key.code == sf::Keyboard::Down) {
                    faseSelecionada = (faseSelecionada == 1) ? 2 : 1;
                }
                else if (evento.key.code == sf::Keyboard::Num1) {
                    numJogadores = 1;
                }
                else if (evento.key.code == sf::Keyboard::Num2) {
                    numJogadores = 2;
                }
                else if (evento.key.code == sf::Keyboard::Enter) {
                    return; // Sai do menu e começa o jogo
                }
            }
        }

        // Atualiza texto das opcoes
        opcao1.setString((faseSelecionada == 1 ? "> " : "  ") + std::string("Coliseu"));
        opcao2.setString((faseSelecionada == 2 ? "> " : "  ") + std::string("Masmorra"));

        textoNumJogadores.setString("Numero de jogadores: " + std::to_string(numJogadores));

        desenhar();
    }
}

void Menu::desenhar()
{
    pGG->limpar();

    pGG->getJanela()->draw(titulo);
    pGG->getJanela()->draw(opcao1);
    pGG->getJanela()->draw(opcao2);
    pGG->getJanela()->draw(textoNumJogadores);
    pGG->getJanela()->draw(instrucoes);

    pGG->mostrar();
}

void Menu::inicializar()
{
    fonte.loadFromFile("assets/PressStart2P-Regular.ttf");

    titulo.setFont(fonte);
    titulo.setString("ColiRun - MENU");
    titulo.setCharacterSize(50);
    titulo.setFillColor(sf::Color::White);
    titulo.setPosition(300.f, 50.f);

    opcao1.setFont(fonte);
    opcao1.setCharacterSize(30);
    opcao1.setPosition(350.f, 150.f);

    opcao2.setFont(fonte);
    opcao2.setCharacterSize(30);
    opcao2.setPosition(350.f, 200.f);

    textoNumJogadores.setFont(fonte);
    textoNumJogadores.setCharacterSize(30);
    textoNumJogadores.setPosition(350.f, 300.f);

    instrucoes.setFont(fonte);
    instrucoes.setString("Pressione ENTER para iniciar");
    instrucoes.setCharacterSize(20);
    instrucoes.setPosition(300.f, 500.f);
}
