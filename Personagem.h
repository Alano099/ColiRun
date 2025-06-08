#pragma once
#include "Entidade.h"
#include "AnimacaoMovimento.h"

#define PLAYER_SIZE_X 85.f
#define PLAYER_SIZE_Y 32.f

constexpr auto PARADO_PATH = "..\\assets\\jogador_parado.png";

namespace Entidades {

	namespace Personagens {

	class Personagem :public Entidade
	{
	protected:
		sf::Vector2f velocidade;
		int vida;
		bool olhandoEsquerda;
		bool ativo;

		ElementosGraficos::AnimacaoMovimento sprite;

	public:

		~Personagem();

		Personagem(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs id, int vida = 1,bool ativo = true, bool olhandoEsquerda = true);

		const int getVida() const;

		virtual void desenhar();

		virtual void atualizar(float dt) = 0;

		virtual void inicializar() = 0;

		virtual void colidir(Entidade* outraEntidade, sf::Vector2f intercepta) = 0;

		void tomarDano(const int dano);

		void moverNaColisao(sf::Vector2f instercepta, sf::Vector2f outraPos);

		const bool estaOlhandoEsquerda() const;

		const bool estaAtivo() const;

	};



	}
}

