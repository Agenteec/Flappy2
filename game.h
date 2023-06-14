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
	static float velocity;
	static float angle;
	static bool spt;
	static float g;
public:
	/// <summary>
	/// Загрузка игровых объектов
	/// </summary>
	static void init() {
		bird_tx[0].loadFromFile("Resources\\Images\\bird_1.png");
		bird_tx[1].loadFromFile("Resources\\Images\\bird_2.png");
		//bird.setTexture(bird_tx[0]);
		spt = false;
		bird.setScale(0.05f, 0.05f);
		bird.setOrigin(sf::Vector2f(bird_tx[0].getSize().x*0.05 / 2.f, bird_tx[0].getSize().y*0.05 / 2.f));
		x = 1024.f/2.f-36.f;
		y = 360.f;
		velocity = 0.f;
		g = 9.8f;
		bird.setPosition(x, y);
		
	}
	static void new_game()
	{
		x = 1024.f / 2.f - 36.f;
		y = 360.f;
		velocity = 0.f;
		bird.setPosition(x, y);
		angle = 0.f;
	}
	/// <summary>
	/// Отрисовка игровых объектов
	/// </summary>
	/// <param name="window">Главное окно</param>
	/// <param name="event">Событие</param>
	static void on_game(sf::RenderWindow* window, sf::Time deltatime, bool pause) {
	if (!pause)
	{
		float dts = deltatime.asSeconds();
		bird_move(dts);
	}
	window->draw(bird);
	}
	static void game_event(sf::Event* event) {
		if (event->type == sf::Event::KeyPressed) {
			if (event->key.code == sf::Keyboard::Space) {
				spt = true;
			}
			
		}
		if (event->type == sf::Event::MouseButtonPressed) {
			if (event->key.code == sf::Mouse::Left) {
				spt = true;
			}
		}
		if (event->type == sf::Event::KeyReleased) {
			if (event->key.code == sf::Keyboard::Space) {
				spt = false;
			}
		}
		if (event->type == sf::Event::MouseButtonReleased) {
			if (event->key.code == sf::Mouse::Left) {
				spt = false;
			}
		}
	}
	static void add_impulse(float impulse) {
		velocity += impulse;
	}
	static void bird_move(float dts)
	{
		
		velocity += g * dts * 0.01f;
		if (velocity >= 10) {
			velocity = 10.f;
		}
		if (spt) {
			add_impulse(-5.f * dts * 0.1f);
			if (angle >= -15)
			{
				angle -= 180.f * dts;
			}
		}
		else
		{
			if (angle<=45)
			{
				angle += 45.f * dts;
			}
		}
		if (y <= 760.f) {

			y += velocity;
		}
		else {
			y = 5.f;

		}
		if (y <= 4.f) {
			y = 758.f;
		}
		bird.setRotation(angle);
		bird.setTexture(bird_tx[spt]);
		bird.setPosition(x, y);
	}
	
	
};

