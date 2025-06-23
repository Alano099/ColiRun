#include "../include/Masmorra.h"

namespace Fases {

	Masmorra::Masmorra(Entidades::Personagens::Jogador* jogador1, Entidades::Personagens::Jogador* jogador2)
		: Fase(IDs::IDs::masmorra, jogador1, jogador2),inimigosVivos(MAX_INIMIGOS) {
		inicializar();
	}

	Masmorra::~Masmorra() {
		
	}

	void Masmorra::executar(float dt) {

		atualizar(dt);
		desenhar();

		if ((p1 && p1->getVida() <= 0) || (p2 && p2->getVida() <= 0)) {
			std::cout << "Um jogador morreu! Fechando o jogo...\n";
			pGG->getJanela()->close();
		}

	}

	void Masmorra::atualizar(float dt) {
		listaJogadores.executar(dt);
		listaInimigos.executar(dt);
		listaObstaculo.executar(dt);
		listaProjetil.executar(dt);
		gerenciar_colisoes();
		fundo.atualizar(dt, p1->getVelocidade().x / 10);
		if (listaInimigos.getTamanho() == 0 && !faseTerminada) {
			faseTerminada = true;
		}
		if (faseTerminada) {
			sf::Text textoVitoria;
			sf::Font fonte;
			if (!fonte.loadFromFile("assets/PressStart2P-Regular.ttf")) {
				std::cerr << "Erro carregando fonte!\n";
			}

			textoVitoria.setFont(fonte);
			textoVitoria.setString("VOCE VENCEU!");
			textoVitoria.setCharacterSize(60);
			textoVitoria.setFillColor(sf::Color::Yellow);
			textoVitoria.setPosition(300.f, 300.f);

			pGG->getJanela()->draw(textoVitoria);
			pGG->mostrar();

			// Espera ENTER para sair
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				pGG->getJanela()->close();
			}

			return; // não segue pro resto do loop se já venceu
		}
	}

	void Masmorra::desenhar() {
		fundo.desenhar(pGG->getJanela());
		pGG->getJanela()->draw(chao);
		listaObstaculo.desenharEntidades();
		listaJogadores.desenharEntidades();
		listaInimigos.desenharEntidades();
		listaProjetil.desenharEntidades();



	}

	void Masmorra::inicializar() {

		gerenciadorColisoes.setListaJogadores(&listaJogadores);
		gerenciadorColisoes.setListaInimigos(&listaInimigos);
		gerenciadorColisoes.setListaObstaculos(&listaObstaculo);
		gerenciadorColisoes.setListaProjeteis(&listaProjetil);

		// Carrega mapa
		carregarMapa("assets/mapas/mapaMasmorra.txt");

		// Inicializa fundo com o tamanho do mapa
		fundo.inicializar("assets/fundos/masmorra.jpg", sf::Vector2f(mapaLargura, mapaAltura));

		// Insere jogadores na lista
		

		// Cria chão com textura repetida
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

	Entidades::Projetil* Masmorra::criarProjetil(sf::Vector2f pos)
	{
		Entidades::Projetil* projetil = new Entidades::Projetil(pos, { PROJETIL_TAMANHO_X, PROJETIL_TAMANHO_Y }, IDs::IDs::projetil, false);
		projetil->inicializar();
		listaProjetil.inserirEnt(projetil);
		return projetil;
	}

	
	void Masmorra::criarMedusas(sf::Vector2f pos)
	{
		Entidades::Personagens::Inimigos::Medusa* inimigo =
			new Entidades::Personagens::Inimigos::Medusa(pos, { MEDUSA_TAMANHO_X,MEDUSA_TAMANHO_Y }, IDs::IDs::medusa,70);
		inimigo->definirLimitesDePatrulha(MEDUSA_LIMITE_PATRULHA);
		if (p1 && p2)
			inimigo->setJogador(p1, p2);
		else if (p1)
			inimigo->setJogador(p1, nullptr);

		Entidades::Projetil* projetil = criarProjetil(pos);

		inimigo->setProjetil(projetil);

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