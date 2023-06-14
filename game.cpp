#include "game.h"
sf::Texture game::bird_tx[2];
sf::Sprite game::bird;
float game::y;
float game::x;
float game::velocity;
float game::angle = 0.f;
bool game::spt;
float game::g;
int game::score;
sf::SoundBuffer game::ChBuff[6];
sf::Sound game::Ch;
std::vector<PairRect> game::PR;
sf::Text game::score_txt;
sf::Font game::font;
//
