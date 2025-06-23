#include "../include/Espinho.h"

namespace Entidades {

	namespace Obstaculos {

		Espinho::Espinho(sf::Vector2f posicao, sf::Vector2f tamanho, IDs::IDs id) : Obstaculo(posicao, tamanho,id)
		{
			inicializar();
		}


		Espinho::~Espinho() {}

		void Espinho::executar(float dt) {
			sprite.executar(pos);
		}

		void Espinho::inicializar() {
			sprite.inicializar("assets/obstaculos/espinhos.png", pos, tam);
			
		}

        void Espinho::obstacular(Entidade* outraEntidade, sf::Vector2f intersecao)
        {
            if (outraEntidade->getID() == IDs::IDs::jogador) {
                auto* jogador = dynamic_cast<Entidades::Personagens::Jogador*>(outraEntidade);
                if (jogador) {
                    float impulsoX = 90.f;
                    float impulsoY = -300.f;

					sf::Vector2f vel = jogador->getVelocidade();

                    if (intersecao.x > intersecao.y) {
                        // COLISÃO LATERAL
                        if (jogador->getPosicao().x < pos.x)
                            vel.x = -impulsoX;
                        else
                            vel.x = +impulsoX;

                        //std::cout << "Hit lateral do espinho! vel.x = " << vel.x << std::endl;
                    }
                    else {
                        // COLISÃO VERTICAL
                        vel.y = impulsoY;

                       //std::cout << "Hit vertical do espinho! vel.y = " << vel.y << std::endl;
                    }
                    jogador->tomarDano(10);
                    jogador->setVelocidade(vel);
                    jogador->setEmKnockback(true);
                    jogador->setTempoKnockback(0.3f);
                }
            }
        }

	}
}