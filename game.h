#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
class game
{
private:
	/// <summary>
	/// Текстуры птицы
	/// </summary>
	static sf::Texture bird_tx[2];
	/// <summary>
	/// Спрайт птицы
	/// </summary>
	static sf::Sprite bird;
	//координаты птички 
	static float x, y;
	static int speed;
public:
	/// <summary>
	/// Загрузка игровых объектов
	/// </summary>
	static void init() {
		bird_tx[0].loadFromFile("Resources\\Images\\bird_1.png");
		bird_tx[1].loadFromFile("Resources\\Images\\bird_2.png");
		bird.setTexture(bird_tx[0]);
		x = 200.f;
		y = 200.f;
		speed = 100.f;
		bird.setPosition(x, y);
		bird.setScale(0.2f, 0.2f);
	}
	/// <summary>
	/// Отрисовка игровых объектов
	/// </summary>
	/// <param name="window">Главное окно</param>
	/// <param name="event">Событие</param>
	static void on_game(sf::RenderWindow* window, sf::Event* event) {


		if (event->type == sf::Event::KeyPressed) {
			if (event->key.code == sf::Keyboard::Space) {
				bird.setTexture(bird_tx[1]);
			}
			else {
				bird.setTexture(bird_tx[0]);
			}
		}

	sf::Clock clock;
	sf::Time deltatime = clock.restart();
	float dts = deltatime.asSeconds();
	if (y <= 760.f) {
		y += speed * dts;
	}
	else {
		y = 5.f;

	}


	bird.setPosition(x, y);
	window->draw(bird);

		


	}
	static void 
	
	
};

