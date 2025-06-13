#include "../include/Fase.h"
#include "../include/Inimigo.h"

namespace Fases {

    Fase::Fase(IDs::IDs id)
        :Ente(id), gerenciador_Eventos(Gerenciadores::Gerenciador_Eventos::get_instance()),
        p1(new Entidades::Personagens::Jogador({ 100.f, 200.f }, true)),
        gerenciadorColisoes(&listaPersonagens, &listaObstaculo) {

        inicializar();
    }

    Fase::~Fase() {}

    void Fase::executar() {
        float dt = Gerenciadores::Gerenciador_Grafico::get_instance()->atualizarTempo();
        atualizar(dt);
        desenhar();
    }

    Entidades::Personagens::Jogador* Fase::getJogador() const
    {
        return p1;
    }


    void Fase::atualizar(float dt) {
        listaPersonagens.executar(dt);
        listaObstaculo.executar(dt);
        gerenciadorColisoes.colidir();
    }

    void Fase::desenhar() {
        fundo.desenhar();
        listaObstaculo.desenharEntidades();
        listaPersonagens.desenharEntidades();
    }

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

        tmp = new Entidades::Obstaculos::Plataforma(sf::Vector2f(399.f, 600.f), sf::Vector2f(1800.f, 32.f));
        listaObstaculo.inserirEnt(tmp);

        tmp = new Entidades::Obstaculos::Plataforma(sf::Vector2f(600.f, 550.f), sf::Vector2f(100.f, 100.f));
        listaObstaculo.inserirEnt(tmp);

        Entidades::Personagens::Inimigos::Inimigo* inimigo = new Entidades::Personagens::Inimigos::Inimigo(sf::Vector2f(700.f, 200.f));
        inimigo->setJogador(p1);
        listaPersonagens.inserirEnt(inimigo);

        listaPersonagens.inserirEnt(p1);

    }

    ElementosGraficos::AnimacaoEstatica Fase::getFundo() const
    {
        return fundo;
    }

} // namespace Fases