#include "Fase.h"

namespace Fases
{
	Fase::Fase(int id):
		Estados::Estado(id),
		jogadores(),
		corpo(),
		carregado(false),
		nao_nasceu(0)
		//obstaulos()
		//inimigos()
		//Gerenciador_Colisoes()
	{
		

		gerenciador_Eventos = Gerenciadores::Gerenciador_Eventos::getGerEventos();
	}

}