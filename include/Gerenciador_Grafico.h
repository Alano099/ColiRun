#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

#define LARGURA 1200
#define ALTURA 720
#define FRAME_RATE 100

#define FONT_PATH "assets/PressStart2P-Regular.ttf"

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
		sf::Font* fonte;

		static Gerenciador_Grafico* instance;
		Gerenciador_Grafico();
	public:

		~Gerenciador_Grafico();
		static Gerenciador_Grafico* get_instance();
		sf::RenderWindow* getJanela();
		void desenhar(sf::RectangleShape* corpo);
		void desenhar(sf::CircleShape* corpo);
		void desenhar(sf::Text* texto);
		void mostrar();
		void limpar();
		void fechajanela();
		const bool abreJanela();

		//novas

		float atualizarTempo();
		sf::Texture* carregarTextura(const char* caminho);
		sf::Vector2u getTamjanela();
		static float getDt() { return dt; }
		void lidarTamJanela();
		void centralizarView(sf::Vector2f pos);
		void atualizarCamera(sf::Vector2f centro, sf::FloatRect limites);
		sf::Font* getFonte() const;
	};


}

