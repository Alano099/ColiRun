#include "../include/AnimacaoEstatica.h"

#include "../include/Gerenciador_Grafico.h"

namespace ElementosGraficos {


	AnimacaoEstatica::AnimacaoEstatica():textura(NULL){}


	AnimacaoEstatica::~AnimacaoEstatica() {

	}

	void AnimacaoEstatica::setScale(sf::Vector2f esc)
	{
		corpo.setScale(esc);
	}

	void AnimacaoEstatica::executar(sf::Vector2f posicao)
	{
		corpo.setPosition(posicao);
	}

	sf::Texture* AnimacaoEstatica::getTextura() const {
		return textura; 
	}

	void AnimacaoEstatica::inicializar(const char* caminho, sf::Vector2f posicao, sf::Vector2f tamanho) {
		textura = Gerenciadores::Gerenciador_Grafico::get_instance()->carregarTextura(caminho);
		if (!textura) {
			std::cout << "ERRO ao carregar textura em AnimacaoEstatica." << std::endl;
			return;
		}

		// Permite repetir a textura
		textura->setRepeated(true);

		// Shape com tamanho desejado (exemplo: 6x largura)
		corpo.setSize(tamanho);
		corpo.setOrigin(corpo.getSize().x / 2.f, corpo.getSize().y / 2.f);
		corpo.setPosition(posicao);
		corpo.setTexture(textura);

		// Define área de repetição da textura
		corpo.setTextureRect(sf::IntRect(
			0, 0,
			static_cast<int>(tamanho.x),
			static_cast<int>(tamanho.y)
		));

		// NÃO precisa usar scale — só usa setTextureRect para repetir
	}



		

}
