#include "../include/Projetil.h"

namespace Entidades {


	Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs id,bool ativo):Entidade(pos,tam,id),ativo(ativo)
	{
		inicializar();
	}

	Projetil::~Projetil()
	{
	}

	void Projetil::setAtivo(bool ativo)
	{
		this->ativo = ativo;
	}

	bool Projetil::getAtivo() const
	{
		return ativo;
	}

	void Projetil::executar(float dt)
	{
		if (ativo) {
			// Aplica gravidade
			velocidade.y += GRAVIDADE * dt;

			pos += velocidade * dt;
			corpo.setPosition(pos);

			if (pos.x < 0.f || pos.x > 2000.f || pos.y > 600.f) {
				ativo = false;
			}
		}
	}
	void Projetil::desenhar()
	{

		if (!ativo) return;

		pGG->getJanela()->draw(corpo);
	}

	void Projetil::inicializar()
	{
		sf::Texture* textura = pGG->carregarTextura("assets/projetil.png");

		corpo.setTexture(textura);
		corpo.setSize(tam);
		
	}

	void Projetil::setDirecao(float dir)
	{
		velocidade.x = dir * 600.f;          // Velocidade horizontal
		velocidade.y = -300.f;               // Velocidade vertical inicial (negativa → sobe primeiro)
	}

	void Projetil::colidir(Entidade* outraEntidade, sf::Vector2f intercepta)
	{
	}

	void Projetil::setDirecaoComAngulo(float anguloGraus, float dir)
	{
		float anguloRad = anguloGraus * 3.14159f / 180.f;
		float velocidadeTotal = 660.f;  // ou outro valor

		velocidade.x = dir * velocidadeTotal * cos(anguloRad);
		velocidade.y = -velocidadeTotal * sin(anguloRad);  // Negativo → sobe primeiro
	}

	void Projetil::calcularTrajetoriaParaAlvo(sf::Vector2f alvo, float tempoVoo)
	{
		sf::Vector2f delta = alvo - pos;

		velocidade.x = delta.x / tempoVoo;
		velocidade.y = (delta.y - 0.5f * GRAVIDADE * tempoVoo * tempoVoo) / tempoVoo;
	}

}