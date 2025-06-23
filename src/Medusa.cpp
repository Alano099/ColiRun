#include "../include/Medusa.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {

            Medusa::Medusa(sf::Vector2f pos, sf::Vector2f tamanho, IDs::IDs id,int vida)
                : Inimigo(pos, tamanho, id,vida), projetil(nullptr), tempoCooldownTiro(0.f)
            {
                inicializar();
            }

            Medusa::~Medusa()
            {
            }

            void Medusa::executar(float dt)
            {
                if (tempoDano > 0.f)
                    tempoDano -= dt;

                // ====== KNOCKBACK ======
                if (emKnockback) {
                    tempoKnockback -= dt;
                    if (tempoKnockback <= 0.f) {
                        emKnockback = false;
                        velocidade.x = 0.f;
                    }
                }
                else {
                    // ====== MOVIMENTO NORMAL ======
                    sf::Vector2f posJog = pJog->getPosicao();
                    float distancia = std::hypot(posJog.x - pos.x, posJog.y - pos.y);

                    if (distancia < 500.f) {
                        velocidade.x = 0.f;
                        olhandoEsquerda = (posJog.x < pos.x);

                        if (tempoCooldownTiro <= 0.f) {
                            ultimoAlvo = posJog;
                            atacar(dt);
                            tempoCooldownTiro = 2.f;
                        }
                    }
                    else {
                        perseguindo = false;

                        velocidade.x = sentido * 60.f;
                        olhandoEsquerda = (sentido == -1);
                    }
                }

                // ====== FÍSICA ======
                pos.x += velocidade.x * dt;
                velocidade.y += GRAVIDADE * dt;
                pos.y += velocidade.y * dt;

                if (tempoCooldownTiro > 0.f)
                    tempoCooldownTiro -= dt;

                if (pos.y >= 600.f) {
                    pos.y = 600.f;
                    velocidade.y = 0.f;
                    noChao = true;
                }
                else {
                    noChao = false;
                }

                if (!perseguindo && (pos.x > pontoDireita.x || pos.x < pontoEsquerda.x)) {
                    sentido *= -1;
                    if (pos.x > pontoDireita.x)
                        pos.x = pontoDireita.x;
                    else if (pos.x < pontoEsquerda.x)
                        pos.x = pontoEsquerda.x;
                }

                // ====== COOLDOWN DE ATAQUE ======
                if (estaAtacando) {
                    tempoAtaque -= dt;
                    if (tempoAtaque <= 0.f) {
                        estaAtacando = false;
                        tempoAtaque = 0.6f;
                    }
                }

                if (tempoInvulneravel > 0.f)
                    tempoInvulneravel -= dt;

                // ====== ANIMAÇÃO ======
                if (estaAtacando) {
                    sprite.atualizar(ElementosGraficos::ID_Animacao::ataque, !olhandoEsquerda, pos, dt);
                }
                else if (emKnockback) {
                    sprite.atualizar(ElementosGraficos::ID_Animacao::parado, !olhandoEsquerda, pos, dt);
                }
                else {
                    sprite.atualizar(ElementosGraficos::ID_Animacao::andar, !olhandoEsquerda, pos, dt);
                }
            }

            void Medusa::inicializar()
            {
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::andar, "assets/inimigos/medusa/medusa_andar.png", 13);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::parado, "assets/inimigos/medusa/medusa_parado.png", 7);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_Animacao::ataque, "assets/inimigos/medusa/medusa_especial.png", 5);
            }

            void Medusa::colidir(Entidade* outraEntidade, sf::Vector2f intercepta)
            {
                switch (outraEntidade->getID()) {
                case IDs::IDs::plataforma:
                    moverNaColisao(intercepta, outraEntidade->getPosicao());
                    break;

                case IDs::IDs::jogador: {
                    Jogador* jogador = dynamic_cast<Jogador*>(outraEntidade);
                    if (jogador && jogador->getAtacando() && tempoDano <= 0.f) {
                        moverNaColisao(intercepta, jogador->getPosicao());
                        tempoDano = 0.5f;
                    }
                    break;
                }

                default:
                    break;
                }
            }

            void Medusa::atacar(float dt)
            {
                if (projetil && !projetil->getAtivo()) {
                    projetil->setAtivo(true);
                    projetil->setPosition({ pos.x, pos.y - 35.f }); // origem do tiro

                    sf::Vector2f alvo = pJog->getPosicao();
                    sf::Vector2f delta = alvo - pos;

                    float t = 1.0f;  // tempo para chegar no alvo
                    float g = GRAVIDADE;

                    float vx = delta.x / t;
                    float vy = (delta.y / t) - (0.5f * g * t);

                    projetil->setVelocidade({ vx, vy });

                    estaAtacando = true;
                    tempoAtaque = 0.6f;
                }
            }
            void Medusa::definirLimitesDePatrulha(float alcance)
            {
                pontoEsquerda = sf::Vector2f(pos.x - alcance, pos.y);
                pontoDireita = sf::Vector2f(pos.x + alcance, pos.y);
            }

        }
    }
}
