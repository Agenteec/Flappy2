#pragma once
#include <SFML/Graphics.hpp>
class Window
{
	float WinH;
	float WinW;
	sf::RenderWindow* window;
public:
	Window():WinW(1024.f), WinH(768.f)
	{
		window = new sf::RenderWindow(sf::VideoMode(WinW, WinH), "FlappyBird");
	}
	void Render()
	{
		while (window->isOpen())
		{
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
			}
		}
	}
};

