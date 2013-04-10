#pragma once

#include "ofMain.h"

#include "ofxRectangleUtils.h"
#include "ofxRectangle.h"

class ofApp : public ofBaseApp{

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
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
    
    
};
