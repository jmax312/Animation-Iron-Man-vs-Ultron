#include "Ultdots.h"

//This is used to make Ultron's cloud
Ultdots::Ultdots(void)
{
		vel = ofVec2f(ofRandom(-.5, .5), ofRandom(-.5, .5)); //velocity for the cloud particles
			
}


Ultdots::~Ultdots(void)
{
}

void Ultdots::setup(float _x, float _y){
	pos = ofVec2f(_x, _y); //start position of cloud particles (Ultron image)
	birth = pos; //sets point of origin for particles (used to destroy ones that are too far)
}

void Ultdots::update(){
	pos+=vel; //moves particles

}

void Ultdots::draw(){
	ofPushMatrix();
	ofTranslate(pos); //helps particles track Ultron's movements
	ofSetColor(200, 50, 50);
	ofCircle(0, 0, 10);
	ofPopMatrix();
}

