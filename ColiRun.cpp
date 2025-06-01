#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>
#include "ColiRun.h"

using namespace std;

ColiRun::ColiRun() : pGG(Gerenciadores::Gerenciador_Grafico::get_instance()), p1({ 100, 400 }, true), p2({ 100,400 }, true), pGE(Gerenciadores::Gerenciador_Eventos::getGerEventos())
	
{
	chao.setSize({ 800, 50 });
	chao.setFillColor(sf::Color::White);
	chao.setPosition({ 0, 550 });

	executar();
}

ColiRun::~ColiRun(){}

void ColiRun::executar() {
	while (pGG->abreJanela()) {

		pGG->atualizarTempo();
		pGG->limpar();

		sf::RectangleShape corpoJogador;

		corpoJogador.setSize(p1.getTamanho());
		corpoJogador.setPosition(p1.getPosicao());
		corpoJogador.setFillColor(sf::Color::Green);

		p1.setCorpo(corpoJogador);

		corpoJogador.setFillColor(sf::Color::Blue);
		corpoJogador.setPosition(p2.getPosicao());

		p2.setCorpo(corpoJogador);

		pGE->tratarEventoJogador(&p1,&p2);

		pGG->desenhar(p1.getCorpo());
		pGG->desenhar(p2.getCorpo());

		pGG->desenhar(chao);
		pGG->mostrar();

		

	}
}
