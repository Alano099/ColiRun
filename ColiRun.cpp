#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>
#include "ColiRun.h"

using namespace std;

ColiRun::ColiRun() : pGG(Gerenciadores::Gerenciador_Grafico::get_instance()), p1({ 100, 400 }, true), 
pGE(Gerenciadores::Gerenciador_Eventos::getGerEventos()), fundo("assets/fundo1.png", sf::Vector2f(0.0f,0.0f),sf::Vector2f(1280,720),1)
	
{
	executar();
}

ColiRun::~ColiRun(){}

void ColiRun::executar() {
	float dt;

	while (pGG->abreJanela()) {

		dt = pGG->atualizarTempo();
		pGG->limpar();

		p1.atualizar(dt);

		fundo.desenhar();
		p1.desenhar();

		pGG->mostrar();

	}

}
