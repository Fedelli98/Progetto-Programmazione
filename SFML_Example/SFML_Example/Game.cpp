#include "Game.h"

Game::Game() : _window(sf::VideoMode(800, 600), "02_Game_Archi"), _player(){//"..." è il titolo della finestra che appare
	//_player.setFillColor(sf::Color::Blue);
	_player.setPosition(20, 20);
}

/*void Game::run(int FPS){

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / FPS);

	while (_window.isOpen()) {
		processEvents();
		bool repaint = false;

		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame){
			timeSinceLastUpdate -= timePerFrame;
			repaint = true;
			update(timePerFrame);
		}
		if (repaint)
			render();
	}
}*/ //1o metodo per tenere sotto controllo i frame per secondo  

void Game::run(int minimum_frame_per_second) {//2o metodo per tenere sotto controllo i fps
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time timePerSecond = sf::seconds(1.f / minimum_frame_per_second);
	
	while (_window.isOpen()) {
		processEvents();
		timeSinceLastUpdate = clock.restart();
		while (timeSinceLastUpdate > timePerSecond) {
			timeSinceLastUpdate -= timePerSecond;
			update(timePerSecond);
		}
		update(timeSinceLastUpdate);
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (_window.pollEvent(event)) {
		if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			_window.close();
		else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape)
				_window.close();
			else if (event.key.code == sf::Keyboard::Up)
				_player.isMoving = true;
			else if (event.key.code == sf::Keyboard::Left)
				_player.rotation = -1;
			else if (event.key.code == sf::Keyboard::Right)
				_player.rotation = 1;
		}
		else if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Up)
				_player.isMoving = false;
			else if (event.key.code == sf::Keyboard::Left)
				_player.rotation = 0;
			else if(event.key.code == sf::Keyboard::Right)
				_player.rotation = 0;
		}
	}
}

void Game::update(sf::Time deltaTime){
	//game logic
}

void Game::render(){
	_window.clear();
	_window.draw(_player);
	_window.display();
}
