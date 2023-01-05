#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Yosk");
	sf::CircleShape shape(200);
	sf::CircleShape shape2(5);

	shape2.setPosition(20,20);
	shape2.setFillColor(sf::Color(0,0,255));
	cout<<shape.getGlobalBounds().contains(shape2.getPosition())<<endl;
	cout<<shape.getPosition().x<< "   " <<shape.getPosition().y<<endl;
    shape.setFillColor(sf::Color(255,0,0));
	sf::RectangleShape shape3(sf::Vector2f(50,50));
	shape3.setPosition(50,50);
	shape3.setFillColor(sf::Color(0,255,0));
    int r = 200;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Key::J) {
                    shape.setRadius(--r);
                    shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y);
                }
            } else if (event.type == sf::Event::MouseButtonPressed) {
				if (shape3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					shape3.setPosition(shape3.getPosition().x + 5, shape3.getPosition().y);
				}
			}
        }

		window.clear();
		window.draw(shape3);
		// window.draw(shape2);
		window.display();
	}
	return 0;
}
