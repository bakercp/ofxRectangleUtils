//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofxRectangleUtils.h"
#include "ofxRectangle.h"
//#include "ofRotatedRectangle.h"
//#include "ofRectanglePacker.h"

using namespace ofx;


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
		
    vector<ofxRectangle>  rectangles;
    vector<ofRectangle*>  selectedRects;
    ofxRectangle          selectedRectsBoundingBox;

    ofxRectangle* draggingRectPtr;
    
    ofPoint dragStart;

    bool isSelecting;
    ofRectangle selectionRect;
    
    ofAlignHorz hAlign;
    ofAlignVert vAlign;
    
    ofRectangle* anchorRect;
    
    string keyboardCommands;
    bool   showKeyboardCommands;


//    ofRotatedRectangle rotatedRect;
    std::vector<ofRectangle>  packedRects;

//    ofRectanglePacker packer;
};
