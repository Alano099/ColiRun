#include "../include/Fase.h"
#include "../include/Inimigo.h"

namespace Fases {

    Fase::Fase(IDs::IDs id)
        :Ente(id), gerenciador_Eventos(Gerenciadores::Gerenciador_Eventos::get_instance()),
        p1(new Entidades::Personagens::Jogador({ 100.f, 200.f }, true)),p2(new Entidades::Personagens::Jogador({ 100.f, 200.f }, false)),
        gerenciadorColisoes(&listaJogadores,&listaInimigos, &listaObstaculo) {

       
    }

    Fase::~Fase() {}

    void Fase::executar(float dt) {
        
        atualizar(dt);
        desenhar();
    }

    Entidades::Personagens::Jogador* Fase::getJogador() const
    {
        return p1;
    }

    
    void Fase::atualizar(float dt) {
        listaJogadores.executar(dt);
        listaInimigos.executar(dt);
        listaObstaculo.executar(dt);
        gerenciar_colisoes();

        fundo.atualizar(dt, p1->getVelocidade().x/8);

    }



    void Fase::desenhar() {

        fundo.desenhar(pGG->getJanela());
        
        listaObstaculo.desenharEntidades();
        listaJogadores.desenharEntidades();
        listaInimigos.desenharEntidades();
    }

    /*
    
    
    void Fases::Fase::inicializar() {

        Gerenciadores::Gerenciador_Grafico* pGG = Gerenciadores::Gerenciador_Grafico::get_instance();
        sf::Texture* tex = pGG->carregarTextura("assets/fundos/coliseu.png");
        sf::Vector2u texSize = tex->getSize();
        sf::Vector2u janelaSize = pGG->getJanela()->getSize();

        sf::Vector2f centro = pGG->getJanela()->getView().getCenter();
        fundo.inicializar("assets/fundos/coliseu.png", centro, sf::Vector2f(static_cast<float>(1320), static_cast<float>(440)));

        sf::Vector2f escala(
            static_cast<float>(janelaSize.x) / static_cast<float>(texSize.x),
            static_cast<float>(janelaSize.y) / static_cast<float>(texSize.y));
        fundo.setScale(escala);

        Entidades::Entidade* tmp = nullptr;

        tmp = new Entidades::Obstaculos::Plataforma(sf::Vector2f(399.f, 600.f), sf::Vector2f(1800.f, 32.f),IDs::IDs::plataforma);
        listaObstaculo.inserirEnt(tmp);

        tmp = new Entidades::Obstaculos::Espinho(sf::Vector2f(600.f, 550.f), sf::Vector2f(100.f, 100.f),IDs::IDs::plataforma);
		listaObstaculo.inserirEnt(tmp);

        //tmp = new Entidades::Obstaculos::Plataforma(sf::Vector2f(600.f, 550.f), sf::Vector2f(100.f, 100.f));
        //listaObstaculo.inserirEnt(tmp);

        Entidades::Personagens::Inimigos::Soldado* inimigo = new Entidades::Personagens::Inimigos::Soldado(sf::Vector2f(700.f, 200.f),{SOLDADO_TAMANHO_X,SOLDADO_TAMANHO_Y},IDs::IDs::soldado);
        inimigo->definirLimitesDePatrulha(150.f);
        inimigo->setJogador(p1);
        listaInimigos.inserirEnt(inimigo);
        Entidades::Personagens::Inimigos::Medusa* inimigo2 = new Entidades::Personagens::Inimigos::Medusa(sf::Vector2f(500.f, 200.f),{MEDUSA_TAMANHO_X,MEDUSA_TAMANHO_Y},IDs::IDs::medusa);
        inimigo2->definirLimitesDePatrulha(150.f);
        inimigo2->setJogador(p1);
        listaInimigos.inserirEnt(inimigo2);

        Entidades::Personagens::Inimigos::Minotauro* inimigo3 = new Entidades::Personagens::Inimigos::Minotauro(sf::Vector2f(800.f, 200.f), { MINOTAURO_TAMANHO_X,MINOTAURO_TAMANHO_Y }, IDs::IDs::minotauro);
		inimigo3->definirLimitesDePatrulha(150.f);
		inimigo3->setJogador(p1);
        listaInimigos.inserirEnt(inimigo3);

        listaJogadores.inserirEnt(p2);

        listaJogadores.inserirEnt(p1);

    }
    */

  
    void Fase::criarPlataformas(sf::Vector2f pos, sf::Vector2f tam)
    {
        Entidades::Entidade* tmp = nullptr;

        tmp = new Entidades::Obstaculos::Plataforma(pos, tam, IDs::IDs::plataforma);
        listaObstaculo.inserirEnt(tmp);
    }

    void Fase::criarSoldados(sf::Vector2f pos)
    {
        Entidades::Personagens::Inimigos::Soldado* inimigo = 
            new Entidades::Personagens::Inimigos::Soldado(pos, { SOLDADO_TAMANHO_X,SOLDADO_TAMANHO_Y }, IDs::IDs::soldado);
        inimigo->definirLimitesDePatrulha(SOLDADO_LIMITE_PATRULHA);
        inimigo->setJogador(p1);
        listaInimigos.inserirEnt(inimigo);
    }

    void Fase::gerenciar_colisoes()
    {
        gerenciadorColisoes.colidir();
    }

} // namespace Fases