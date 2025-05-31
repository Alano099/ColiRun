#pragma once

#include "stdafx/stdafx.h"
#include "IDs/IDs.h"

class Ente
{

	protected:
		const IDs::IDs ID;

	public:

		Ente(const IDs::IDs ID);
		virtual ~Ente() ;
		const IDs::IDs getID() const { return ID; }
		virtual void desenhar() = 0;
};

