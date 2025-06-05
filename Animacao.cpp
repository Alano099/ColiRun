#include "Animacao.h"

namespace ElementosGraficos {

	const float Animacao::AnimacaoUnica::switchTime = 0.2;

	Gerenciadores::Gerenciador_Grafico* Animacao::pGG = Gerenciadores::Gerenciador_Grafico::get_instance();

	Animacao::Animacao():
	corpo(),
	mapaAnimacao(),
	ID_Atual(ID_Animacao::andar)
	{

		corpo.setScale(sf::Vector2f(3, 3));

	}

	Animacao::~Animacao() {

		std::map<ID_Animacao, AnimacaoUnica*>::iterator it;
		for (it = mapaAnimacao.begin(); it != mapaAnimacao.end(); ++it)
			delete (it->second);

		mapaAnimacao.clear();

	}

	void Animacao::adicionarNovaAnimacao(ID_Animacao id, const char* caminho, unsigned int imagemCount) {

		AnimacaoUnica* tmp = new AnimacaoUnica(caminho, imagemCount);

		if (tmp == NULL) {
			std::cout << "ERRO CRIANDO ANIMACAO EM ANIMACAO::ADICIONARNOVAANIMACAO() " << std::endl;
			exit(1);
		}

		mapaAnimacao.insert(std::pair<ID_Animacao, AnimacaoUnica*>(id, tmp));
		sf::IntRect rectSize = tmp->getSize();

		corpo.setSize(sf::Vector2f(rectSize.width, rectSize.height));
		corpo.setOrigin(sf::Vector2f(rectSize.width, rectSize.height) / 2.0f);

	

	}

	void Animacao::atualizar(ID_Animacao id, bool olhandoEsquerda, sf::Vector2f posicao, float dt) {
		if (ID_Atual != id) {
			ID_Atual = id;
			mapaAnimacao[ID_Atual]->reseta();
		}

		mapaAnimacao[ID_Atual]->atualizar(dt, olhandoEsquerda);

		corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));
		corpo.setTextureRect(mapaAnimacao[ID_Atual]->getSize());
		corpo.setTexture(mapaAnimacao[ID_Atual]->getTExture());

	}

	void Animacao::desenhar() {
		pGG->desenhar(&corpo);
	}

}