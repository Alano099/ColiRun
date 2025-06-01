#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>
#include "ColiRun.h"

using namespace std;

ColiRun::ColiRun() : pGG(Gerenciadores::Gerenciador_Grafico::get_instance()), p1({ 100, 400 }, true)
	
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

		pGG->desenhar(corpoJogador);
		pGG->desenhar(chao);
		pGG->mostrar();
	}
}
