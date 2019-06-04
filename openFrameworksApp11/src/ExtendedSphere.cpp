#include "ExtendedSphere.h"


void ExtendedSphere::draw(int x, int y, int w, int h, int screenW , int screenH )
{
	ofSetColor(this->myColor);
	auto currentPos = this->getPosition();
	this->x = currentPos.x;
	this->y = currentPos.y;
	ofSpherePrimitive::draw();
}
