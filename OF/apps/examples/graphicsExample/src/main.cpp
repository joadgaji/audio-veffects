#include "ofMain.h"
#include "pCenter.h"
#include "ofAppGlutWindow.h"
//========================================================================
int main( ){

    ofAppGlutWindow window;
	int wd = 1024;
	ofSetupOpenGL(&window, wd,768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new pCenter(500));
	



}
