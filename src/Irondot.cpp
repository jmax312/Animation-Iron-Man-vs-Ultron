#include "Irondot.h"

//This is for Ironman's weapon beam
Irondots::Irondots(void)
{
	vel = ofVec2f(4, 0); //velocity for the beam particles
	
}


Irondots::~Irondots(void)
{
}

void Irondots::setup(float _x, float _y){
	pos = ofVec2f(_x, _y); //start position of beam particles (Ironman image)
	birth = pos; //sets point of origin for particles (used to destroy ones that are too far)
}

void Irondots::update(){
	pos+=vel; //moves particles

}

void Irondots::draw(){
	ofPushMatrix();
	ofTranslate(pos); //helps particles track Ironman's movements
	ofSetColor(20, 170, 220);
	ofCircle(0, 0, 10);
	ofPopMatrix();
}

