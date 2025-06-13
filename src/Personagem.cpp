#include "../include/Personagem.h"
#include "../include/Animacao.h"

namespace Entidades {

	namespace Personagens {
		Personagem::~Personagem()
		{
		}

		Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs id, int vida, bool ativo, bool olhandoEsquerda)
			: Entidade(pos, tam, id), vida(vida), ativo(ativo), olhandoEsquerda(olhandoEsquerda) {
		}

		const int Personagem::getVida() const
		{
			return vida;
		}

		void Personagem::desenhar()
		{
			sprite.desenhar();
			sf::RectangleShape debug;
			debug.setFillColor(sf::Color::Transparent);
			debug.setOutlineColor(sf::Color::Red);
			debug.setOutlineThickness(1.f);
			debug.setSize(tam);                    // tam = this->tam da classe Entidade
			debug.setOrigin(tam.x / 2, tam.y / 2);
			debug.setPosition(getPosicao());       // posição central da entidade
			Gerenciadores::Gerenciador_Grafico::get_instance()->getJanela()->draw(debug);
		}

		void Personagem::tomarDano(const int dano)
		{
			vida -= dano;
			if (vida <= 0)
				ativo = false;
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

		
		
	}

}