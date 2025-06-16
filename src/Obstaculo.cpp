#include "../include/Obstaculo.h"


namespace Entidades {

	namespace Obstaculos {


		Obstaculo::Obstaculo(sf::Vector2f posicao, sf::Vector2f tamanho,IDs::IDs id):Entidade(posicao,tamanho,id),sprite(){

			danoso = false;

		}

		Obstaculo::~Obstaculo(){}

		sf::Vector2f Obstaculo::getPosicao() const {
			return pos;
		}

		void Obstaculo::desenhar() {

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


	}

}