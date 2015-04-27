#pragma once

#include <ofMain.h>
//This is used to draw and move Ultron
class Ultron
{
public:
	Ultron(void);
	~Ultron(void);

	public:
		void setup();
		void update();
		void draw();

		ofImage ultron;
		float x, y;
		
};