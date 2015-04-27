#include "Ultron.h"

//This is used to draw and move Ultron
Ultron::Ultron(void)
{
	
	ultron.loadImage("ultron.png"); //loads Ultron image
	ultron.setAnchorPercent(.5, .5); //sets the anchor point in the center
	
}


Ultron::~Ultron(void)
{
}

void Ultron::setup(){

}

void Ultron::update(){
	//Noise gives Ultron a seemingly eratic movement, making it harder to predict where he'll fly
	x = ofMap( ofNoise( ofGetElapsedTimef()), 0, 1, 10, 1000); //used for Ultron's horizontal movement
	y = ofMap( ofNoise( 1000.0+ ofGetElapsedTimef()), 0, 1, 50, 300); //used for Ultron's vertical movement
}

void Ultron::draw(){
	ultron.draw(x, y); //draws Ultron
}