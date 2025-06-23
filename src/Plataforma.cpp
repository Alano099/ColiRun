#include "../include/plataforma.h"

namespace Entidades {

	namespace Obstaculos {


		Plataforma::Plataforma(sf::Vector2f posicao, sf::Vector2f tamanho,IDs::IDs id,bool ehTrampolim):Obstaculo(posicao, tamanho,id),trampolim(ehTrampolim)
		{
			inicializar();
		}

		Plataforma::~Plataforma() {
		}
		
		void Plataforma::executar(float dt) {
			
			float forcaEmpuxo = GRAVIDADE;

			if (!noChao) {
				// Aplica gravidade - empuxo
				velocidadeY += (GRAVIDADE - forcaEmpuxo) * dt;

				pos.y += velocidadeY * dt;

				if (pos.y >= CHAO) {
					pos.y = CHAO;
					velocidadeY = 0.f;
					noChao = true;
				}
			}

			sprite.executar(pos);
		}

		void Plataforma::inicializar() {
            if(!trampolim)
			    sprite.inicializar(PLATAFORMA_CAMINHO, pos, tam);
			else
			    sprite.inicializar("assets/obstaculos/mola.png", pos, tam);

	

		}

        void Plataforma::obstacular(Entidade* outraEntidade, sf::Vector2f intersecao)
        {

            IDs::IDs id = outraEntidade->getID();

            if (id == IDs::IDs::jogador) {
                auto* jogador = dynamic_cast<Entidades::Personagens::Jogador*>(outraEntidade);
                if (jogador) {

                    sf::Vector2f jogadorPos = jogador->getPosicao();

                    if (intersecao.x > intersecao.y) {
                        // Colisão lateral
                        if (jogadorPos.x < pos.x)
                            jogadorPos.x += intersecao.x;
                        else
                            jogadorPos.x -= intersecao.x;

                        jogador->setVelocidade(sf::Vector2f(0.f, jogador->getVelocidade().y));
                    }
                    else {
                        // Colisão vertical
                        if (jogadorPos.y < pos.y) {
                            // Colisão de cima
                            jogador->setNochao(true);
                            jogador->setPulando(false);
                            jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, 0.f));

                            //std::cout << "Colidiu por cima!" << std::endl;

                            // Se for trampolim, aplica pulo suave
                            if (trampolim) {
                                //std::cout << "TRAMPOLIM ativado!" << std::endl;

                                float velPulo = jogador->getVelPulo();

                                jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, -velPulo));
                                jogador->setPulando(true);
                                // NÃO altera a posição — deixa a física agir
                            }
                        }
                        else {
                            // Colisão de baixo (opcional)
                            jogadorPos.y -= intersecao.y;
                            jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, 0.f));
                        }
                    }

                    jogador->setPosition(jogadorPos);
                }
            }

            if (id == IDs::IDs::soldado || id == IDs::IDs::minotauro || id == IDs::IDs::medusa) {
                auto* inimigo = dynamic_cast<Entidades::Personagens::Inimigos::Inimigo*>(outraEntidade);

               
                if (inimigo) {
                    sf::Vector2f inimigoPos = inimigo->getPosicao();

                    if (intersecao.x > intersecao.y) {
                       
                        if (inimigoPos.x < pos.x)
                            inimigoPos.x += intersecao.x;
                        else
                            inimigoPos.x -= intersecao.x;

                        inimigo->setSentido(-inimigo->getSentido());
                        //std::cout << "Inimigo trocou de sentido!" << std::endl;


                        // Opcional: pode zerar velocidade.x se quiser
                        inimigo->setVelocidade(sf::Vector2f(0.f, inimigo->getVelocidade().y));
                      
                        inimigo->setPosition(inimigoPos);

                        inimigo->setPerseguindo(false);
                    }
                    else {
                        // Colisão VERTICAL → inimigo cai/anda normal
                        inimigo->setVelocidade(sf::Vector2f(0.f, inimigo->getVelocidade().x));
                    }

                  
                }
            }


        }


	}

}