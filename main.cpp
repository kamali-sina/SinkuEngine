#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Yosk");
	sf::CircleShape shape(200);
    shape.setFillColor(sf::Color(255,0,0));
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
            }
        }

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
