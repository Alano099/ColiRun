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

Gerenciador_Grafico::Gerenciador_Grafico() {
	janela = new sf::RenderWindow(sf::VideoMode(800, 600), "ColiRun");
	janela->setFramerateLimit(60);
}

Gerenciador_Grafico::~Gerenciador_Grafico() {
	delete janela;
}

sf::RenderWindow* Gerenciador_Grafico::getJanela() {
	return janela;
}

void Gerenciador_Grafico::desenhar(sf::RectangleShape corpo) {
	if (abreJanela()) {
		janela->draw(corpo);
	}
}
void Gerenciador_Grafico::desenhar(sf::CircleShape corpo) {
	if (abreJanela()) {
		janela->draw(corpo);
	}
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
}

void Gerenciador_Grafico::fechajanela() {
	janela->close();
}

const bool Gerenciador_Grafico::abreJanela() {
	return (janela->isOpen());
}
void Gerenciador_Grafico::atualizarTempo()
{
	dt = relogio.getElapsedTime().asSeconds();
	relogio.restart();
}
}
