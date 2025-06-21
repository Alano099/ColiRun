#include "../include/MainMenu.h"  
#include "../include/Fase.h" // Adicionado para garantir que Fases::Fase seja um tipo de classe completo

namespace Menus  
{  
    MainMenu::MainMenu(Fases::Fase* pF) :  
        Menu(),  
        Estado(dynamic_cast<Gerenciadores::Gerenciador_Estado*>(pF), Estados::estadoID::mainMenu),
        pFase(pF),  
        titulo() {  
        Gerenciadores::Gerenciador_Grafico* pGG = Gerenciadores::Gerenciador_Grafico::get_instance();  
        Menus::Botao* bt = NULL;  

        bt = new Menus::Botao(sf::Vector2f(pGG->getTamjanela().x / 2.0f, pGG->getTamjanela().y / 2), "PLAY GAME");
        bt->selecionar(true);  
        vectorBotao.push_back(bt);  

        bt = new Menus::Botao(sf::Vector2f(pGG->getTamjanela().x / 2.0f, pGG->getTamjanela().y / 2 + 100), "LEADERBOARD");
        vectorBotao.push_back(bt);  

        bt = new Menus::Botao(sf::Vector2f(pGG->getTamjanela().x / 2.0f, pGG->getTamjanela().y / 2 + 200), "SETTINGS");
        vectorBotao.push_back(bt);  

        bt = new Menus::Botao(sf::Vector2f(pGG->getTamjanela().x / 2.0f, pGG->getTamjanela().y / 2 + 300), "EXIT GAME");
        vectorBotao.push_back(bt);  

        titulo->setTextoInfo("Colirun");  
        titulo->setFonteTamanho(140);  
        titulo->setTextoCor(77.6, 68.2, 44.3);
        titulo->setTextoAlinhamento(Menus::TextoAlinhamento::centro);

        titulo->setPosicao(sf::Vector2f(pGG->getTamjanela().x / 2.0f, 0.0f - titulo->getTamanho().y / 2));

        max = 3;  
    }  

    MainMenu::~MainMenu() {  
    }  

    void MainMenu::Atualizar(float dt) {  
        ativado= true;  
        if (titulo->getPosicao().y < 200)  
            titulo->setPosicao(sf::Vector2f(titulo->getPosicao().x, titulo->getPosicao().y + 1));
    }  

    void MainMenu::renderizar() {  
        atualizarView();   
        for (it = vectorBotao.begin(); it != vectorBotao.end(); ++it)  
            (*it)->renderizar();  
        titulo->renderizar();  
    }  

    void MainMenu::exec() {  
        if (ativado) {  
            ativado = false;
            switch (selecionar) {  
            case 0:  
                mudarEstado(Estados::estadoID::jogador);  
                break;  
            case 1:  
                mudarEstado(Estados::estadoID::configuracoes);
                break;  
            case 2:  
                pFase->endGame();
                break;   
            default:  
                break;  
            }  
        }  
    }  

    void MainMenu::resetaEstado() {  
        vectorBotao[selecionar]->selecionar(false);
        selecionar = 0;
        vectorBotao[selecionar]->selecionar(true);
        titulo->setPosicao(sf::Vector2f(titulo->getPosicao().x, 0.0f - titulo->getTamanho().y / 2));
        
    }  
}