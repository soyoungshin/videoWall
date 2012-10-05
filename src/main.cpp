#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;

	// for linux, is in full screen
    //ofSetupOpenGL(&window, 1680 * 2, 1050 * 3, OF_GAME_MODE);

    // for testing on one monitor
	ofSetupOpenGL(&window, 1680, 1050, OF_WINDOW);
    ofSetWindowPosition(0,0);


	// for windows
	//ofSetupOpenGL(&window, 1500, 1500, OF_WINDOW); // <-------- setup the GL context
	//ofSetWindowPosition(50, 200);

	ofRunApp( new testApp());
}
