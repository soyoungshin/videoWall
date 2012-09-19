#include "testApp.h"

// a doc of gstutils http://ofxfenster.undef.ch/doc/classofGstVideoUtils.html

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	compositionHandler.setup(PORT);
	fbo.allocate(ofGetWidth(), ofGetHeight());
	//bezel.setup(40.0f, 36.0f);
	bezel.setup(0.0f, 0.0f, 3, 2);
}

//--------------------------------------------------------------
void testApp::update(){
	compositionHandler.update();

	//for future reference, these are the filepaths
	/*
		fileNames.push_back("data/varied-codecs/720/h264/1/qt_h264_20sec_720.mov");
		fileNames.push_back("data/varied-codecs/720/h264/2/qt_h264_20sec_720.mov");
		fileNames.push_back("data/varied-codecs/720/h264/3/qt_h264_20sec_720.mov");
		fileNames.push_back("data/varied-codecs/720/h264/4/qt_h264_20sec_720.mov");
		fileNames.push_back("data/varied-codecs/720/h264/5/qt_h264_20sec_720.mov");
		fileNames.push_back("data/varied-codecs/720/h264/6/qt_h264_20sec_720.mov");

		
		//		fileNames.push_back("data/varied-codecs/1080/h264/1/qt_h264.mov");
		//fileNames.push_back("data/varied-codecs/1080/h264/2/qt_h264.mov");
		//fileNames.push_back("data/varied-codecs/1080/h264/3/qt_h264.mov");
		//fileNames.push_back("data/varied-codecs/1080/h264/4/qt_h264.mov");
		//fileNames.push_back("data/varied-codecs/1080/h264/5/qt_h264.mov");
		//fileNames.push_back("data/varied-codecs/1080/h264/6/qt_h264.mov");
		*/

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0,0,0);
	compositionHandler.drawToFbo(&fbo);
	bezel.draw(&fbo);
	compositionHandler.drawSubtitles();

	// draw some debug info
	ofEnableAlphaBlending();
	ofSetColor(0,0,0,128);
	ofRect(0,0,100,30);
	ofDisableAlphaBlending();

	ofSetHexColor(0xffffff);
	string toDraw = ofToString(ofGetFrameRate());
	ofDrawBitmapString(toDraw, 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	// some code for bezel adjustment.
	// TODO: incorporate this in to a control panel gui.
	switch(key) {
		case OF_KEY_UP:
			bezel.setColumnSpacer(bezel.getColumnSpacer() + 1);
			break;
		case OF_KEY_DOWN:
			bezel.setColumnSpacer(bezel.getColumnSpacer() - 1);
			break;
		case OF_KEY_LEFT:
			bezel.setRowSpacer(bezel.getRowSpacer() + 1);
			break;
		case OF_KEY_RIGHT:
			bezel.setRowSpacer(bezel.getRowSpacer() - 1);
			break;
		case OF_KEY_RETURN:
			bezel.setDisplayHelper(!bezel.getDisplayHelper());
			break;
		case ' ':
			// this was more of a test case anyways.
			//			(*players.begin())->setPaused((*players.begin())->getGstVideoUtils()->isPaused());
		default:
			break;
	}	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}