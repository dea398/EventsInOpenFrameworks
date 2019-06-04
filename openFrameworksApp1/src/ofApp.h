#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <GL/freeglut.h>

class ofApp : public ofBaseApp{

	public:
		ofxFloatSlider radius;
		ofxPanel gui;
		ofxButton button;
		
		int j = 0;
		int i = 100;
		int k = 150;
		
		void buttonPressed();
		void setup();
		void update();
		void draw();

		void DrawCube();

		void OtherCube();

		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
