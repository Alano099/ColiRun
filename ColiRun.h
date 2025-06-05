#pragma once

#include "Personagem.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "AnimacaoEstatica.h"

class ColiRun {

private:
	Gerenciadores::Gerenciador_Grafico* pGG;
	Gerenciadores::Gerenciador_Eventos* pGE;


	Entidades::Personagens::Personagem p1;
	ElementosGraficos::AnimacaoEstatica fundo;

public:
	ColiRun();
	~ColiRun();

	void executar();

};