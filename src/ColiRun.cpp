#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>
#include "../include/ColiRun.h"

using namespace std;

ColiRun::ColiRun() : pGG(Gerenciadores::Gerenciador_Grafico::get_instance()), p1(new Entidades::Personagens::Jogador({ 100.f,200.f }, true)),
pGE(Gerenciadores::Gerenciador_Eventos::get_instance()), fundo(), listaObstaculo(), listaPersonagens(), gerenciadorColisoes(&listaPersonagens, &listaObstaculo)

{

	sf::Texture* tex = pGG->carregarTextura("assets/fundos/coliseu.png");
	sf::Vector2u texSize = tex->getSize();
	sf::Vector2f centro = pGG->getJanela()->getView().getCenter();

	Entidades::Personagens::Inimigos::Inimigo* inimigo = new Entidades::Personagens::Inimigos::Inimigo(sf::Vector2f(700.f, 200.f));
	inimigo->setJogador(p1); // seguir jogador
	listaPersonagens.inserirEnt(inimigo);

	fundo.inicializar("assets/fundos/coliseu.png", centro, sf::Vector2f(static_cast<float>(1320), static_cast<float>(440)));


	sf::Vector2u janelaSize = pGG->getJanela()->getSize();
	sf::Vector2f escala(
		static_cast<float>(janelaSize.x) / static_cast<float>(texSize.x),
		static_cast<float>(janelaSize.y) / static_cast<float>(texSize.y)
	);

	fundo.setScale(escala);


	Entidades::Entidade* tmp;

	tmp = new Entidades::Obstaculos::Plataforma(sf::Vector2f(399.f, 600.f), sf::Vector2f(1800.f, 32.f));
	listaObstaculo.inserirEnt(tmp);

	tmp = new Entidades::Obstaculos::Plataforma(sf::Vector2f(600.f, 550.f), sf::Vector2f(100.f, 100.f));
	listaObstaculo.inserirEnt(tmp);


	listaPersonagens.inserirEnt(p1);



	executar();
}

ColiRun::~ColiRun() {}

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

		pGG->centralizarView(fundo.getPosicao());


	}

}