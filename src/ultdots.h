#pragma once

#include <ofMain.h>
//This is used to make Ultron's cloud
class Ultdots
{
public:
	Ultdots(void);
	~Ultdots(void);

	public:
		void setup(float _x, float _y);
		void update();
		void draw();

		ofVec2f pos, vel, birth;
		
		
};