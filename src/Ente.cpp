#include "../include/Ente.h"

Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::get_instance());

Ente::Ente(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(0.f, 0.f),const IDs::IDs ID):ID(ID)
{
}
Ente::~Ente()
{

}