#include "../include/Personagem.h"
#include "../include/Animacao.h"

namespace Entidades {

	namespace Personagens {
		Personagem::~Personagem()
		{
		}

		Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs id, int vida, bool ativo, bool olhandoEsquerda)
			: Entidade(pos, tam, id), vida(vida), ativo(ativo), olhandoEsquerda(olhandoEsquerda),colidiu(false),ataqueCooldown(0.f),
				estaAtacando(false),podeAtacar(true),tempoAtaque(0.f), emKnockback(false), tempoKnockback(0.f),vidaMax(vida){

			
			

		}

		const int Personagem::getVida() const
		{
			return vida;
		}

		void Personagem::desenhar()
		{
			desenharBarraVida();
			sprite.desenhar();
			sf::RectangleShape debug;
			
			
			/*
			
			
			debug.setFillColor(sf::Color::Transparent);
			debug.setOutlineColor(sf::Color::Red);
			debug.setOutlineThickness(1.f);
			debug.setSize(tam);                    // tam = this->tam da classe Entidade
			debug.setOrigin(tam.x / 2, tam.y / 2);
			debug.setPosition(getPosicao());       // posi��o central da entidade
			Gerenciadores::Gerenciador_Grafico::get_instance()->getJanela()->draw(debug);
			
			
			*/
			
			if (!podeAtacar) {
				ataque.setFillColor(sf::Color(255, 0, 0, 100)); // vermelho semi-transparente
				ataque.setOutlineColor(sf::Color::Yellow);
				ataque.setOutlineThickness(2.f);
				Gerenciadores::Gerenciador_Grafico::get_instance()->getJanela()->draw(ataque);
			}
			
		}

		void Personagem::tomarDano(const int dano)
		{
			vida -= dano;
			if (vida < 0)
				vida = 0;

			if (vida == 0) {
				ativo = false;  // <<< aqui voc� marca que o personagem "morreu"
			}
		}

		void Personagem::moverNaColisao(sf::Vector2f intercepta, sf::Vector2f outraPos)
		{
			if (intercepta.x > intercepta.y) {
				if (pos.x < outraPos.x)
					pos.x += intercepta.x;
				else
					pos.x -= intercepta.x;
				velocidade.x = 0.0f;
			}

			else {

				if (pos.y < outraPos.y)
					pos.y += intercepta.y;
				else
					pos.y -= intercepta.y;
				velocidade.y = 0.0f;

			}

		}

		const bool Personagem::estaOlhandoEsquerda() const
		{
			return olhandoEsquerda;
		}

		const bool Personagem::estaAtivo() const
		{
			return ativo;
		}

		sf::FloatRect Personagem::getHitbox() const
		{
			return sprite.getGlobalBounds();
		}

		sf::FloatRect Personagem::getAtaqueHitbox() const
		{
			return ataque.getGlobalBounds();
		}

		void Personagem::desenharBarraVida()
		{
			sf::RectangleShape barraFundo;
			barraFundo.setSize(sf::Vector2f(40.f, 5.f));
			barraFundo.setFillColor(sf::Color::Red);
			barraFundo.setPosition(pos.x - 20.f, pos.y - tam.y / 2.f - 10.f);

			float proporcao = static_cast<float>(vida) / static_cast<float>(vidaMax);
			if (proporcao < 0.f) proporcao = 0.f; // N�o deixar barra negativa

			sf::RectangleShape barraAtual;
			barraAtual.setSize(sf::Vector2f(40.f * proporcao, 5.f));
			barraAtual.setFillColor(sf::Color::Green);
			barraAtual.setPosition(pos.x - 20.f, pos.y - tam.y / 2.f - 10.f);

			pGG->getJanela()->draw(barraFundo);
			pGG->getJanela()->draw(barraAtual);
		}

		
		
	}

}