#include "Ente.h"

Ente::Ente(const IDs::IDs ID):ID(ID)
{
	pGG = Gerenciadores::Gerenciador_Grafico::get_instance();
}
Ente::~Ente(){}