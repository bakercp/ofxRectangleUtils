#include "ofApp.h"

int numRects = 500;
int fboSize = 256;


void ofApp::setup(){

	ofEnableAlphaBlending();
	reCreateRects();
}


void ofApp::reCreateRects(){

	rectangles.clear();

	// create a random set of rectangles to play with
	for(int i = 0; i < numRects; ++i){
		float w = std::floor(ofRandom(20, 40));
		float h = std::floor(ofRandom(20, 40));

		ColoredRectangle r;
		r.rect = ofRectangle(0,0,w,h);
		r.color = ofColor(ofRandom(32,255), ofRandom(32,255), ofRandom(32,255));

		rectangles.push_back(r);
	}
}


void ofApp::packAll(float padding){

	fbos.clear();
	rectsPerFbo.clear();

	//demo packing
	ofRectangle bounds = ofRectangle(0,0, fboSize, fboSize);
	packer = new ofRectanglePacker(bounds, padding);
	rectsPerFbo.resize(1); //add the 1st one

	for (int i = 0 ; i < rectangles.size(); i++) {

		bool didFit = packer->pack(rectangles[i].rect);

		if (!didFit){ //make a new FBO

			//ofLog() << "did pack until rect " << i - 1 << "; lets make a new fbo to fit the remaining";

			//start a new fbo to hold the next rects
			vector<ColoredRectangle> emptyV;
			rectsPerFbo.push_back(emptyV);

			//make new packer
			delete packer;
			packer = new ofRectanglePacker(bounds, padding);

			i--; //dont forget to retry the one that didnt fit

		}else{

			rectsPerFbo[rectsPerFbo.size() - 1].push_back(rectangles[i]);
		}
	}

	delete packer;
	packer = NULL;

	int c = 0;
	for(int i = 0; i < rectsPerFbo.size(); i++){
		ofFbo fbo;
		fbo.allocate(fboSize, fboSize, GL_RGBA);
		fbo.begin();
		ofClear(22,255);
		for (size_t j = 0; j < rectsPerFbo[i].size(); ++j){
			ColoredRectangle & rect = rectsPerFbo[i][j];
			ofNoFill();
			ofSetColor(rect.color);
			ofDrawRectangle(rect.rect);
			ofFill();
			ofSetColor(rect.color, 64);
			ofDrawRectangle(rect.rect);
			ofSetColor(rect.color);
			ofDrawBitmapString(ofToString(c), rect.rect.x , rect.rect.y + 10);
			c++;
		}
		fbo.end();
		fbos.push_back(fbo);
	}
}


void ofApp::update(){
	padding = ofClamp(ofGetMouseX() * 0.02, 0, 100);
	float t = ofGetElapsedTimef();
	packAll(padding);
	t = ofGetElapsedTimef() - t;
	ofSetWindowTitle(ofToString(ofGetFrameRate(),1) + " packing: " + ofToString(t,3) + " sec");
}


void ofApp::draw(){

    ofBackground(0);
	ofSetColor(255);

	int space = 2;
	int y = space;
	int x = 0;
	for(int i = 0; i < fbos.size(); i++){
		fbos[i].draw(x, y);
		x += (fboSize + space);
		if ( x > ofGetWidth() - fboSize){
			x = space;
			y += fboSize + space;
		}
	}

	ofDrawBitmapString("num FBOs: " + ofToString(fbos.size()) +
					   "\nPadding: " + ofToString(padding, 1) +
					   "\nnumRects: " + ofToString(numRects, 1)
					   ,20, ofGetHeight() - 50);

}


void ofApp::keyPressed(int key){
	reCreateRects();
};

