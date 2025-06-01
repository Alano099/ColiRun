#include "Gerenciador_Eventos.h"

#include <iostream>

using namespace std;

namespace Gerenciadores {

	Gerenciador_Eventos* Gerenciador_Eventos::pGE = nullptr;
	Gerenciador_Grafico* Gerenciador_Eventos::pGG = Gerenciador_Grafico::get_instance();

	Gerenciador_Eventos::Gerenciador_Eventos() : evento() {
		if (pGG == nullptr) {
			//cout << "Erro ao criar gerenciador de eventos : gerenciador grafico nao foi criado" << endl;
			exit(1);
		}

		
	}

	Gerenciador_Eventos::~Gerenciador_Eventos() {
		pGG = nullptr;
		pGE = nullptr;
		
	}

	Gerenciador_Eventos* Gerenciador_Eventos::getGerEventos() {
		if (pGE == nullptr) {
			pGE = new Gerenciador_Eventos();
		}

		return pGE;
	}

	void Gerenciador_Eventos::tratarEventoJanela() {
		pGG->fechajanela();
	}

    // Método para tratar eventos de movimento para dois jogadores
    void Gerenciador_Eventos::tratarEventoJogador(int jogadorID) {
        while (pGG->getJanela()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                pGG->fechajanela();
            }
            if (evento.type == sf::Event::KeyPressed) {
                if (jogadorID == 1) {
                    if (evento.key.code == sf::Keyboard::W) {
                        // Jogador 1: cima
                    }
                    if (evento.key.code == sf::Keyboard::S) {
                        // Jogador 1: baixo
                    }
                    if (evento.key.code == sf::Keyboard::A) {
                        // Jogador 1: esquerda
                    }
                    if (evento.key.code == sf::Keyboard::D) {
                        // Jogador 1: direita
                    }
                }
                else if (jogadorID == 2) {
                    if (evento.key.code == sf::Keyboard::Up) {
                        // Jogador 2: cima
                    }
                    if (evento.key.code == sf::Keyboard::Down) {
                        // Jogador 2: baixo
                    }
                    if (evento.key.code == sf::Keyboard::Left) {
                        // Jogador 2: esquerda
                    }
                    if (evento.key.code == sf::Keyboard::Right) {
                        // Jogador 2: direita
                    }
                }
            }
        }
    }

	const sf::Event Gerenciador_Eventos::getEvento() const {
		return evento;
	}

	
}