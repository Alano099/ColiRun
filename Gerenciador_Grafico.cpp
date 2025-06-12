#include "Gerenciador_Grafico.h"


float Gerenciadores::Gerenciador_Grafico::dt = 0.f;

namespace Gerenciadores {

	Gerenciador_Grafico* Gerenciador_Grafico::instance = nullptr;


	Gerenciador_Grafico* Gerenciador_Grafico::get_instance() {
		if (instance == nullptr) {
			instance = new Gerenciador_Grafico();
		}
		return instance;
	}

	Gerenciador_Grafico::Gerenciador_Grafico():
		janela(new sf::RenderWindow(sf::VideoMode(LARGURA,ALTURA), "ColiRun")),
		view(sf::Vector2f(LARGURA/2,ALTURA/2),sf::Vector2f(LARGURA,ALTURA)),
		mapaTexturas(),
		relogio() 
	{
			fonte = new sf::Font();
			if(!fonte->loadFromFile(FONT_PATH))
			{
				std::cout << "FONTE NAO ENCONTRADA NO CAMINHO: " << std::endl;
				exit(1);
			}
			relogio.restart();

	}

	Gerenciador_Grafico::~Gerenciador_Grafico() {
		std::map<const char*, sf::Texture*>::iterator it;
		for (it = mapaTexturas.begin(); it != mapaTexturas.end(); it++)
			delete (it->second);
		delete(janela);
		delete(fonte);

	}

	sf::RenderWindow* Gerenciador_Grafico::getJanela() {
		return janela;
	}

	void Gerenciador_Grafico::desenhar(sf::RectangleShape* corpo) {
			janela->draw(*corpo);
	}
	
	void Gerenciador_Grafico::desenhar(sf::CircleShape* corpo) {
			janela->draw(*corpo);
	}
	
	void Gerenciador_Grafico::desenhar(sf::Text* texto) {	
			janela->draw(*texto);
	}

	void Gerenciador_Grafico::mostrar() {
		if (abreJanela()) {
			janela->display();
		}
	}

	void Gerenciador_Grafico::limpar() {
		if (abreJanela()) {
			janela->clear();
		}

		sf::Event evento;
		while (janela->pollEvent(evento)) {
			switch (evento.type) {
			case sf::Event::Closed:
				fechajanela();
				break;
			default:
				break;
			}
		}

	}

	void Gerenciador_Grafico::fechajanela() {
		janela->close();
	}

	const bool Gerenciador_Grafico::abreJanela() {
		return (janela->isOpen());
	}



	float Gerenciador_Grafico::atualizarTempo()
	{
		float dt = relogio.getElapsedTime().asSeconds() + 0.0002f;
		relogio.restart();

		return dt;

	}
	sf::Texture* Gerenciador_Grafico::carregarTextura(const char* caminho)
	{
		
		std::map<const char*, sf::Texture*>::iterator it = mapaTexturas.begin();
		while (it != mapaTexturas.end()) {

			if (!strcmp(it->first, caminho))
				return it->second;
			it++;

		}

		sf::Texture* tex = new sf::Texture();

		if (!tex->loadFromFile(caminho)) {
			std::cout << "TEXTURA NAO ENCONTRADA NO CAMINHO: " << caminho << std::endl;
			exit(1);
		}

		mapaTexturas.insert(std::pair<const char*, sf::Texture*>(caminho, tex));

		return tex;

	}
	sf::Vector2u Gerenciador_Grafico::getTamjanela()
	{
		return janela->getSize();
	}
	void Gerenciador_Grafico::lidarTamJanela()
	{

		float aspectRatio = float(janela->getSize().x / float(janela->getSize().y));
		view.setSize(sf::Vector2f(ALTURA * aspectRatio, ALTURA));
		janela->setView(view);

	}
	void Gerenciador_Grafico::centralizarView(sf::Vector2f pos)
	{

		view.setCenter(sf::Vector2f(pos.x, pos.y));
		janela->setView(view);

	}
	sf::Font* Gerenciador_Grafico::getFonte() const{
		return fonte;
	}
}
