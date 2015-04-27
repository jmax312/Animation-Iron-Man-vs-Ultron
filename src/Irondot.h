#pragma once

#include <ofMain.h>
//This is for Ironman's weapon beam
class Irondots
{
public:
	Irondots(void);
	~Irondots(void);

	public:
		void setup(float _x, float _y);
		void update();
		void draw();

		ofVec2f pos, vel, birth;
		
		
};