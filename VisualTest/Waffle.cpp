#include "Waffle.h"

void Waffle::init()
{
	this->window = nullptr;

	this->window = new sf::RenderWindow(this->video, "Sorting Visualiztion"); //creates on the heap so we have to delete when we are done using it 

	
	
	
	
}

Waffle::Waffle(int width, int height)
{	
	srand(time(NULL)); 

	this->video.width = width;
	this->video.height = height;
	this->rectw = 5; 
	
	this->numOfRects = width / this->rectw; 
	this->a = 0; 
	this->b = 1; 
	//initializes the size of the array
	for (int i = 0; i < numOfRects; i++)
	{
		int randh = rand() % this->video.height + 30;
		
		
		this->rects[i].setPosition(sf::Vector2f(this->rectw * i, this->video.height - randh));
		this->rects[i].setSize(sf::Vector2f(this->rectw, randh));
		this->rects[i].setFillColor(sf::Color::White);
	}
	init(); 
}

Waffle::~Waffle()
{
	delete this->window; 
}

void Waffle::input()
{
	while (this->window->pollEvent(this->e))
	{
		switch (e.type)
		{
		case sf::Event::Closed: 
			this->window->close(); 
			break; 
		case sf::Event::KeyPressed:
			switch (e.key.code) // keyboard input 
			{
			case sf::Keyboard::Escape:
				std::cout << "Closed with escape" << std::endl; 
				this->window->close(); 
				break; 
			}
			
			break; 
		}
	}
}

void Waffle::update()// update the game logic 
{
	/*for (int i = 0; i < this->numOfRects-1; i++)
	{
		const int b = i + 1; 
		if (rects[i].getSize().y> rects[b].getSize().y)
		{
			//this->swap( rects[i], rects[b]); 
			i = 0; 
		}
	} */

	this->bubble(); 
	
	
}

void Waffle::draw()
{
	this->window->clear(); 
	/*draw here */

	for (int i =0 ; i<this->numOfRects; i++	)
	{
		this->window->draw(this->rects[i]); 
	}
	

	/*draw here */
	this->window->display(); 
}

void Waffle::run()
{
	while (this->window->isOpen())
	{
		this->input();// pollsevents  
		this->update(); //updates
		this->draw(); //renders to the screen 
	}
}

const bool Waffle::running() const
{
	return this->window->isOpen();
}

void Waffle::swap( sf::RectangleShape &a ,sf::RectangleShape &b)
{
	/*
	*/
	sf::RectangleShape dummy(sf::Vector2f(a.getSize().x,a.getSize().y)); 
	//dummy.setPosition(a.getPosition().x,a.getPosition().y); 
	a.setSize(sf::Vector2f(b.getSize().x,b.getSize().y));
	a.setPosition(sf::Vector2f(a.getPosition().x,this->video.height-a.getSize().y)); 
	b.setSize(sf::Vector2f(dummy.getSize().x,dummy.getSize().y)); 
	b.setPosition(sf::Vector2f(b.getPosition().x, this->video.height - b.getSize().y));
	
	
}

void Waffle::bubble()
{
	for (int i = 0; i < 350; i++)// this is how much it does it per update ; determines the speed of the sorting 
	{
		if (a < numOfRects - 1 && b < numOfRects)
		{
			if (rects[a].getSize().y > rects[b].getSize().y)// the one before is less than the one after
			{
				this->swap(rects[a], rects[b]);
				this->a = 0;
				this->b = 1;
			}
			else
			{
				this->a++;
				this->b++;
			}

		}
		else
		{
			for (int j = 0; j < numOfRects; j++)
			{
				rects[j].setFillColor(sf::Color::Blue); 
			}
		}
	}
}
