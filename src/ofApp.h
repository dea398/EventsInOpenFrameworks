#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ExtendedSphere.h"
#include "ExtendedBox.h"

class ofApp : public ofBaseApp{

	public:
		ofxFloatSlider radius;
		ofxPanel gui;
		ofxButton button;

		ofBoxPrimitive box;
		ofSpherePrimitive sphere;
		ofEasyCam cam;

		std::list<ExtendedSphere> spheres;

		ExtendedBox eBox;

		int j = 0;
		int i = 100;
		int k = 100;

		void setup();
		void update();
		void draw();

		void buttonPressed();
		void OtherCube();
		void DrawCube();

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
		void onMouseIn(ofVec2f & e);
};
