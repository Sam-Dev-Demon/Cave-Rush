#include "Game.h"

Game::Game() : win(sf::VideoMode({800u, 600u}), "Hello", sf::Style::Default, sf::State::Fullscreen)
{
	win.setVerticalSyncEnabled(true);
}

void Game::run()
{
	sf::Clock c;
	float maxTime = 0.25;
	while (win.isOpen())
	{
		input();
		delta = c.restart().asSeconds();
		if (delta > maxTime)
			delta = maxTime;
		process();
		render();
	}
}

void Game::input()
{
	while (const std::optional event = win.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			win.close();
		if (const auto* key = event->getIf<sf::Event::KeyPressed>())
		{
			if (key->code == sf::Keyboard::Key::Q && key->control)
				win.close();
		}
	}
}

void Game::process()
{
	
}

void Game::render()
{
	win.clear(sf::Color(0, 0, 0, 255));
	
	win.display();
}