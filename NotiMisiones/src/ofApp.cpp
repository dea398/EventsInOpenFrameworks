#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

	//ofSetVerticalSync(true);
	if (numberOfMissions==0)
	{
		numberOfMissions = 1;
	}

	numberOfColumns = numberOfMissions / 2;
	if (numberOfColumns==0)
	{
		numberOfColumns = 1;
		numberOfRows = 1;
	}
	
	background.load("images/NotiMisionesBackground.jpeg");
	title.load("images/Title2.png");
	
	for (size_t i = 0; i < numberOfMissions; i++)
	{
		misioneros.emplace_back(to_string(i), i, 
			temporalFunctionGetFileName(i), true, 
			temporalFunctionGetPreviewDuration(i));
		misioneros.back().setRepeat(false);
	}

	//------------registering (adding) listeners ----------

	//ofAddListener(ExtendedVideoPlayer::clickedGlobal, //the ofEvent that we want to listen to. In this case exclusively to the circleEvent of redCircle (red circle) object.
	//	this, //pointer to the class that is going to be listening. it can be a pointer to any object. There's no need to declare the listeners within the class that's going to listen.
	//	&ofApp::onMouseInVideo);//pointer to the method that's going to be called when a new event is broadcasted (callback method). The parameters of the event are passed to this method.

	
	maxWidthVideo = misioneros.front().getWidth()*3;
	maxHeightVideo = misioneros.front().getHeight()*3;
	//widthOffset = (ofGetWidth() / factor) / (factor);
	marginX = (ofGetWidth()*0.15) * (float)(1.0/numberOfColumns);
	marginY = (ofGetHeight() * 0.1) * (float)(1.0 / numberOfRows);
	
	widthVideo = (ofGetWidth() / numberOfColumns);
	heightVideo = (ofGetHeight()-yStart) / numberOfRows;
	
	startIntro();
	ofToggleFullscreen();
}

void ofApp::startIntro()
{
	playIntro = true;
	intro->UnregisterMouseEvents();
	intro->setRepeat(false);
	intro->play();
}

//--------------------------------------------------------------
void ofApp::update()
{	
	if (playIntro && intro)
	{
		intro->update();
	}
	else
	{
		for (auto &o : misioneros)
		{
			if (!o.getIsDone())
			{
				o.update();
			}
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(255);

	if (playIntro && intro)
	{
		intro->draw(0, 0, ofGetWidth(), ofGetHeight());
		
		if (intro->getIsDone())
		{
			playIntro = false;
			//auto ptr=intro.release();
			//delete ptr;
			for (auto &o : misioneros)
			{
				o.play();
			}
		}
	}
	else
	{
		background.draw(0, 0, ofGetWidth(), ofGetHeight());
		
		title.draw(ofGetWidth()/2 - title.getWidth()/2, 0);
		
		isVideoFull = false;
		int i = 0;
		for (auto &o : misioneros)
		{
			if (o.isFullScreening())
			{
				isVideoFull = true;				
				Drawing(i, o);
				break;
			}
			i++;
		}
		if (isVideoFull)
		{
			stopVideos();
		}

		if (!isVideoFull)
		{
			i = 0;
			for (auto &o : misioneros)
			{
				if (o.getIsDone())
				{
					o.setIsPreview(true);
					o.setVolume(0.0f);
					o.play();
				}
				Drawing(i, o);
				i++;
			}
		}	

	}
	/*ofDrawBitmapString("duration: " + ofToString(intro.getDuration()),0,50);
	ofDrawBitmapString("position: " + ofToString(intro.getPosition()), 0, 100);*/
}

void ofApp::stopVideos()
{
	for (auto &o : misioneros)
	{
		if (!o.getIsDone() && !o.isFullScreening())
		{
			o.stop();
		}
	}
}

void ofApp::Drawing(int i, ExtendedVideoPlayer & o)
{
	int x = ((int)(ofGetWidth() / numberOfColumns))*(i%numberOfColumns);
	int y = (int)(i / numberOfColumns) * ((ofGetHeight() - yStart) / numberOfRows);
	int currentWidth = widthVideo - (marginX * 2);
	int currentHeight = heightVideo - (marginY * 2);
	if (currentHeight > maxHeightVideo)
	{
		currentHeight = maxHeightVideo;
	}
	if (currentWidth > maxWidthVideo)
	{
		currentWidth = maxWidthVideo;
	}

	o.draw(x + marginX, y + yStart, currentWidth, currentHeight, ofGetWidth(), ofGetHeight());
}

string ofApp::temporalFunctionGetFileName(int i)
{
	switch (i)
	{
	case 0:
		return "movies/Australia.mp4";
	case 1:
		return "movies/Brazil.mp4";
	case 2:
		return "movies/Madrid.mp4";
	case 3:
		return "movies/London.mp4";
	case 4:
		return "movies/Japan.mp4";
	case 5:
		return "movies/France.mp4";
	default:
		return "movies/fingers.mov";
	}
}

float ofApp::temporalFunctionGetPreviewDuration(int i)
{
	switch (i)
	{
	case 0:
		return 0.31f;
	case 1:
		return 0.14f;
	case 2:
		return 0.12f;
	case 3:
		return 0.14f;
	case 4:
		return 0.16f;
	case 5:
		return 0.15f;
	default:
		return 0.1f;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case 'f':
	{
		ofToggleFullscreen();
		break;
	}
	case 'i':
	{
		stopVideos();
		startIntro();
		break;
	}
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	//widthOffset = (ofGetWidth() / factor) / (factor);
	marginX = (ofGetWidth() * 0.15) * (float)(1.0 / numberOfColumns);
	marginY = (ofGetHeight() * 0.1) * (float)(1.0 / numberOfRows);
	widthVideo = (ofGetWidth() / numberOfColumns);
	heightVideo = (ofGetHeight() - yStart) / numberOfRows;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::onMouseInVideo(ofVec2f & e)
{
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
