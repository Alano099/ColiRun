#pragma once

#include "../include/Minotauro.h"

namespace Entidades {

	namespace Personagens {

		namespace Inimigos {

			Minotauro::Minotauro(sf::Vector2f pos,sf::Vector2f tamanho, IDs::IDs id,int vida) : Inimigo(pos,tamanho,id,vida)
			{
				inicializar();
			}

			Minotauro::~Minotauro() {}

			void Minotauro::executar(float dt) {

                if (tempoDano > 0.f)
                    tempoDano -= dt;

                if (!enfurecido && vida <= 0.3f * vidaMax) {
                    enfurecido = true;
                    std::cout << "[Minotauro ENFURECIDO]\n";
                }

                // KNOCKBACK
                if (emKnockback) {
                    tempoKnockback -= dt;
                    if (tempoKnockback <= 0.f) {
                        emKnockback = false;
                        velocidade.x = 0.f;
                    }
                }
                else {
                    sf::Vector2f posJog = pJog->getPosicao();
                    float distancia = std::hypot(posJog.x - pos.x, posJog.y - pos.y);

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
                                tempoAtaque = 1.5f;
                            }
                        }
                        else {
                            // PERSEGUIR
                            sf::Vector2f dir = posJog - pos;
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

                if (vida <= vidaMax * 0.3f)
                    enfurecido = true;

                if (estaAtacando && !enfurecido) {

                    sprite.atualizar(ElementosGraficos::ID_Animacao::dano, !estaOlhandoEsquerda(), pos, dt);

                }
                else if (!estaAtacando && !enfurecido)
                    sprite.atualizar(ElementosGraficos::ID_Animacao::andar, !(velocidade.x < 0.f), pos, dt);

                if(estaAtacando && enfurecido)
                    sprite.atualizar(ElementosGraficos::ID_Animacao::dano2, !estaOlhandoEsquerda(), pos, dt);

                else if(!estaAtacando && enfurecido)
                    sprite.atualizar(ElementosGraficos::ID_Animacao::andar2, !(velocidade.x < 0.f), pos, dt);
			}

			void Minotauro::inicializar() {
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/inimigos/minotauro/minotauro_andar.png", 8);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar2, "assets/inimigos/minotauro/minotauro_andar.png", 8);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/inimigos/minotauro/minotauro_parado.png", 6);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::dano, "assets/inimigos/minotauro/minotauro_ataque.png", 6);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::dano2, "assets/inimigos/minotauro/minotauro_ataque2.png", 6);

			}

			void Minotauro::colidir(Entidade* outraEntidade, sf::Vector2f intercepta)
			{
				switch (outraEntidade->getID()) {
				case IDs::IDs::plataforma:
					moverNaColisao(intercepta, outraEntidade->getPosicao());
					break;

				case IDs::IDs::jogador: {
					Jogador* jogador = dynamic_cast<Jogador*>(outraEntidade);
					if (jogador && jogador->getAtacando() && tempoDano <= 0.f) {
						std::cout << "ATAQUE COLIDIU!\n";
						moverNaColisao(intercepta, jogador->getPosicao());
						tempoDano = 0.5f;
					}

                    if (jogador && jogador->getAtacando() && tempoDano <= 0.f) {
                        moverNaColisao(intercepta, jogador->getPosicao());
                        this->tomarDano(10);  // <- Faltou isso !!
                        tempoDano = 0.5f;
                    }

					break;
				}

				default:
					break;
				}
			}

			void Minotauro::atacar(float dt)
			{
			}

			void Minotauro::definirLimitesDePatrulha(float alcance)
			{
				pontoEsquerda = sf::Vector2f(pos.x - alcance, pos.y);
				pontoDireita = sf::Vector2f(pos.x + alcance, pos.y);
			}

		}
	}
}