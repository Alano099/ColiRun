#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>
#include "Entidade.h"
#include "Gerenciador_Grafico.h"

using namespace std;

int main() {


	Gerenciadores::Gerenciador_Grafico* pGG = Gerenciadores::Gerenciador_Grafico::get_instance();

	Entidades::Entidade jogador({ 50, 50 }, { 50, 50 }, sf::Color::Green);
	Entidades::Entidade alvo({ 50,50 }, { 400,50 }, sf::Color::Blue);
	Entidades::Entidade obstaculo({ 50,100 }, { 200,50 }, { sf::Color::Red });


	bool moving = false;

	while (pGG->abreJanela()) {



		//Update scene

		//Sempre andando pra direita
		jogador.mover(1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			jogador.mover(0, -1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			jogador.mover(0, 1);

		//Alvo encontrado vc vence
		if (jogador.intercepta(alvo))
			pGG->fechajanela();
		if (jogador.intercepta(obstaculo)) {

			jogador.resetarPosicao();
			//playerRect.move(-1, 0);
		}

 		//Render cycle 
		pGG->limpar();

		pGG->desenhar(jogador.getCorpo());
		pGG->desenhar(alvo.getCorpo());
		pGG->desenhar(obstaculo.getCorpo());

		pGG->mostrar();




	}

	return 0;

}