#include "../include/Coliseu.h"

namespace Fases {

	Coliseu::Coliseu(Entidades::Personagens::Jogador* jogador1, Entidades::Personagens::Jogador* jogador2)
		: Fase(IDs::IDs::coliseu, jogador1, jogador2) {

		inicializar();

	}

	Coliseu::~Coliseu()
	{
	}

	void Coliseu::executar(float dt) {

		atualizar(dt);
		desenhar();

		if (p1->getPosicao().x >= mapaLargura) {
			faseTerminada = true;
			
		}

		if ((p1 && p1->getVida() <= 0) || (p2 && p2->getVida() <= 0)) {
			std::cout << "Um jogador morreu! Fechando o jogo...\n";
			pGG->getJanela()->close();
		}

	}

	void Coliseu::atualizar(float dt) {
		listaJogadores.executar(dt);
		listaInimigos.executar(dt);
		listaObstaculo.executar(dt);
		gerenciar_colisoes();

		float mediaVel = 0.f;
		if (p1 && p2)
			mediaVel = (p1->getVelocidade().x + p2->getVelocidade().x) / 2.f;
		else if (p1)
			mediaVel = p1->getVelocidade().x;

		fundo.atualizar(dt, mediaVel / 10.f);

	}

	void Coliseu::desenhar() {

		fundo.desenhar(pGG->getJanela());
		pGG->getJanela()->draw(chao);

		listaObstaculo.desenharEntidades();
		listaJogadores.desenharEntidades();
		listaInimigos.desenharEntidades();
	}

	void Coliseu::inicializar() {

		gerenciadorColisoes.setListaJogadores(&listaJogadores);
		gerenciadorColisoes.setListaInimigos(&listaInimigos);
		gerenciadorColisoes.setListaObstaculos(&listaObstaculo);

		// Carrega mapa
		carregarMapa("assets/mapas/mapaColiseu.txt");

		// Inicializa fundo com o tamanho do mapa
		fundo.inicializar("assets/fundos/coliseu.png", sf::Vector2f(mapaLargura, mapaAltura));

		// Insere jogadores na lista
		
		// Cria ch�o com textura repetida
		sf::Texture* texturaChao = pGG->carregarTextura("assets/obstaculos/chao.jpeg");
		texturaChao->setRepeated(true);

		sf::Vector2f tamanhoChao(mapaLargura, 5000.f);

		chao.setSize(tamanhoChao);
		chao.setOrigin(0.f, 0.f); // Origem no canto superior esquerdo
		chao.setPosition(0.f, CHAO + 32.f); // Posiciona na base do mapa

		chao.setTexture(texturaChao);
		chao.setTextureRect(sf::IntRect(0, 0, static_cast<int>(tamanhoChao.x), static_cast<int>(tamanhoChao.y)));


		//std::cout << "Coliseu inicializado com largura = " << mapaLargura << " e altura = " << mapaAltura << std::endl;
	}

	void Coliseu::carregarMapa(const std::string& caminho) {
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
		std::vector<sf::Vector2f> posicoesPossiveisLamas;
		std::vector<sf::Vector2f> posicoesPossiveisMinotauros;


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
					posicoesPossiveisMinotauros.push_back({ x, y });
					//criarMinotauros({ x, y });
					break;

				case 'L':
					posicoesPossiveisLamas.push_back({ x, y });
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

		int numPlataformas = 3 + rand() % 3; // 3 a 5

		std::random_shuffle(posicoesPossiveisPlataformas.begin(), posicoesPossiveisPlataformas.end());

		for (int i = 0; i < numPlataformas && i < posicoesPossiveisPlataformas.size(); i++) {
			criarPlataformas(posicoesPossiveisPlataformas[i], { 100.f, TAMANHO_PLATAFORMA_Y });
		}

		// SORTEIO MINOTAUROS

		int numMinotauros = 3 + rand() % 4; // 3 a 6

		std::random_shuffle(posicoesPossiveisMinotauros.begin(), posicoesPossiveisMinotauros.end());

		for (int i = 0; i < numMinotauros && i < posicoesPossiveisMinotauros.size(); i++) {
			criarMinotauros(posicoesPossiveisMinotauros[i]);
		}

		// SORTEIO SOLDADOS

		int numSoldados = 3 + rand() % 4; // 3 a 6

		std::random_shuffle(posicoesPossiveisSoldados.begin(), posicoesPossiveisSoldados.end());

		for (int i = 0; i < numSoldados && i < posicoesPossiveisSoldados.size(); i++) {
			criarSoldados(posicoesPossiveisSoldados[i]);
		}


		//SORTEIO LAMAS

		int numLamas = 3 + rand() % 4; // 3 a 6
		std::random_shuffle(posicoesPossiveisLamas.begin(), posicoesPossiveisLamas.end());


		for (int i = 0; i < numLamas && i < posicoesPossiveisLamas.size(); i++) {
			criarLamas(posicoesPossiveisLamas[i]);
		}


		arquivo.close();
	}

	void Coliseu::criarLamas(sf::Vector2f pos)
	{
		Entidades::Entidade* tmp = nullptr;

		tmp = new Entidades::Obstaculos::Lama({pos.x,pos.y + 10.f}, { LAMA_TAMANHO_X, LAMA_TAMANHO_Y }, IDs::IDs::lama);
		listaObstaculo.inserirEnt(tmp);
	}

	void Coliseu::criarMinotauros(sf::Vector2f pos)
	{
		Entidades::Personagens::Inimigos::Minotauro* inimigo =
			new Entidades::Personagens::Inimigos::Minotauro(pos, { MINOTAURO_TAMANHO_X,MINOTAURO_TAMANHO_Y }, IDs::IDs::minotauro,100);
		inimigo->definirLimitesDePatrulha(MINOTAURO_LIMITE_PATRULHA);
		if(p1&&p2)
			inimigo->setJogador(p1, p2);
		else if (p1)
			inimigo->setJogador(p1, nullptr);
		listaInimigos.inserirEnt(inimigo);
	}

}
