#pragma once

#include "../stdafx/stdafx.h"
#include "../IDs/IDs.h"
#include "Gerenciador_Grafico.h"
#include "Math.h"

class Ente
{
protected:
	const IDs::IDs ID;
	static Gerenciadores::Gerenciador_Grafico* pGG;
	sf::Vector2f posicao;
	sf::Vector2f tamanho;

public:
	// Construtor explicit para evitar conversões implícitas
	Ente(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(0.f, 0.f), const IDs::IDs ID);
	virtual ~Ente();
	const IDs::IDs getID() const { return ID; }
	virtual void desenhar() = 0;
	virtual void executar(float dt) = 0;
	virtual void inicializar() = 0;
};