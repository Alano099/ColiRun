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
	Math::CoordF posicao;
	Math::CoordF tamanho;

public:
	// Construtor explicit para evitar conversões implícitas
	Ente(Math::CoordF posicao = Math::CoordF(0.f, 0.f), Math::CoordF tamanho = Math::CoordF(0.f, 0.f), const IDs::IDs ID);
	virtual ~Ente();
	const IDs::IDs getID() const { return ID; }
	virtual void desenhar() = 0;
	virtual void executar(float dt) = 0;
	virtual void inicializar() = 0;
};