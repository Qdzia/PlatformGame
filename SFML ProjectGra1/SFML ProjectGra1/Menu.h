#pragma once
#include "GameObject.h"
using namespace sf;


class Menu
{
private:
	int selectedItemIndex;
	Font font;
	Text menu[4];
	
public:
	
	Menu(float width, float height);
	~Menu();
	void draw(RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void drawScore(RenderWindow &window, int score);
};

