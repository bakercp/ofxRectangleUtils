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
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
		
    std::vector<ofxRectangle>  rectangles;
    std::vector<ofRectangle*>  selectedRects;
    ofxRectangle selectedRectsBoundingBox;

    ofxRectangle* draggingRectPtr;
    
    glm::vec2 dragStart;

    bool isSelecting;
    ofRectangle selectionRect;
    
    ofAlignHorz hAlign;
    ofAlignVert vAlign;
    
    ofRectangle* anchorRect;
    
    string keyboardCommands;
    bool showKeyboardCommands;


//    ofRotatedRectangle rotatedRect;
    std::vector<ofRectangle>  packedRects;

//    ofRectanglePacker packer;
};
