#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	bg.loadImage("bg.jpg"); //loads the bg image
	iron.loadImage("ironman.png"); //loads Ironman
	iron.setAnchorPercent (.5, .5); //puts Ironman's anchor point in the middle of him
	ironwin.loadImage("ironmanwins.jpg"); //loads Ironman Win pic
	ultwin.loadImage("ultronwins.jpg"); //loads Ultron Win pic

	ipos = ofVec2f(200, 500); //Ironman's starting position

	ironup = false; //this is used to determine if Ironman is flying
	fire = false; //this is used to determine if Ironman has his weapon beam
	iwin = false; //this is used to see if Ironman has won
	uwin = false; //this is used to see if Ultron has won

	ulthits = 0; //this tells us how many times Ultron has been hit (used for debugging)
	ironhits = 0; //this tells us how many times Ironman has been hit (used for debugging)
	ihealth = 100; //this is Ironman's starting health
	uhealth = 100; //this is Ultron's starting health
}

//--------------------------------------------------------------
void ofApp::update(){
	ult.update();
	if (ironup == false){ //these two loops determine if Ironman is flying or falling
		if(ipos.y < 500){
		ipos.y += 2; //falling
		}
	}
	if (ironup == true){
		if(ipos.y > 0){
		ipos.y -= 3; //flying
		}
	}

	Ultdots tempdot; //this section is used to create Ultron's red cloud
	tempdot.setup(ult.x, ult.y);
	ultdot.push_back(tempdot);
	for (int i = 0; i < ultdot.size(); i++){
		ultdot[i].update();
		float distance = ofDist(ultdot[i].birth.x, ultdot[i].birth.y, ultdot[i].pos.x, ultdot[i].pos.y);
		if (distance > 50){ //this erases the dots that have gone too far from their origin point so the computer doesn't overload
			ultdot.erase(ultdot.begin()+i);
			i--;
		}
	}
	
	

		Irondots tempidot; //this section is used to create Ironman's weapon beam
		tempidot.setup(ipos.x, ipos.y);
		irondot.push_back(tempidot);
		for (int i = 0; i < irondot.size(); i++){
			irondot[i].update();
			float distance2 = ofDist(irondot[i].birth.x, irondot[i].birth.y, irondot[i].pos.x, irondot[i].pos.y);
			if(distance2 > 200){ //this limits his beam's size
				irondot.erase(irondot.begin()+i);
				i--;
			}
		
		}

		if (uhealth == 0){ //this tells us if Ironman has won
			iwin = true;
			cout << "Ironman wins!" << endl;
		}
		if (ihealth == 0){ //this tells us if Ultron has won
			uwin = true;
			cout << "Ultron wins!" << endl;
		}
}

//--------------------------------------------------------------
void ofApp::draw(){
if (iwin == false && uwin == false){
	ofSetColor(255); //this makes sure image colors aren't affected by the colors of the dots
	bg.draw(0, 0); //draws the background
	ofSetColor(50, 200, 100); //color for healthbars
	ofRect(20, 50, ihealth, 10); //ironman health bar
	ofRect(900, 50, uhealth, 10); //ultron health bar
	

	for (int i = 0; i < ultdot.size(); i++){ //this draws Ultron's cloud
		ultdot[i].draw();
		float distance4 = ofDist(ultdot[i].pos.x, ultdot[i].pos.y, ipos.x, ipos.y);
			if(distance4 < 10 && ihealth > 0){ //this lets us determine if Ironman has been hit by the cloud
				ihealth-=.5; //this subtracts from Ironman's health if he's hit
				ironhits++; //this tells us how many times Ironman's been hit (used for debugging)
				cout << "Ironhit" << ironhits << endl;
			}
		}
		
	
	if (fire == true){ //if Ironman is firing (space is pressed)
		for (int i = 0; i < irondot.size(); i++){ //this draws Ironman's weapon beam
			irondot[i].draw();
			float distance3 = ofDist(irondot[i].pos.x, irondot[i].pos.y, ult.x, ult.y);
			if(distance3 < 15 && uhealth > 0){ //this tells us if Ironman has hit Ultron
				uhealth--; //this subtracts from Ultron's health if he's hit
				ulthits++; //this tells us how many times Ultron's been hit (used for debugging)
				cout << "Ulthit" << ulthits << endl;
			}
		}
	}
	ofSetColor(255); //makes sure the characters aren't tinted by the dot colors
	ult.draw();
	iron.draw(ipos);
}
if (iwin == true && uwin == false){ //shows Ironman win state
	ironwin.draw(0,0);
}
if (uwin == true && iwin == false){ //shows Ultron win state
	ultwin.draw(0,0);
}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

		if(key == OF_KEY_RIGHT) ipos.x+=8; //moves Ironman to the right
		if(key == OF_KEY_LEFT) ipos.x-=8; //moves Ironman to the left
		if(key == OF_KEY_UP) ironup = true; //makes Ironman fly
		if(key == ' ') fire = true; //fires Ironman's weapon beam
		if(key == '1') iwin = true; //will show Ironman win state (used for debugging)
		if(key == '2') uwin = true; //will show Ultron win state (used for debugging)
		if(key == '3'){ //sets back to game after win state reached (used for debugging)
			iwin = false;
			ihealth = 100;
			uwin = false;
			uhealth = 100;
		}
		
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key == OF_KEY_UP) ironup = false; //makes Ironman fall
	if(key == ' ') fire = false; //stops firing Ironman's beam
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
