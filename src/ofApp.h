#pragma once

#include "ofMain.h"
#include "ultron.h"
#include "ultdots.h"
#include "Irondot.h"
#define number 3

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofImage bg, iron, ironwin, ultwin;
		ofVec2f ipos;
		bool ironup, fire, iwin, uwin;
		float ulthits, ironhits, ihealth, uhealth;

		Ultron ult; 
		vector <Ultdots> ultdot;
		vector <Irondots> irondot;
};
