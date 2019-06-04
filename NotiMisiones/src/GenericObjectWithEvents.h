#pragma once
#include "ofMain.h"
class GenericObjectWithEvents
{
protected:
	bool withEvents;
	bool isBeingDragged;
	bool isHovered;
	bool withHoverEffect;
	uint8_t clicks;
	
	ofColor myColor;
	ofColor tempColor;
	ofColor hoverColor;
	int x;
	int y;
	int height;
	int width;
	

public:
	static ofEvent<ofVec2f> clickedGlobal;
	ofEvent<ofVec2f> clickedInside;
	ofEvent<ofVec2f> hovered;
	ofEvent<ofVec2f> exited;
	GenericObjectWithEvents() 
	{
		clicks = 0;
		isHovered = false;
		isBeingDragged = false;
		withEvents = false;
		withHoverEffect = true;
		myColor = ofColor::white;
		tempColor = myColor;
		hoverColor = ofColor::lightGreen;
	}
	virtual ~GenericObjectWithEvents();

	void RegisterMouseEvents();
	void UnregisterMouseEvents();
	void setWithHoverEffect(bool value);
	void setColor(ofColor color);
	void setHoverColor(ofColor color);
	virtual void draw(int x, int y, int w, int h, int screenW=0, int screenH=0) = 0;
	virtual void mouseDragged(ofMouseEventArgs & mouse);
	virtual void mousePressed(ofMouseEventArgs & mouse);
	virtual void mouseMoved(ofMouseEventArgs & mouse);
	virtual void mouseReleased(ofMouseEventArgs & args);
	virtual void mouseScrolled(ofMouseEventArgs & args);
	virtual void mouseEntered(ofMouseEventArgs & args);
	virtual void mouseExited(ofMouseEventArgs & args);
	virtual bool inside(float _x, float _y);
};

