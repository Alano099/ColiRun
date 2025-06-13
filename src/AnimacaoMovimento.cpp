#include "../include/AnimacaoMovimento.h"


namespace ElementosGraficos {

	const float AnimacaoMovimento::AnimacaoUnica::switchTime = 0.2f;

	AnimacaoMovimento::AnimacaoMovimento():mapaAnimacao(),ID_Atual(ID_Animacao::parado){}

	AnimacaoMovimento::~AnimacaoMovimento() {

		std::map<ID_Animacao, AnimacaoUnica*>::iterator it;
		for (it = mapaAnimacao.begin(); it != mapaAnimacao.end(); ++it)
			delete (it->second);

		mapaAnimacao.clear();


	}

	void AnimacaoMovimento::adicionarNovaAnimacao(ID_Animacao id, const char* caminho, unsigned int imagemCount)
	{
		AnimacaoUnica* tmp = new AnimacaoUnica(caminho, imagemCount);

		if (tmp == NULL) {
			std::cout << "ERRO CRIANDO ANIMACAO EM ANIMACAO::ADICIONARNOVAANIMACAO() " << std::endl;
			exit(1);
		}

		mapaAnimacao.insert(std::pair<ID_Animacao, AnimacaoUnica*>(id, tmp));
		sf::IntRect rectSize = tmp->getSize();

		corpo.setSize(sf::Vector2f(static_cast<float>(rectSize.width), static_cast<float>(rectSize.height)));
		corpo.setOrigin(sf::Vector2f(static_cast<float>(rectSize.width) / 2.f, static_cast<float>(rectSize.height) / 2.f));

	}

	void AnimacaoMovimento::atualizar(ID_Animacao id, bool olhandoEsquerda, sf::Vector2f posicao, float dt)
	{
		if (ID_Atual != id) {
			ID_Atual = id;
			mapaAnimacao[ID_Atual]->reseta();
		}

		mapaAnimacao[ID_Atual]->atualizar(dt, olhandoEsquerda);

		corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));
		corpo.setTextureRect(mapaAnimacao[ID_Atual]->getSize());
		corpo.setTexture(mapaAnimacao[ID_Atual]->getTExture());

	}

}