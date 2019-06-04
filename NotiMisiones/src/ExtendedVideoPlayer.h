#pragma once
#include "ofMain.h"
#include "GenericObjectWithEvents.h"
class ExtendedVideoPlayer: public ofVideoPlayer, public GenericObjectWithEvents
{
private:
	string myName;
	int myIndex;
	string myFile;
	bool isFullScreen;
	void load(string & file);
	bool isPreview;
	float previewDuration;
	bool repeat;
	bool isDone;
public:

	ExtendedVideoPlayer(): ExtendedVideoPlayer("Unknown",0,"",false,0.0f)
	{
			
	}
	ExtendedVideoPlayer(string name, int index, string file,bool isPreview,float previewDuration)
	{
		myName = name;
		myIndex= index;
		isFullScreen = false;
		this->isPreview = isPreview;
		this->previewDuration = previewDuration;
		repeat = true;
		isDone = false;
		if (file!="")
		{
			myFile = file;
			load(myFile);
			if (this->isPreview)
			{
				this->setVolume(0.0f);
			}
			setup();
		}
	}
	~ExtendedVideoPlayer();
	
	// Inherited via GenericObjectWithEvents
	void setup();
	void stop();
	void play();
	bool isFullScreening() const;
	void setRepeat(bool value);
	void setIsPreview(bool value);
	bool getIsDone() const;
	virtual void draw(int x, int y, int w, int h, int screenW=0, int screenH=0) override;
	virtual void mouseReleased(ofMouseEventArgs & args) override;

};

