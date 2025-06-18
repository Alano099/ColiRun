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

		for (int i = 0; i < 2; i++) {

			criarMinotauros({ 250.f + distancia.x,250.f + distancia.y });
			distancia += {40.f, 40.f};

		}

		distancia += {500.f, 0.f};

		for (int i = 0; i < 3; i++) {

			criarSoldados({ 250.f + distancia.x,250.f + distancia.y });
			distancia += {30.f, 30.f};

		}


	}

	void Coliseu::criarObstaculos()
	{
		criarPlataformas(sf::Vector2f(399.f, 600.f), {PLATAFORMA_LARGURA,PLATAFORMA_ALTURA });
		criarPlataformas(sf::Vector2f(500.f, 500.f), sf::Vector2f(50.f, 200.f));
		criarLamas(sf::Vector2f(399.f, 550.f));
		criarLamas(sf::Vector2f(799.f, 550.f));
	}

	void Coliseu::inicializar() {
		fundo.inicializar("assets/fundos/coliseu.png", sf::Vector2f(1600.f, 600.f));

		carregarMapa("assets/mapas/mapaColiseu.txt");

		listaJogadores.inserirEnt(p1);
		listaJogadores.inserirEnt(p2);
	}

	void Coliseu::carregarMapa(const std::string& caminho) {
		std::ifstream arquivo(caminho);

		if (!arquivo.is_open()) {
			std::cerr << "Erro ao abrir mapa: " << caminho << std::endl;
			return;
		}

		std::string linha;

		for (int i = 0; std::getline(arquivo, linha); i++) {
			int j = 0;

			for (char tile : linha) {
				float x = j * TAMANHO_TILE;
				float y = i * TAMANHO_TILE;

				switch (tile) {
				case '#':
					// parede (se quiser)
					break;

				case 'P':
					criarPlataformas({ x, y }, { TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y });
					break;

				case 'I':
					criarSoldados({ x, y });
					break;

				case 'M':
					criarMinotauros({ x, y });
					break;

				case 'L':
					criarLamas({ x, y });
					break;

				default:
					// vazio
					break;
				}

				j++;
			}
		}

		arquivo.close();
	}

	void Coliseu::criarLamas(sf::Vector2f pos)
	{
		Entidades::Entidade* tmp = nullptr;

		tmp = new Entidades::Obstaculos::Lama(pos, { LAMA_TAMANHO_X, LAMA_TAMANHO_Y }, IDs::IDs::lama);
		listaObstaculo.inserirEnt(tmp);
	}

	void Coliseu::criarMinotauros(sf::Vector2f pos)
	{
		Entidades::Personagens::Inimigos::Minotauro* inimigo =
			new Entidades::Personagens::Inimigos::Minotauro(pos, { MINOTAURO_TAMANHO_X,MINOTAURO_TAMANHO_Y }, IDs::IDs::minotauro);
		inimigo->definirLimitesDePatrulha(MINOTAURO_LIMITE_PATRULHA);
		inimigo->setJogador(p1);
		listaInimigos.inserirEnt(inimigo);
	}

}
