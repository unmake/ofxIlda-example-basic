#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 700,500, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
    ofSetWindowTitle("UNMAKE Laser Tennis ;-)");
	ofRunApp( new testApp());

}


// ToDo
/*
Make method for correcting scaling
 - look into correcting scaling from off angles
Make better ball path guidance with movement in collisions
Better ball collision detection. Make check for bounding box
Clean code + test area and test method
*/
