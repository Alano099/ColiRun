#pragma once

#include "../stdafx/stdafx.h"
#include "../IDs/IDs.h"
#include "Gerenciador_Grafico.h"

class Ente
{
protected:
	const IDs::IDs ID;
	static Gerenciadores::Gerenciador_Grafico* pGG;

public:
	// Construtor explicit para evitar conversões implícitas
	Ente(const IDs::IDs ID);
	virtual ~Ente();
	const IDs::IDs getID() const { return ID; }
	virtual void desenhar() = 0;
	virtual void atualizar(float dt) = 0;
	virtual void inicializar() = 0;
};