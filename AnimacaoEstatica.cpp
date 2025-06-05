#include "AnimacaoEstatica.h"

#include "Gerenciador_Grafico.h"

namespace ElementosGraficos {

	AnimacaoEstatica::AnimacaoEstatica(const char* caminho, sf::Vector2f posicao, sf::Vector2f tamanho, float escala):textura(NULL),
	corpo(sf::Vector2f(tamanho.x , tamanho.y)){

		textura = Gerenciadores::Gerenciador_Grafico::get_instance()->carregarTextura(caminho);

		corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));
		corpo.setScale(sf::Vector2f(escala, escala));

		corpo.setTexture(textura);
	}

	AnimacaoEstatica::~AnimacaoEstatica() {

	}

	void AnimacaoEstatica::atualizar(sf::Vector2f posicao)
	{
		corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));
	}

	void AnimacaoEstatica::desenhar()
	{
		Gerenciadores::Gerenciador_Grafico::get_instance()->desenhar(&corpo);
	}


		

}
