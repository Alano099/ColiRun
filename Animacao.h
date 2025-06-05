//Codigo adaptado do monitor matheus Burda https://www.youtube.com/watch?v=KJJo9QPY8kI&t || https://github.com/MatheusBurda/Desert

#pragma once

#include "Gerenciador_Grafico.h"
#include "stdafx/stdafx.h"

#include <map>


namespace ElementosGraficos{

	enum ID_Animacao {

		andar = 0,
		parado = 1,
		ataque = 2


		};


	class Animacao
	{
		private:
			class AnimacaoUnica {
			private:
				const unsigned int imageCount;
				unsigned int imagemAtual;
				sf::Texture* textura;
				float tempoTotal;
				sf::IntRect rectSize;
				static const float switchTime;

			public:
				AnimacaoUnica(const char* caminho, const unsigned int imageCount) :
					imageCount(imageCount),
					imagemAtual(0),
					textura(pGG->carregarTextura(caminho)),
					tempoTotal(0.0f),
					rectSize() {

					if (textura == NULL) {
						std::cout << "ERROR: carregando textura falhou em AnimacaoUnica::AnimacaoUnica()." << std::endl;
						exit(1);
					}

					rectSize.width = textura->getSize().x / float(imageCount);
					rectSize.height = textura->getSize().y;

					}

				~AnimacaoUnica(){}

				void atualizar(float dt, bool olhandoEsquerda) {

					tempoTotal += dt;

					if (tempoTotal >= switchTime) {
						tempoTotal -= switchTime;
						imagemAtual++;

						if (imagemAtual >= imageCount) {
							imagemAtual = 0;
						}
					}

					if (olhandoEsquerda) {
						rectSize.left = (imagemAtual + 1) * abs(rectSize.width);
						rectSize.width = -abs(rectSize.width);

					}

					else {
						rectSize.left = imagemAtual * rectSize.width;
						rectSize.width = abs(rectSize.width);
					}


				}

				void reseta() {

					imagemAtual = 0;
					tempoTotal = 0;

				}

				sf::IntRect getSize() const { return rectSize; }
				sf::Texture* getTExture() const { return textura; }

			};
		

	private:
		sf::RectangleShape corpo;
		std::map<ID_Animacao, AnimacaoUnica*> mapaAnimacao;
		ID_Animacao ID_Atual;

		static Gerenciadores::Gerenciador_Grafico* pGG;

	public:
		Animacao();
		~Animacao();

		void adicionarNovaAnimacao(ID_Animacao id, const char* caminho, unsigned int imagemCount);
		void atualizar(ID_Animacao id, bool olhandoEsquerda, sf::Vector2f posicao, float dt);
		void desenhar();
	};


}


