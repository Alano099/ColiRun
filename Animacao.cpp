#include "Animacao.h"

namespace ElementosGraficos {

	Gerenciadores::Gerenciador_Grafico* Animacao::pGG = Gerenciadores::Gerenciador_Grafico::get_instance();

	Animacao::Animacao():corpo(){}

	Animacao::~Animacao() {}
	
	void Animacao::desenhar() {
		
		pGG->desenhar(&corpo);
		//corpo.setSize(sf::Vector2f(100.f, 100.f)); // temporário, só pra aparecer
	}

}