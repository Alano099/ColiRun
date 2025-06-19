#include "../include/Masmorra.h"

namespace Fases {

	Masmorra::Masmorra() : Fase(IDs::IDs::masmorra), inimigosVivos(MAX_INIMIGOS) {
		inicializar();
	}

	Masmorra::~Masmorra() {
		
	}

	void Masmorra::criarInimigos() {
		sf::Vector2f distancia = { 0.f, 0.f };
		for (int i = 0; i < MAX_INIMIGOS; i++) {
			criarSoldados({ 250.f + distancia.x, 250.f + distancia.y });
			distancia += { 10.f, 10.f };
		}
	}

	void Masmorra::criarObstaculos() {
		//criarPlataformas(sf::Vector2f(399.f, 600.f));
	}

	void Masmorra::inicializar() {

		
		fundo.inicializar("assets/fundos/masmorra.jpg",sf::Vector2f(static_cast<float>(1320), static_cast<float>(440)));

		criarInimigos();
		criarObstaculos();
		listaJogadores.inserirEnt(p1);

	}

	void Masmorra::criarMedusas(sf::Vector2f pos)
	{
		Entidades::Personagens::Inimigos::Medusa* inimigo =
			new Entidades::Personagens::Inimigos::Medusa(pos, { MEDUSA_TAMANHO_X,MEDUSA_TAMANHO_Y }, IDs::IDs::medusa);
		inimigo->definirLimitesDePatrulha(MEDUSA_LIMITE_PATRULHA);
		inimigo->setJogador(p1);
		listaInimigos.inserirEnt(inimigo);
	}

	void Masmorra::criarEspinhos(sf::Vector2f pos)
	{
		Entidades::Entidade* tmp = nullptr;

		tmp = new Entidades::Obstaculos::Espinho(pos, { ESPINHO_TAMANHO_X, ESPINHO_TAMANHO_Y }, IDs::IDs::espinho);
		listaObstaculo.inserirEnt(tmp);
	}

	void Masmorra::carregarMapa(const std::string& caminho){}

}