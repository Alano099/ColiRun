#pragma once

#include "Personagem.h"
#include "Gerenciador_Grafico.h"

class ColiRun {

private:
	Gerenciadores::Gerenciador_Grafico* pGG;
	Entidades::Personagens::Personagem p1;
	sf::RectangleShape chao;

public:
	ColiRun();
	~ColiRun();

	void executar();

};