#include "../include/Ente.h"

Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::get_instance());

Ente::Ente(Math::CoordF posicao = Math::CoordF(0.f, 0.f), Math::CoordF tamanho = Math::CoordF(0.f, 0.f),const IDs::IDs ID):ID(ID)
{
}
Ente::~Ente()
{

}