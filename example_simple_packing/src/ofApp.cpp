//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


void ofApp::setup()
{
	ofEnableAlphaBlending();
	reCreateRects();
}


void ofApp::reCreateRects()
{
	rectangles.clear();

	// Create a random set of rectangles to play with.
    for (int i = 0; i < numRects; ++i)
    {
		float w = std::floor(ofRandom(20, 40));
		float h = std::floor(ofRandom(20, 40));

        rectangles.push_back(ColoredRectangle());
		rectangles.back().rect = ofRectangle(0, 0, w, h);
		rectangles.back().color = ofColor(ofRandom(32, 255),
                                          ofRandom(32, 255),
                                          ofRandom(32, 255));

	}
}


void ofApp::packAll(float padding)
{
	fbos.clear();
	rectsPerFbo.clear();

	//demo packing
	ofRectangle bounds(0, 0, fboSize, fboSize);
	ofRectanglePacker packer(bounds, padding);
	rectsPerFbo.resize(1); //add the 1st one

	for (int i = 0 ; i < rectangles.size(); i++) {

		bool didFit = packer.pack(rectangles[i].rect);

        // Make a new FBO if it didn't fit.
		if (!didFit)
        {
            // Reset the packer.
            packer.reset();

			// Start a new FBO to hold the next rects.
			rectsPerFbo.push_back(std::vector<ColoredRectangle>());

            // Reset counter to make sure last rectangle is packed.
			--i;
		}
        else
        {
			rectsPerFbo.back().push_back(rectangles[i]);
		}
	}

    packer.reset();

	int c = 0;

    for (const auto& rects: rectsPerFbo)
    {
		ofFbo fbo;
		fbo.allocate(fboSize, fboSize, GL_RGBA);
		fbo.begin();
		ofClear(22, 255);

        for (const auto& rect: rects)
        {
			ofNoFill();
			ofSetColor(rect.color);
			ofDrawRectangle(rect.rect);
			ofFill();
			ofSetColor(rect.color, 64);
			ofDrawRectangle(rect.rect);
			ofSetColor(rect.color);
			ofDrawBitmapString(ofToString(c), rect.rect.x , rect.rect.y + 10);
			++c;
		}

		fbo.end();
		fbos.push_back(fbo);
	}
}


void ofApp::update()
{
	padding = ofClamp(ofGetMouseX() * 0.02, 0, 100);
	float t = ofGetElapsedTimef();
    packAll(padding);
    t = ofGetElapsedTimef() - t;
    ofSetWindowTitle(ofToString(ofGetFrameRate(),1) + " packing: " + ofToString(t,3) + " sec");
}


void ofApp::draw()
{
    ofBackground(0);
	ofSetColor(255);

	int space = 2;
	int y = space;
	int x = 0;

    for (const auto& fbo: fbos)
    {
        fbo.draw(x, y);
        x += (fboSize + space);

        if ((x + fboSize) > ofGetWidth())
        {
            x = space;
            y += fboSize + space;
        }
    }

	ofDrawBitmapString("num FBOs: " + ofToString(fbos.size()) +
					   "\nPadding: " + ofToString(padding, 1) +
					   "\nnumRects: " + ofToString(numRects, 1)
					   ,20, ofGetHeight() - 50);

}


void ofApp::keyPressed(int key)
{
	reCreateRects();
}
