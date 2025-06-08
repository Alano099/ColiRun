#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>
#include "ColiRun.h"

using namespace std;

ColiRun::ColiRun() : pGG(Gerenciadores::Gerenciador_Grafico::get_instance()), p1(new Entidades::Personagens::Jogador({100.f,200.f}, true)),
pGE(Gerenciadores::Gerenciador_Eventos::getGerEventos()), fundo(), listaObstaculo(),listaPersonagens(), gerenciadorColisoes(&listaPersonagens, &listaObstaculo)
	
{

	sf::Texture* tex = pGG->carregarTextura("assets/fundo1.png");
	sf::Vector2u texSize = tex->getSize();
	sf::Vector2f centro = pGG->getJanela()->getView().getCenter();



	//fundo.inicializar("assets/fundo1.png", centro, sf::Vector2f(texSize.x, texSize.y));

	Entidades::Entidade* tmp;

	tmp = new Entidades::Obstaculos::Plataforma(sf::Vector2f(200.f, 600.f), sf::Vector2f(700.f, 32.f));
	listaObstaculo.inserirEnt(tmp);
	
	tmp = new Entidades::Obstaculos::Plataforma(sf::Vector2f(600.f, 550.f), sf::Vector2f(100.f,100.f));
	listaObstaculo.inserirEnt(tmp);
	
	
	listaPersonagens.inserirEnt(p1);

	

	executar();
}

ColiRun::~ColiRun(){}

void ColiRun::executar() {
	float dt;

	while (pGG->abreJanela()) {

		dt = pGG->atualizarTempo();
		pGG->limpar();

		fundo.desenhar();

		listaPersonagens.executar(dt);

		listaObstaculo.executar(dt);

		gerenciadorColisoes.colidir();

		listaObstaculo.desenharEntidades();

		listaPersonagens.desenharEntidades();


		pGG->mostrar();

		pGG->centralizarView(p1->getPosicao());


	}

}
