#include "ofApp.h"

GLfloat angleCube = 0.0f;     // Rotational angle for cube

ofBoxPrimitive box;

//--------------------------------------------------------------
void ofApp::setup()
{
	button.addListener(this, &ofApp::buttonPressed);

	gui.setup();
	gui.add(radius.setup("radius", 140, 10, 300));
	gui.add(button.setup("Add Sphere"));
	ofBackground(0, 0, 0);

	box.set(200);
	
	//box.move(700, 100, -200);
	ofAddListener(eBox.clickedInside, //the ofEvent that we want to listen to. In this case exclusively to the circleEvent of redCircle (red circle) object.
		this, //pointer to the class that is going to be listening. it can be a pointer to any object. There's no need to declare the listeners within the class that's going to listen.
		&ofApp::onMouseIn);//pointer to the method that's going to be called when a new event is broadcasted (callback method). The parameters of the event are passed to this method.

	eBox.setPosition(650, 300, 0);
}

void ofApp::exit()
{
	button.removeListener(this, &ofApp::buttonPressed);
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	/*for (size_t x = 0; x < j; x++)
	{
		ofDrawSphere(200*(x+1), 200*(x+1), radius);
	}*/

	int x = 0;
	for (auto & s : spheres)
	{
		s.setPosition(200 * (x + 1), 200 * (x + 1), 0);
		s.draw();
		++x;
	}

	gui.draw();

	ofEnableDepthTest();

	ofPushMatrix();
		DrawCube();
	ofPopMatrix();

	ofPushMatrix();
		OtherCube();
	ofPopMatrix();

	ofSetColor(255, 255, 255);
	ofPushMatrix();
		ofTranslate(700, 100, -200);
		ofRotateDeg(angleCube, 1.0f, 1.0f, 1.0f);
		//box.rotate(-0.15f, 1.0f, 1.0f, 1.0f);
		//box.move(10, 0, 0);
		
		box.drawWireframe();
	ofPopMatrix();

	//ofDrawBox(100);
	ofPushMatrix();
	ofSetColor(ofColor::white);
	eBox.rotate(-0.15f, 1.0f, 1.0f, 1.0f);
	eBox.draw();
	ofPopMatrix();

	ofDisableDepthTest();
}

void ofApp::onMouseIn(ofVec2f & e)
{
	eBox.setColor(ofColor(rand() * 255, rand() * 255, rand() * 255));

}

void ofApp::DrawCube()
{
	glTranslatef(400.0f, 250.0f, -400.0f);  // Move right and into the screen
	glRotatef(angleCube, 1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
	// Top face (y = i)
	glColor3f(0.0f, 1.0f, 0.0f);     // Green
	glVertex3f(i, i, -i);
	glVertex3f(-i, i, -i);
	glVertex3f(-i, i, i);
	glVertex3f(i, i, i);

	// Bottom face (y = -i)
	glColor3f(1.0f, 0.5f, 0.0f);     // Orange
	glVertex3f(i, -i, i);
	glVertex3f(-i, -i, i);
	glVertex3f(-i, -i, -i);
	glVertex3f(i, -i, -i);

	// Front face  (z = i)
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(i, i, i);
	glVertex3f(-i, i, i);
	glVertex3f(-i, -i, i);
	glVertex3f(i, -i, i);

	// Back face (z = -i)
	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f(i, -i, -i);
	glVertex3f(-i, -i, -i);
	glVertex3f(-i, i, -i);
	glVertex3f(i, i, -i);

	// Left face (x = -i)
	glColor3f(0.0f, 0.0f, 1.0f);     // Blue
	glVertex3f(-i, i, i);
	glVertex3f(-i, i, -i);
	glVertex3f(-i, -i, -i);
	glVertex3f(-i, -i, i);

	// Right face (x = i)
	glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3f(i, i, -i);
	glVertex3f(i, i, i);
	glVertex3f(i, -i, i);
	glVertex3f(i, -i, -i);
	glEnd();

	angleCube -= 0.15f;
}

void ofApp::OtherCube()
{
	// Render a color-cube consisting of 6 quads with different colors
	glTranslatef(200.0f, 500.0f, -100.0f);
	//glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]
	//play with values above
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	   // Top face (y = k)
	   // Define vertices in counter-clockwise (CCW) order with normal pointing out
	ofSetColor(0, 255, 0);
	//glColor3f(0.0f, 1.0f, 0.0f);     // Green
	glVertex3f(k, k, -k);
	glVertex3f(-k, k, -k);
	glVertex3f(-k, k, k);
	glVertex3f(k, k, k);

	// Bottom face (y = -k)
	glColor3f(k, 0.5f, 0.0f);     // Orange
	glVertex3f(k, -k, k);
	glVertex3f(-k, -k, k);
	glVertex3f(-k, -k, -k);
	glVertex3f(k, -k, -k);

	// Front face  (z = k)
	glColor3f(k, 0.0f, 0.0f);     // Red
	glVertex3f(k, k, k);
	glVertex3f(-k, k, k);
	glVertex3f(-k, -k, k);
	glVertex3f(k, -k, k);

	// Back face (z = -k)
	glColor3f(k, k, 0.0f);     // Yellow
	glVertex3f(k, -k, -k);
	glVertex3f(-k, -k, -k);
	glVertex3f(-k, k, -k);
	glVertex3f(k, k, -k);

	// Left face (x = -k)
	glColor3f(0.0f, 0.0f, k);     // Blue
	glVertex3f(-k, k, k);
	glVertex3f(-k, k, -k);
	glVertex3f(-k, -k, -k);
	glVertex3f(-k, -k, k);

	// Right face (x = k)
	glColor3f(k, 0.0f, k);     // Magenta
	glVertex3f(k, k, -k);
	glVertex3f(k, k, k);
	glVertex3f(k, -k, k);
	glVertex3f(k, -k, -k);
	glEnd();  // End of drawing color-cube

	angleCube -= 0.15f;
}

void ofApp::buttonPressed() 
{
	//++j;
	spheres.emplace_back(50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
