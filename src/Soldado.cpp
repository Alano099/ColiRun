#include "../include/Soldado.h"

namespace Entidades {

	namespace Personagens {

		namespace Inimigos {

			Soldado::Soldado(sf::Vector2f pos, sf::Vector2f tamanho,IDs::IDs id,int vida): Inimigo(pos,tamanho,id,vida)
			{

                forca = 1.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.0f - 1.0f)));
         
				inicializar();
				
			}

			Soldado::~Soldado() {}

            void Soldado::executar(float dt) {
                if (tempoDano > 0.f)
                    tempoDano -= dt;

                // KNOCKBACK
                if (emKnockback) {
                    tempoKnockback -= dt;
                    if (tempoKnockback <= 0.f) {
                        emKnockback = false;
                        velocidade.x = 0.f;
                    }
                }
                else {
                    sf::Vector2f posJogMaisPerto = pJog->getPosicao();
                    float distancia = std::hypot(posJogMaisPerto.x - pos.x, posJogMaisPerto.y - pos.y);

                    if (pJog2) {
                        sf::Vector2f posJog2 = pJog2->getPosicao();
                        float dist2 = std::hypot(posJog2.x - pos.x, posJog2.y - pos.y);

                        if (dist2 < distancia) {
                            distancia = dist2;
                            posJogMaisPerto = posJog2;
                        }
                    }

                    float RANGE_VISAO = 300.f;
                    float RANGE_ATAQUE = 50.f;

                    if (distancia < RANGE_VISAO) {
                        perseguindo = true;

                        if (distancia < RANGE_ATAQUE) {
                            // ATACANDO
                            velocidade.x = 0.f;

                            if (!estaAtacando && podeAtacar) {
                                atacar(dt);
                                estaAtacando = true;
                                tempoAtaque = 0.6f;
                            }
                        }
                        else {
                            // PERSEGUIR
                            sf::Vector2f dir = posJogMaisPerto - pos;
                            float mag = std::sqrt(dir.x * dir.x + dir.y * dir.y);
                            if (mag != 0.f) dir /= mag;

                            velocidade.x = dir.x * 100.f;
                            olhandoEsquerda = dir.x < 0;
                        }
                    }
                    else {

                        if (perseguindo) {
                            // AJUSTE: Atualiza o ponto de patrulha atual
                            pontoEsquerda = sf::Vector2f(pos.x - 150.f, pos.y);
                            pontoDireita = sf::Vector2f(pos.x + 150.f, pos.y);
                            perseguindo = false;
                        }
                        velocidade.x = sentido * 60.f;
                    }
                }

                // Movimento vertical
                velocidade.y += GRAVIDADE * dt;

                // Atualizar posição
                pos.x += velocidade.x * dt;
                pos.y += velocidade.y * dt;

                // Colisão com chão
                if (pos.y >= CHAO) {
                    pos.y = CHAO;
                    velocidade.y = 0.f;
                    noChao = true;
                }
                else {
                    noChao = false;
                }


                if (pos.x <= LIMITE_ESQUERDA) {
                    pos.x = LIMITE_ESQUERDA;
                    velocidade.x = 0.f;
                }

                if (pos.x >= 3268.f) {
                    pos.x = 3268.f;
                    velocidade.x = 0.f;
                }

                // Limites de patrulha
                if (!perseguindo && (pos.x > pontoDireita.x || pos.x < pontoEsquerda.x)) {
                    sentido *= -1;

                    if (pos.x > pontoDireita.x)
                        pos.x = pontoDireita.x;
                    else if (pos.x < pontoEsquerda.x)
                        pos.x = pontoEsquerda.x;
                }

                if (estaAtacando) {


                    if (!olhandoEsquerda) {
                        ataque.setPosition(pos.x + 30.f, pos.y - 20.f);
                    }
                    else {
                        ataque.setPosition(pos.x - 30.f, pos.y - 20.f);
                    }
                }

                else {
                    ataque.setSize(sf::Vector2f(0.f, 0.f)); // IMPORTANTE: zera a hitbox quando não ataca
                }

                // Atualizar cooldown de ataque
                if (estaAtacando) {
                    tempoAtaque -= dt;
                    if (tempoAtaque <= 0.f) {
                        estaAtacando = false;
                        podeAtacar = true;
                    }
                }

                if (tempoInvulneravel > 0.f)
                    tempoInvulneravel -= dt;

                if (estaAtacando) {

                    sprite.atualizar(ElementosGraficos::ID_Animacao::dano, !estaOlhandoEsquerda(), pos, dt);

                }
                else
                    sprite.atualizar(ElementosGraficos::ID_Animacao::andar, !(velocidade.x < 0.f), pos, dt);
            }

			void Soldado::inicializar() {

				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/inimigos/soldado/soldado_andar.png", 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/inimigos/soldado/soldado_parado.png", 3);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::dano, "assets/inimigos/soldado/soldado_ataque.png", 6);
			}

	
            void Soldado::colidirAtaque(Entidade* outraEntidade, sf::Vector2f intercepta) {
                switch (outraEntidade->getID()) {


                case IDs::IDs::jogador: {
                    Jogador* jogador = dynamic_cast<Jogador*>(outraEntidade);

                    if (estaAtacando && tempoDano <= 0.f) {
                        std::cout << "Soldado ATACOU Jogador!\n";

                        float baseX = 150.f;
                        float baseY = 50.f;

                        float deltaX = jogador->getPosicao().x - this->getPosicao().x;

                        sf::Vector2f empurrao;
                        if (deltaX >= 0.f) {
                            // Jogador está à direita → empurra pra direita
                            empurrao = sf::Vector2f(baseX * forca, -baseY * forca);
                        }
                        else {
                            // Jogador está à esquerda → empurra pra esquerda
                            empurrao = sf::Vector2f(-baseX * forca, -baseY * forca);
                        }

                        jogador->setVelocidade(empurrao);
                        jogador->setEmKnockback(true);
                        jogador->setTempoKnockback(0.4f);
                        jogador->tomarDano(6.f);

                        tempoDano = 0.5f;
                    }

                    break;
                }
                default:
                    break;
                }
            }
			void Soldado::definirLimitesDePatrulha(float alcance)
			{
				pontoEsquerda = sf::Vector2f(pos.x - alcance, pos.y);
				pontoDireita = sf::Vector2f(pos.x + alcance, pos.y);
			}


			void Soldado::atacar(float dt) {
            
                podeAtacar = false;
                tempoAtaque = 1.5f;
               
                ataque.setSize(sf::Vector2f(15.f, 15.f));
            
            }

		}

	}

}