#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
class game
{
private:
	/// <summary>
	/// �������� �����
	/// </summary>
	static sf::Texture bird_tx[2];
	/// <summary>
	/// ������ �����
	/// </summary>
	static sf::Sprite bird;
	//���������� ������ 
	static float x, y;
	static int speed;
	static bool spt;
public:
	/// <summary>
	/// �������� ������� ��������
	/// </summary>
	static void init() {
		bird_tx[0].loadFromFile("Resources\\Images\\bird_1.png");
		bird_tx[1].loadFromFile("Resources\\Images\\bird_2.png");
		//bird.setTexture(bird_tx[0]);
		spt = false;
		x = 400.f;
		y = 360.f;
		speed = 200.f;
		bird.setPosition(x, y);
		bird.setScale(0.05f, 0.05f);
	}
	/// <summary>
	/// ��������� ������� ��������
	/// </summary>
	/// <param name="window">������� ����</param>
	/// <param name="event">�������</param>
	static void on_game(sf::RenderWindow* window) {


		

	sf::Clock clock;
	sf::Time deltatime = clock.restart();
	float dts = deltatime.asSeconds();
	if (y <= 760.f) {
		y += speed * dts;
	}
	else {
		y = 5.f;

	}
		bird.setTexture(bird_tx[spt]);
	

	bird.setPosition(x, y);
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
	
	
};

