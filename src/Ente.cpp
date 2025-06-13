#include "../include/Ente.h"

Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::get_instance());

Ente::Ente(const IDs::IDs ID):ID(ID)
{
}
Ente::~Ente()
{

}