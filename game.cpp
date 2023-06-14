#include "game.h"
sf::Texture game::bird_tx[2];
sf::Sprite game::bird;
float game::y;
float game::x;
float game::velocity;
float game::angle = 0.f;
bool game::spt;
float game::g;
std::vector<PairRect> game::PR;
//
