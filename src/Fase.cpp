#include "../include/Fase.h"
#include "../include/Inimigo.h"

namespace Fases {

    Fase::Fase(IDs::IDs id)
        :Ente(id), gerenciador_Eventos(Gerenciadores::Gerenciador_Eventos::get_instance()),
        p1(new Entidades::Personagens::Jogador({ 100.f, 200.f }, true)),p2(new Entidades::Personagens::Jogador({ 100.f, 200.f }, false)),
        gerenciadorColisoes() {

       
    }

    Fase::~Fase() {}

    

    Entidades::Personagens::Jogador* Fase::getJogador() const
    {
        return p1;
    }



  
    void Fase::criarPlataformas(sf::Vector2f pos, sf::Vector2f tam)
    {
        bool ehTrampolim = false;

        // 30% de chance
        int chance = rand() % 100;

        if (chance < 30)
            ehTrampolim = true;

        Entidades::Entidade* tmp = new Entidades::Obstaculos::Plataforma(pos, tam, IDs::IDs::plataforma, ehTrampolim);

        listaObstaculo.inserirEnt(tmp);
    }

    void Fase::criarSoldados(sf::Vector2f pos)
    {
        Entidades::Personagens::Inimigos::Soldado* inimigo = 
            new Entidades::Personagens::Inimigos::Soldado(pos, { SOLDADO_TAMANHO_X,SOLDADO_TAMANHO_Y }, IDs::IDs::soldado,100);
        inimigo->definirLimitesDePatrulha(SOLDADO_LIMITE_PATRULHA);
        inimigo->setJogador(p1);
        listaInimigos.inserirEnt(inimigo);
    }

    void Fase::gerenciar_colisoes()
    {
        gerenciadorColisoes.colidir();
    }

} // namespace Fases