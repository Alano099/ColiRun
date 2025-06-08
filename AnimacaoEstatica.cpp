#include "AnimacaoEstatica.h"

#include "Gerenciador_Grafico.h"

namespace ElementosGraficos {


	AnimacaoEstatica::AnimacaoEstatica():textura(NULL){}


	AnimacaoEstatica::~AnimacaoEstatica() {

	}

	void AnimacaoEstatica::atualizar(sf::Vector2f posicao)
	{
		corpo.setPosition(posicao);
	}

	sf::Texture* AnimacaoEstatica::getTextura() const {
		return textura; // ou &textura, conforme j� estiver
	}

	void AnimacaoEstatica::inicializar(const char* caminho, sf::Vector2f posicao, sf::Vector2f tamanho) {
		textura = Gerenciadores::Gerenciador_Grafico::get_instance()->carregarTextura(caminho);
		if (!textura) {
			std::cout << "ERRO ao carregar textura em AnimacaoEstatica." << std::endl;
			return;
		}

		
		corpo.setTextureRect(sf::IntRect(0, 0, tamanho.x, tamanho.y));
		corpo.setSize(tamanho);
		corpo.setTextureRect(sf::IntRect(0, 0, static_cast<int>(tamanho.x), static_cast<int>(tamanho.y)));
		corpo.setOrigin(tamanho.x / 2.f, tamanho.y / 2.f);
		corpo.setPosition(posicao);
		corpo.setTexture(textura);
	}



		

}
