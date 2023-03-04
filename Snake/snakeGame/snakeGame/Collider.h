#pragma once
class Collider
{
public:
	Collider(sf::RectangleShape* body);
	virtual ~Collider();
	
	bool checkCollision(const Collider& other);

	//Getters
	sf::Vector2f getHalfSize() const;
	sf::Vector2f getPos() const;

private:
	sf::RectangleShape* body;
};

