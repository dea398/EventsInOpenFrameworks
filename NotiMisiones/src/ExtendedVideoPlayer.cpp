#include "ExtendedVideoPlayer.h"
#include <iostream>


void ExtendedVideoPlayer::load(string& file)
{
	try
	{
		ofVideoPlayer::setPixelFormat(OF_PIXELS_BGRA);
		ofVideoPlayer::load(file);	
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}

ExtendedVideoPlayer::~ExtendedVideoPlayer()
{
	UnregisterMouseEvents();
}

void ExtendedVideoPlayer::setup()
{
	RegisterMouseEvents();
}

void ExtendedVideoPlayer::stop()
{
	ofVideoPlayer::stop();
	this->width = 0;
	this->height = 0;
	isDone = true;
}

void ExtendedVideoPlayer::play()
{
	ofVideoPlayer::play();
	isDone = false;
}

bool ExtendedVideoPlayer::isFullScreening() const
{
	return isFullScreen;
}

void ExtendedVideoPlayer::setRepeat(bool value)
{
	repeat = value;
	ofVideoPlayer::setPosition(0.0f);
}

void ExtendedVideoPlayer::setIsPreview(bool value)
{
	isPreview = value;
}

bool ExtendedVideoPlayer::getIsDone() const
{
	return isDone;
}

void ExtendedVideoPlayer::draw(int x, int y, int w, int h, int screenW, int screenH)
{
	if (isFullScreen)
	{
		ofSetColor(this->tempColor);
		this->x = 10;
		this->y = 10;
		this->width = screenW;
		this->height = screenH;
		ofVideoPlayer::draw(10, 10, screenW-10, screenH-10);
	}
	else
	{
		ofSetColor(this->myColor);
		this->x = x;
		this->y = y;
		this->width = w;
		this->height = h;
		ofVideoPlayer::draw(x, y, w, h);
	}

	if (!repeat)
	{
		if (ofVideoPlayer::getPosition() > 0.999f)
		{
			isDone = true;
			isFullScreen = false;
			ofVideoPlayer::setPosition(0.0f);
			this->stop();
			//this->closeMovie();
		}
	}
	if (isPreview)
	{
		if (ofVideoPlayer::getPosition()>previewDuration)
		{
			ofVideoPlayer::setPosition(0.0f);
		}
	}
	
}

void ExtendedVideoPlayer::mouseReleased(ofMouseEventArgs & args)
{
	if (inside(args.x, args.y)) 
	{
		// if the mouse is pressed over the object an event will be notified (broadcasted) 
		// the Event object will contain the mouse position, so this values are accesible to any class that is listening.
		ofVec2f mousePos = ofVec2f(args.x, args.y);
		ofNotifyEvent(clickedInside, mousePos, this);
		ofNotifyEvent(clickedGlobal, mousePos);
		++this->clicks;
		if (this->clicks==2)
		{
			this->isFullScreen = !this->isFullScreen;
			this->isPreview = !this->isPreview;
			if (this->isPreview)
			{
				ofVideoPlayer::setPosition(0.0f);
				ofVideoPlayer::setVolume(0.0f);
			}
			else
			{
				ofVideoPlayer::setPosition(previewDuration);
				ofVideoPlayer::setVolume(1.0f);
			}
			this->clicks = 0;
		}
	}
}


