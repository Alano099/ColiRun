#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

#define LARGURA 1200
#define ALTURA 720
#define FRAME_RATE 100
#include <map>
#include "Math.h"

namespace Gerenciadores {

	class Gerenciador_Grafico
	{
	private:
		sf::RenderWindow* janela;

		//novas
		static float dt;
		sf::Clock relogio;
		sf::View view;
		std::map<const char*, sf::Texture*> mapaTexturas;
		std::map<const char*, sf::Font*> fontsMap;

		static Gerenciador_Grafico* instance;
		Gerenciador_Grafico();
	public:

		~Gerenciador_Grafico();
		static Gerenciador_Grafico* get_instance();
		sf::RenderWindow* getJanela();
		void desenhar(sf::RectangleShape* corpo);
		void desenhar(sf::CircleShape* corpo);
		void renderizar(sf::Text* text);
		void mostrar();
		void limpar();
		void fechajanela();
		const bool abreJanela();

		//novas

		float atualizarTempo();
		sf::Texture* carregarTextura(const char* caminho);
		sf::Vector2u getTamjanela();
		void lidarTamJanela();
		void centralizarView(sf::Vector2f pos);
		

		//menu
		// 
		//void setWindowSize(Math::CoordU size);
		//Math::CoordU getWindowSize() const;

		Math::CoordF getTopLeftPosition() const;

		//void centerView(Math::CoordF pos);

		//sf::Texture* loadTexture(const char* path);

		sf::Font* carregaFonte(const char* path);

	};


}

