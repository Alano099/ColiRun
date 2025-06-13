#pragma once

#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "plataforma.h"
#include "ListaEntidades.h"
#include "Gerenciador_Grafico.h"
#include "MainMenu.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Colisoes.h"
#include "AnimacaoEstatica.h"
#include "Inimigo.h"

class ColiRun {

private:
	Gerenciadores::Gerenciador_Grafico* pGG;
	Gerenciadores::Gerenciador_Estado* pEG;
	Gerenciadores::Gerenciador_Eventos* pGE;


	Entidades::Personagens::Jogador* p1;

	Lista::ListaEntidade listaPersonagens;
	Lista::ListaEntidade listaObstaculo;
	Gerenciadores::Gerenciador_Colisoes gerenciadorColisoes;

	
	ElementosGraficos::AnimacaoEstatica fundo;

public:
	ColiRun();
	~ColiRun();

	void executar();

};