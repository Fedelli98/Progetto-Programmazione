#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
public:
	Game(const Game&) = delete;
	Game& operator=(const Game) = delete;
	Game();
	//void run(int FPS);
	void run(int minimum_frame_per_second);

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	sf::RenderWindow _window;
	Player _player;
};