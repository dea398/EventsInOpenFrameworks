#pragma once

#include "ofMain.h"
#include <vector>
#include "ExtendedVideoPlayer.h"
#include <deque>
#include <memory>

using namespace std;

class ofApp : public ofBaseApp{

	public:
		int myClicks = 0;
		bool isVideoFull = false;
		ofImage background;
		ofImage title;
		string introVideo = "movies/Intro.mp4";
		unique_ptr<ExtendedVideoPlayer> intro = make_unique<ExtendedVideoPlayer>("intro", 0, introVideo,false,0);

		std::list<ExtendedVideoPlayer> misioneros;
		int numberOfMissions=6;
		const string misionero = "misionero";
		int marginX = 180;
		int marginY = 102;
		
		int yStart = 200;

		int numberOfColumns;
		int numberOfRows = 2;
		int tableWidth;
		int tableHeight;

		int maxWidthVideo;
		int maxHeightVideo;
		int widthVideo;
		int heightVideo;

		bool playIntro;

		void setup();
		void startIntro();
		void update();
		void draw();

		void stopVideos();

		void Drawing(int i, ExtendedVideoPlayer & o);

		string temporalFunctionGetFileName(int i);
		float temporalFunctionGetPreviewDuration(int i);
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
		void onMouseInVideo(ofVec2f & e);
		
};
