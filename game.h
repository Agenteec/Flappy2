#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <random>
#include <SFML/Audio.hpp>

struct PairRect
{
	sf::RectangleShape s1;
    sf::RectangleShape s2;
	
};
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
	static float velocity;
	static float angle;
	static bool spt;
	static float g;
	static int score;
	static std::vector<PairRect> PR;

	static sf::SoundBuffer ChBuff[6];

	static sf::Sound Ch;
public:
	/// <summary>
	/// �������� ������� ��������
	/// </summary>
	static void init() {
		bird_tx[0].loadFromFile("Resources\\Images\\bird_1.png");
		bird_tx[1].loadFromFile("Resources\\Images\\bird_2.png");
		bird_tx[0].setSmooth(true);
		bird_tx[1].setSmooth(true);
		//bird.setTexture(bird_tx[0]);
		spt = false;
		bird.setScale(0.05f, 0.05f);
		bird.setOrigin(sf::Vector2f(bird_tx[0].getSize().x*0.05 / 2.f, bird_tx[0].getSize().y*0.05 / 2.f));
		x = 1024.f/2.f-36.f;
		y = 360.f;
		velocity = 0.f;
		g = 9.8f;
		bird.setPosition(x, y);
		
		PairRect temp1;
		temp1.s1.setSize(sf::Vector2f(60.f, 768.f));
		temp1.s2.setSize(sf::Vector2f(60.f, 768.f));
		temp1.s1.setFillColor(sf::Color(36, 252, 49));
		temp1.s2.setFillColor(sf::Color(36, 252, 49));
		temp1.s1.setPosition(-300.f, 0.f);
		temp1.s2.setPosition(-300.f, 768.f - 100.f-100.f);
		for (size_t i = 0; i < 3; i++)
		{
			PR.push_back(temp1);
		}
		srand(time(NULL));
		ChBuff[0].loadFromFile("Resources\\Sounds\\Ch\\ch1.wav");
		ChBuff[1].loadFromFile("Resources\\Sounds\\Ch\\ch2.wav");
		ChBuff[2].loadFromFile("Resources\\Sounds\\Ch\\ch3.wav");
		ChBuff[3].loadFromFile("Resources\\Sounds\\Ch\\ch4.wav");
		ChBuff[4].loadFromFile("Resources\\Sounds\\Ch\\ch5.wav");
		ChBuff[5].loadFromFile("Resources\\Sounds\\Ch\\ch6.wav");
		
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
	/// ��������� ������� ��������
	/// </summary>
	/// <param name="window">������� ����</param>
	/// <param name="event">�������</param>
	static void on_game(sf::RenderWindow* window, sf::Time deltatime, bool pause) {
	if (!pause)
	{
		float dts = deltatime.asSeconds();
		bird_move(dts);
		
		col_move(dts);
	}
	
	for (size_t i = 0; i < PR.size(); i++)
	{
		window->draw(PR[i].s1); 
		window->draw(PR[i].s2);
	}
	window->draw(bird);
	
	}
	static void col_move(float dts) {
		for (size_t i = 0; i < PR.size(); i++)
		{
			bool fl=true;
			if (PR[i].s1.getPosition().x <= -170) {
				int p = rand() %6  + 0;
				PR[i].s1.setPosition(sf::Vector2f(1124, -PR[i].s1.getSize().y + 100.f * p));
				PR[i].s2.setPosition(sf::Vector2f(1124, PR[i].s1.getSize().y + PR[i].s1.getPosition().y + 150.f));
			}
			if (i > 0) {
				if ((PR[i].s1.getPosition().x - PR[i - 1].s1.getPosition().x)<=400&& (PR[i].s1.getPosition().x - PR[i - 1].s1.getPosition().x) >= -400) {
					fl = false;
				}
			}
			if (fl) {
				PR[i].s1.move(-200.f * dts, 0);
				PR[i].s2.move(-200.f * dts, 0);
			}
		}
	}
	static void game_event(sf::Event* event) {
		if (event->type == sf::Event::KeyPressed) {
			if (event->key.code == sf::Keyboard::Space) {
				if (!spt)
					rand_ch();
				spt = true;
			}
			
		}
		if (event->type == sf::Event::MouseButtonPressed) {
			if (event->key.code == sf::Mouse::Left) {
				if (!spt)
					rand_ch();
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
				angle -= 360.f * dts;
			}
		}
		else
		{
			if (angle<=45.f)
			{
				angle += 30.f * dts;
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
	static void rand_ch()
	{
		int p = rand() % 6 + 0;
		Ch.setBuffer(ChBuff[p]);
		Ch.play();
	}
	
	
};

