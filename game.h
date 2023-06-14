#pragma once
#include <SFML/Graphics.hpp>
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
public:
	/// <summary>
	/// Загрузка игровых объектов
	/// </summary>
	static void init() {
		bird_tx[0].loadFromFile("Resources\\Images\\bird_1.png");
		bird_tx[1].loadFromFile("Resources\\Images\\bird_2.png");
		bird.setTexture(bird_tx[0]);
		bird.setPosition(200, 200);
		bird.setScale(0.2f, 0.2f);
	}
	/// <summary>
	/// Отрисовка игровых объектов
	/// </summary>
	/// <param name="window">Главное окно</param>
	/// <param name="event">Событие</param>
	static void on_game(sf::RenderWindow *window, sf::Event *event) {
		
		
			if (event->type == sf::Event::KeyPressed) {
				if (event->key.code == sf::Keyboard::Space) {
					bird.setTexture(bird_tx[1]);
				}
				else {
					bird.setTexture(bird_tx[0]);
				}
			}
		
		
		window->draw(bird);

		


	}

};

