#include "GenericObjectWithEvents.h"

// the static event, or any static variable, must be initialized outside of the class definition.
ofEvent<ofVec2f> GenericObjectWithEvents::clickedGlobal = ofEvent<ofVec2f>();

GenericObjectWithEvents::~GenericObjectWithEvents()
{
	UnregisterMouseEvents();
}

void GenericObjectWithEvents::RegisterMouseEvents()
{
	ofRegisterMouseEvents(this); // this will enable our circle class to listen to the mouse events.
	withEvents = true;
}

void GenericObjectWithEvents::UnregisterMouseEvents()
{
	if (withEvents)
	{
		ofUnregisterMouseEvents(this); // disable listening to mouse events.
		withEvents = false;
	}
}

void GenericObjectWithEvents::setWithHoverEffect(bool value)
{
	withHoverEffect = value;
}

void GenericObjectWithEvents::setColor(ofColor color)
{
	myColor = color;
	tempColor = color;
}

void GenericObjectWithEvents::setHoverColor(ofColor color)
{
	hoverColor = color;
}

void GenericObjectWithEvents::setRadius(int radius)
{
	this->radius = radius;
	setHasRadius(true);
}

void GenericObjectWithEvents::setHasRadius(bool value)
{
	hasRadius = value;
}

void GenericObjectWithEvents::mouseDragged(ofMouseEventArgs & mouse)
{
}

void GenericObjectWithEvents::mousePressed(ofMouseEventArgs & mouse)
{
}

bool GenericObjectWithEvents::inside(float _x, float _y)
{
	if (hasRadius)
	{
		return (ofVec2f(_x, _y).distance(ofVec2f(x, y)) < radius);
	}
	else
	{
		return ((_x > x) && (_x < x + width) && (_y > y) && (_y < y + height));
	}
}

void GenericObjectWithEvents::mouseMoved(ofMouseEventArgs & mouse)
{
	if (inside(mouse.x, mouse.y))
	{
		// if the mouse is hovered the object an event will be notified (broadcasted) 
		// the Event object will contain the mouse position, so this values are accesible to any class that is listening.
		ofVec2f mousePos = ofVec2f(mouse.x, mouse.y);
		ofNotifyEvent(hovered, mousePos, this);
		isHovered = true;
		if (withHoverEffect)
		{
			myColor = hoverColor;
		}
	}
	else
	{
		if (isHovered)
		{
			if (!inside(mouse.x, mouse.y))
			{
				ofVec2f mousePos = ofVec2f(mouse.x, mouse.y);
				ofNotifyEvent(hovered, mousePos, this);
				isHovered = false;
				if (withHoverEffect)
				{
					myColor = tempColor;
				}
			}
		}
	}
}

void GenericObjectWithEvents::mouseReleased(ofMouseEventArgs & args)
{
	if (inside(args.x, args.y))
	{
		// if the mouse is pressed over the object an event will be notified (broadcasted) 
		// the Event object will contain the mouse position, so this values are accesible to any class that is listening.
		ofVec2f mousePos = ofVec2f(args.x, args.y);
		ofNotifyEvent(clickedInside, mousePos, this);
		ofNotifyEvent(clickedGlobal, mousePos);
		++this->clicks;
		if (this->clicks == 2)
		{
			this->clicks = 0;
		}

	}
}

void GenericObjectWithEvents::mouseScrolled(ofMouseEventArgs & args)
{
}

void GenericObjectWithEvents::mouseEntered(ofMouseEventArgs & args)
{

}

void GenericObjectWithEvents::mouseExited(ofMouseEventArgs & args)
{

}
