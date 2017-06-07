//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofMain.h"
#include "ofxRectangleUtils.h"


class ColoredRectangle
{
public:
	ofRectangle rect;
	ofColor color;
};


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

	void keyPressed(int key) override;

	void reCreateRects();
	void packAll(float padding);

    std::vector<ofFbo> fbos;
	std::vector<ColoredRectangle> rectangles;
	std::vector<std::vector<ColoredRectangle>> rectsPerFbo;

	int padding = 0;

    int numRects = 500;
    int fboSize = 256;

};
