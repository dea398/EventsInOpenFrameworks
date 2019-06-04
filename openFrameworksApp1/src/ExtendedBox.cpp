#include "ExtendedBox.h"


void ExtendedBox::GetInfo()
{
	auto currentPos = this->getPosition();
	this->x = currentPos.x;
	this->y = currentPos.y;
	this->width = this->getWidth();
	this->height = this->getHeight();
}

void ExtendedBox::draw(int x, int y, int w, int h, int screenW, int screenH)
{
	GetInfo();
	ofSetColor(this->myColor);
	ofBoxPrimitive::draw();
}
