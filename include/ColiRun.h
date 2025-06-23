#pragma once  

#include "Gerenciador_Grafico.h"  
#include "Gerenciador_Eventos.h"  
#include "Coliseu.h"  
#include "Masmorra.h"  
#include "Jogador.h"  
#include "Menu.h"

class ColiRun  
{  
private:  
   Gerenciadores::Gerenciador_Grafico* pGG;  
   

   // Jogadores como atributos  
   Entidades::Personagens::Jogador p1;  
   Entidades::Personagens::Jogador p2;  

   Fases::Coliseu coliseu;  
   Fases::Masmorra masmorra;  

   Menu menu;  

   Fases::Fase* faseAtual;  

public:  
   ColiRun();  
   ~ColiRun();  

   void executar();  
};
