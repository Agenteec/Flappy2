#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"
#include "GUI.h"
class Window
{
	float WinH;
	float WinW;
	sf::RenderWindow* window;
public:
	Window():WinW(1024.f), WinH(768.f)
	{
		window = new sf::RenderWindow(sf::VideoMode(WinW, WinH), "FlappyBird");
		game::init();
	}
	void Render()
	{
		while (window->isOpen())
		{
			sf::Event* event= new sf::Event;
			game::on_game(window, event);
			delete event;
		}
	}
};