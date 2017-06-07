//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once

#include "ofMain.h"
#include "ofxRectangleUtils.h"

class ColoredRectangle{
public:
	ofRectangle rect;
	ofColor color;
};


class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

	void keyPressed(int key);
	void keyReleased(int key){};

	void reCreateRects();
	void packAll(float padding);


	ofRectanglePacker *packer;

	vector<ofFbo> fbos;
	vector<ColoredRectangle>  rectangles;
	vector< vector<ColoredRectangle> > rectsPerFbo;

	int padding;
};
