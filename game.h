#pragma once
#include <SFML/Graphics.hpp>
class game
{
private:
	static sf::Texture bird_tx[2];
	static sf::Sprite bird;
public:
	static void init() {
		bird_tx[0].loadFromFile("Resources\\Images\\bird_1.png");
		bird_tx[1].loadFromFile("Resources\\Images\\bird_2.png");
		bird.setTexture(bird_tx[0]);
		bird.setPosition(200, 200);
		bird.setScale(0.2f, 0.2f);
	}
	static void on_game(sf::RenderWindow *window, sf::Event *event) {
		
		while (window->pollEvent(*event))
		{
			if (event->type == sf::Event::Closed)
				window->close();
			if (event->type == sf::Event::KeyPressed) {
				if (event->key.code == sf::Keyboard::Space) {
					bird.setTexture(bird_tx[1]);
				}
				else {
					bird.setTexture(bird_tx[0]);
				}
			}
		}
		window->clear(sf::Color(0, 0, 0));
		window->draw(bird);
		window->display();
		


	}

};

