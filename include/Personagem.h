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
		
		sf::Vector2f velocidadeMaxima;
		int vida;
		bool olhandoEsquerda;
		bool ativo;
		bool colidiu;
		sf::RectangleShape ataque;
		bool podeAtacar;
		float tempoAtaque;
		bool estaAtacando;
		float ataqueCooldown;
		int vidaMax;
		bool emKnockback;
		float tempoKnockback;

		ElementosGraficos::AnimacaoMovimento sprite;

	public:

		~Personagem();

		Personagem(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs id, int vida ,bool ativo = true, bool olhandoEsquerda = true);

		const int getVida() const;

		virtual void desenhar();

		virtual void executar(float dt) = 0;

		virtual void inicializar() = 0;

		virtual void colidir(Entidade* outraEntidade, sf::Vector2f intercepta) = 0;

		virtual void atacar(float dt) = 0;

		bool getAtacando() { return estaAtacando; }

		void tomarDano(const int dano);

		void moverNaColisao(sf::Vector2f instercepta, sf::Vector2f outraPos);

		const bool estaOlhandoEsquerda() const;

		const bool estaAtivo() const;

		sf::FloatRect getHitbox() const;

		sf::FloatRect getAtaqueHitbox() const;

		void desenharBarraVida();

		void setEmKnockback(bool k) { emKnockback = k; }
		bool getEmKnockback() { return emKnockback; }

		void setTempoKnockback(float t) { tempoKnockback = t; }
	};



	}
}

