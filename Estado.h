#pragma once

namespace Gerenciadores
{
	class Gerenciador_Estado;
}

namespace Estados
{
	class Estado
	{
	protected:
		static Gerenciadores::Gerenciador_Estado* pGE;
		const int id_estado;
	public:
		Estado(int id = -1);

		virtual ~Estado();

		void setGerenciadorEstado(Gerenciadores::Gerenciador_Estado* pGE);

		int getId() const;

		const bool get_ativo();
		
		virtual void executar() = 0;
		virtual void reiniciar();
	};
}