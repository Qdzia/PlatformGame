#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Tutorials", Style::Default);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//Update

		//Draw
		window.clear();

		//Draw everything
		window.display();
	}

	return 0;
}