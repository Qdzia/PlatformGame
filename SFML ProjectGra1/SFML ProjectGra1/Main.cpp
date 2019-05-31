#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Tutorials", Style::Default);
	window.setFramerateLimit(60);

	CircleShape shape(50.0f);

	while(window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//Update
		shape.move(0.1f, 0.5f);
		shape.setFillColor(Color::Black);
		//Draw
		
		window.clear(Color::Green);

		//Draw everything
		window.draw(shape);
		window.display();
	}

	return 0;
}