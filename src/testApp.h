#pragma once

#include "ofMain.h"
//#include "hfPosition.h"
#include "ofxGstStandaloneVideoPlayer.h"
#include "ofxBezel.h"
#include "ofxCompositionHandler.h"
#include <time.h>

#define PORT 12345

class testApp : public ofBaseApp {

	public:
		testApp() {};
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofFbo fbo;
		ofxBezel bezel;

		ofxCompositionHandler compositionHandler;

		//VideoPlayerPtr vidPlayer;
		ofVideoPlayer players[6];
};