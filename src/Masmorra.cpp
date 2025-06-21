#include "../include/Masmorra.h"

namespace Fases {

	Masmorra::Masmorra() : Fase(IDs::IDs::masmorra), inimigosVivos(MAX_INIMIGOS) {
		inicializar();
	}

	Masmorra::~Masmorra() {
		
	}

	void Masmorra::executar(float dt) {

		atualizar(dt);
		desenhar();
	}

	void Masmorra::atualizar(float dt) {
		listaJogadores.executar(dt);
		listaInimigos.executar(dt);
		listaObstaculo.executar(dt);
		gerenciar_colisoes();
		fundo.atualizar(dt, p1->getVelocidade().x / 10);
	}

	void Masmorra::desenhar() {
		fundo.desenhar(pGG->getJanela());
		pGG->getJanela()->draw(chao);
		listaObstaculo.desenharEntidades();
		listaJogadores.desenharEntidades();
		listaInimigos.desenharEntidades();
	}

	void Masmorra::inicializar() {

		// Carrega mapa
		carregarMapa("assets/mapas/mapaMasmorra.txt");

		// Inicializa fundo com o tamanho do mapa
		fundo.inicializar("assets/fundos/masmorra.jpg", sf::Vector2f(mapaLargura, mapaAltura));

		// Insere jogadores na lista
		listaJogadores.inserirEnt(p1);
		listaJogadores.inserirEnt(p2);

		// Cria chão com textura repetida
		sf::Texture* texturaChao = pGG->carregarTextura("assets/obstaculos/chao.jpeg");
		texturaChao->setRepeated(true);

		sf::Vector2f tamanhoChao(mapaLargura, 5000.f);

		chao.setSize(tamanhoChao);
		chao.setOrigin(0.f, 0.f); // Origem no canto superior esquerdo
		chao.setPosition(0.f, CHAO + 32.f); // Posiciona na base do mapa

		chao.setTexture(texturaChao);
		chao.setTextureRect(sf::IntRect(0, 0, static_cast<int>(tamanhoChao.x), static_cast<int>(tamanhoChao.y)));

		std::cout << "Coliseu inicializado com largura = " << mapaLargura << " e altura = " << mapaAltura << std::endl;

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

	void Masmorra::carregarMapa(const std::string& caminho){
	
		std::ifstream arquivo(caminho);

		if (!arquivo.is_open()) {
			std::cerr << "Erro ao abrir mapa: " << caminho << std::endl;
			return;
		}

		std::string linha;

		int numLinhas = 0;
		int numColunas = 0;

		std::vector<sf::Vector2f> posicoesPossiveisPlataformas;
		std::vector<sf::Vector2f> posicoesPossiveisSoldados;
		std::vector<sf::Vector2f> posicoesPossiveisEspinhos;
		std::vector<sf::Vector2f> posicoesPossiveisMedusas;


		for (int i = 0; std::getline(arquivo, linha); i++) {
			numLinhas++;

			int j = 0;

			for (char tile : linha) {
				float x = j * TAMANHO_TILE;
				float y = i * TAMANHO_TILE;

				switch (tile) {
				case '#':
					// parede (se quiser)
					break;

				case 'P':

					posicoesPossiveisPlataformas.push_back({ x, y });
					//criarPlataformas({ x, y }, { 65.f, 65.f });
					break;

				case 'I':
					posicoesPossiveisSoldados.push_back({ x, y });
					//criarSoldados({ x, y });
					break;

				case 'M':
					posicoesPossiveisMedusas.push_back({ x, y });
					//criarMinotauros({ x, y });
					break;

				case 'E':
					posicoesPossiveisEspinhos.push_back({ x, y });
					//criarLamas({ x, y });
					break;

				default:
					// vazio
					break;
				}

				j++;
			}

			if (j > numColunas)
				numColunas = j;

		}

		mapaLargura = numColunas * TAMANHO_TILE;
		mapaAltura = numLinhas * TAMANHO_TILE;

		// SORTEIO PLATAFORMAS
		int numPlataformas = 3 + rand() % 4; // 3 a 6

		std::random_shuffle(posicoesPossiveisPlataformas.begin(), posicoesPossiveisPlataformas.end());

		for (int i = 0; i < numPlataformas && i < posicoesPossiveisPlataformas.size(); i++) {
			criarPlataformas(posicoesPossiveisPlataformas[i], { 300.f, TAMANHO_PLATAFORMA_Y });
		}
		// SORTEIO SOLDADOS

		int numSoldados = 3 + rand() % 4; // 3 a 6

		std::random_shuffle(posicoesPossiveisSoldados.begin(), posicoesPossiveisSoldados.end());

		for (int i = 0; i < numSoldados && i < posicoesPossiveisSoldados.size(); i++) {
			criarSoldados(posicoesPossiveisSoldados[i]);
		}
		// SORTEIO MEDUSAS

		int numMinotauros = 3 + rand() % 4; // 3 a 6

		std::random_shuffle(posicoesPossiveisMedusas.begin(), posicoesPossiveisMedusas.end());

		for (int i = 0; i < numMinotauros && i < posicoesPossiveisMedusas.size(); i++) {
			criarMedusas(posicoesPossiveisMedusas[i]);
		}

		//SORTEIO ESPINHOS

		int numLamas = 3 + rand() % 4; // 3 a 6
		std::random_shuffle(posicoesPossiveisEspinhos.begin(), posicoesPossiveisEspinhos.end());


		for (int i = 0; i < numLamas && i < posicoesPossiveisEspinhos.size(); i++) {
			criarEspinhos(posicoesPossiveisEspinhos[i]);
		}



		arquivo.close();

	}

}