#pragma once
#include <SFML/Graphics.hpp>

class Game
{
	private:
		sf::RenderWindow win;
		float delta;
		
		void input();
		void process();
		void render();

	public:
		Game();
		void run();
};