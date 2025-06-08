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
    void Gerenciador_Eventos::tratarEventoJogador(Entidades::Personagens::Jogador* p1, Entidades::Personagens::Jogador* p2) {

        const float velocidade = 5.f;

        while (pGG->getJanela()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                pGG->fechajanela();
            }
            if (evento.type == sf::Event::KeyPressed) {
                if (p1) {
                    if (evento.key.code == sf::Keyboard::W) {
                        p1->setPosition(p1->getPosicao() + sf::Vector2f(0.f, -velocidade));
                    }
                    if (evento.key.code == sf::Keyboard::S) {
                        p1->setPosition(p1->getPosicao() + sf::Vector2f(0.f, velocidade));
                    }
                    if (evento.key.code == sf::Keyboard::A) {
                        p1->setPosition(p1->getPosicao() + sf::Vector2f(-velocidade, 0.f));
                    }
                    if (evento.key.code == sf::Keyboard::D) {
                        p1->setPosition(p1->getPosicao() + sf::Vector2f(velocidade, 0.f));
                    }
                }
                if (p2) {
                    if (evento.key.code == sf::Keyboard::Up) {
                        p2->setPosition(p2->getPosicao() + sf::Vector2f(0.f, -velocidade));
                    }
                    if (evento.key.code == sf::Keyboard::Down) {
                        p2->setPosition(p2->getPosicao() + sf::Vector2f(0.f, velocidade));
                    }
                    if (evento.key.code == sf::Keyboard::Left) {
                        p2->setPosition(p2->getPosicao() + sf::Vector2f(-velocidade, 0.f));
                    }
                    if (evento.key.code == sf::Keyboard::Right) {
                        p2->setPosition(p2->getPosicao() + sf::Vector2f(velocidade, 0.f));
                    }
                }
            }
        }
    }

	const sf::Event Gerenciador_Eventos::getEvento() const {
		return evento;
	}

	
}