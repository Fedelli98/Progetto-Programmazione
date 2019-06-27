#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable{
public:
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	Player();

	
	template<typename ... Args>
	void  setPosition(Args&& ...  args) {//&& serve per dare al compilatore il compito di riconoscere il tipo di dato passato 
		_shape.setPosition(std::forward<Args>(args)...);
	}

	void update(sf::Time deltaTime);
	bool isMoving;
	int rotation;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape _shape;
	sf::Vector2f _velocity;

};

