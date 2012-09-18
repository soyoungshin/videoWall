#include "testApp.h"

// a doc of gstutils http://ofxfenster.undef.ch/doc/classofGstVideoUtils.html

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	compositionHandler.setup(PORT);
	fbo.allocate(ofGetWidth(), ofGetHeight());
	//bezel.setup(40.0f, 36.0f);
	bezel.setup(20.0f, 20.0f, 3, 2);

    players[0].loadMovie("big_buck_bunny_720p_h264.mov");
    players[1].loadMovie("big_buck_bunny_720p_h264 (3rd copy).mov");
    players[2].loadMovie("big_buck_bunny_720p_h264 (another copy).mov");
    players[3].loadMovie("big_buck_bunny_720p_h264 (copy).mov");
    players[4].loadMovie("big_buck_bunny_720p_h264 (4th copy).mov");
    players[5].loadMovie("big_buck_bunny_720p_h264 (5th copy).mov");



	for(int i= 0; i < 6; i++) {
	    players[i].setPosition(rand() % 100 / 100.0);
        players[i].play();
        players[i].setLoopState(OF_LOOP_NORMAL);
	}
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
	for(int i= 0; i < 6; i++) {
        players[i].idleMovie();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0,0,0);

	// for debugging
	fbo.begin();
	ofClear(0,0,0,0);

	int width = ofGetWidth();
	int height = ofGetHeight();

	for(int i= 0; i < 6; i++) {
        players[i].draw(i*300, i*300, width/2, height/2);
	}

	fbo.end();

	bezel.draw(&fbo);
	//fbo.draw(0,0);
	compositionHandler.drawSubtitles();

    // added for debugging



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
		//case OF_KEY_RETURN:
		case '1':
			bezel.setDisplayHelper(!bezel.getDisplayHelper());
			break;
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
