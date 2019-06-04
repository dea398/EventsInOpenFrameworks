#pragma once
#include "GenericObjectWithEvents.h"

class ExtendedSphere: public GenericObjectWithEvents, 
	public ofSpherePrimitive
{

public:
	ExtendedSphere() :ExtendedSphere(10)
	{

	}
	ExtendedSphere(int radius)
	{
		GenericObjectWithEvents::setRadius(radius);
		RegisterMouseEvents();
	}
	~ExtendedSphere()
	{
		UnregisterMouseEvents();
	}

	// Inherited via GenericObjectWithEvents
	virtual void draw(int x=0, int y=0, int w=0, int h=0, int screenW = 0, int screenH = 0) override;
};

