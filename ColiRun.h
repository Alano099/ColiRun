#pragma once

#include "Personagem.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"

class ColiRun {

private:
	Gerenciadores::Gerenciador_Grafico* pGG;
	Gerenciadores::Gerenciador_Eventos* pGE;


	Entidades::Personagens::Personagem p1;
	Entidades::Personagens::Personagem p2;
	sf::RectangleShape chao;

public:
	ColiRun();
	~ColiRun();

	void executar();

};