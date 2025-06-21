#include "../include/Texto.h"

#define TEXT_SIZE 24

namespace Menus
{
	Gerenciadores::Gerenciador_Grafico* Texto::pGG(Gerenciadores::Gerenciador_Grafico::get_instance());

    Texto::Texto(sf::Vector2f posicao, std::string info, const char* path) :
        info(info) {
        texto.setString(info);

        texto.setFont(*pGG->carregaFonte(path));

        texto.setCharacterSize(TEXT_SIZE);

        setTextoAlinhamento(TextoAlinhamento::esquerda);

        texto.setPosition(sf::Vector2f(posicao.x, posicao.y));

        texto.setFillColor(sf::Color::White);
    }

    Texto::~Texto() {}

    void Texto::setTextoInfo(std::string info) {
        this->info = info;
        texto.setString(this->info);
    }

    void Texto::setPosicao(sf::Vector2f posicao) {
        texto.setPosition(sf::Vector2f(posicao.x, posicao.y));
    }

    void Texto::setTextoCor(const unsigned int R, const unsigned int G, const unsigned int B) {
        texto.setFillColor(sf::Color(R, G, B));
    }

    void Texto::setFonteTamanho(const unsigned int tamanho) {
        texto.setCharacterSize(tamanho);
    }

    void Texto::setTextoAlinhamento(TextoAlinhamento opcao) {
        switch (opcao) {
        case TextoAlinhamento::esquerda:
            texto.setOrigin(0, 0);
            break;
        case TextoAlinhamento::centro:
            texto.setOrigin(getTamanho().x / 2, getTamanho().y);
            break;
        case TextoAlinhamento::direita:
            texto.setOrigin(getTamanho().x, 0);
            break;
        default:
            texto.setOrigin(getTamanho().x / 2, getTamanho().y);
            break;
        }
    }

    sf::Vector2f Texto::getTamanho() const {
        sf::FloatRect textRect = texto.getLocalBounds();
        return sf::Vector2f(textRect.width, textRect.height);
    }

    void Texto::renderizar() {
        pGG->renderizar(&texto);
    }

    std::string Texto::getInfo() const {
        return info;
    }

    sf::Vector2f Texto::getPosicao() const {
        return sf::Vector2f(texto.getPosition().x, texto.getPosition().y);
    }
}