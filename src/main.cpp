#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Button {
	sf::Sprite _sprite;
	public:
	Button(sf::Sprite &shape) {
		_sprite = shape;
	}

	void draw(sf::RenderWindow &window) {
		window.draw(_sprite);
	}

	void update(sf::Event &event) {
		if (event.type == sf::Event::MouseMoved) {
			if (_sprite.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
				cout<<"disappearing" <<endl;
				_sprite.setColor(sf::Color(255,255,255, 100));
			} else {
				cout<<"appearing..." <<endl;
				_sprite.setColor(sf::Color(255,255,255, 255));
			}
		}
	}
};

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

	sf::Font font;

	if (!font.loadFromFile("RubikBubbles-Regular.ttf")) {
		cout<<"we are fucked!"<<endl;
		exit(0);
	}

	sf::Texture texture;
	texture.loadFromFile("button.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);

	Button b(sprite);

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
			b.update(event);
        }

		window.clear();
		// window.draw(shape3);
		b.draw(window);
		// window.draw(shape2);
		window.display();
	}
	return 0;
}
