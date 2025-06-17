#include "../include/Coliseu.h"

namespace Fases {

	Coliseu::Coliseu() :Fase(IDs::IDs::coliseu) {

		inicializar();

	}

	Coliseu::~Coliseu()
	{
	}

	void Coliseu::criarInimigos()
	{

		sf::Vector2f distancia = {0.f,0.f};
		for (int i = 0; i < MAX_INIMIGOS; i++) {

			criarSoldados({ 250.f + distancia.x,250.f + distancia.y });
			distancia += {10.f, 10.f};

		}

		

	}

	void Coliseu::criarObstaculos()
	{
		criarPlataformas(sf::Vector2f(399.f, 600.f));
	}

	void Coliseu::inicializar() {

		Gerenciadores::Gerenciador_Grafico* pGG = Gerenciadores::Gerenciador_Grafico::get_instance();
		sf::Texture* tex = pGG->carregarTextura("assets/fundos/coliseu.png");
		sf::Vector2u texSize = tex->getSize();
		sf::Vector2u janelaSize = pGG->getJanela()->getSize();

		sf::Vector2f centro = pGG->getJanela()->getView().getCenter();
		fundo.inicializar("assets/fundos/coliseu.png", centro, sf::Vector2f(static_cast<float>(1320), static_cast<float>(440)));

		criarInimigos();
		criarObstaculos();
		listaJogadores.inserirEnt(p1);
		listaJogadores.inserirEnt(p2);
	}


}
