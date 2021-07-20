#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
class Waffle
{
private: 
	sf::RenderWindow* window;
	sf::Event e; 
	sf::VideoMode video; 
	

	void init(); // initializes all the variables 

	

public: 
	
	int rectw, numOfRects , a,b ; // number of rects is 800
	sf::RectangleShape rects[800]; // there are going to be 800 for now 
	Waffle(int width, int height);

	virtual ~Waffle(); 

	void input(); 
	void update(); 
	void draw(); 
	void run(); 
	void swap(sf::RectangleShape& a, sf::RectangleShape& b);
	void bubble(); 

	const bool running() const; 





};

