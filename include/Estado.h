#pragma once

namespace Gerenciadores
{
	class Gerenciador_Estado;
}

namespace Estados
{
	enum estadoID
	{
		nulo = -1,
		mainMenu = 0, 
		novoJogo,
		jogador,
		configuracoes,
		fimJogo
	};
	class Estado
	{
	protected:
		Gerenciadores::Gerenciador_Estado* pEG;
		estadoID id;
	public:
		Estado(Gerenciadores::Gerenciador_Estado* pEG = nullptr, Estados::estadoID id = nulo);

		virtual ~Estado();

		void setGerenciadorEstado(Gerenciadores::Gerenciador_Estado* pEG);
		
		void mudarEstado(Estados::estadoID id);
		
		Estados::estadoID getID() const;
		
		virtual void atualizar(float dt) = 0;
		virtual void renderizar() = 0;
		virtual void resetarEstado() = 0;
		
	};
}