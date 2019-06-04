#pragma once
#include "GenericObjectWithEvents.h"

class ExtendedBox : public ofBoxPrimitive, public GenericObjectWithEvents
{
public:
	ExtendedBox() :ExtendedBox(50)
	{
	}
	ExtendedBox(int size)
	{
		this->set(size);
		RegisterMouseEvents();
		this->hasRadius = true;
		this->radius = size;
		GetInfo();
	}

	~ExtendedBox()
	{
		UnregisterMouseEvents();
	}

	void GetInfo();
	// Inherited via GenericObjectWithEvents
	virtual void draw(int x = 0, int y = 0, int w = 0, int h = 0, int screenW = 0, int screenH = 0) override;
};
