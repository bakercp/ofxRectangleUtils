#include "ofApp.h"


void ofApp::setup()
{
    
    ofSetFrameRate(30);
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    isSelecting     = false;
    draggingRectPtr = NULL;

    // create a random set of rectangles to play with
    for(int i = 0; i < 40; ++i)
    {
        // random coordinates
        float w = std::floor(ofRandom(5,100));
        float h = std::floor(ofRandom(75,100));
        float x = std::floor(ofRandom(0, ofGetWidth()  - w));
        float y = std::floor(ofRandom(0, ofGetHeight() - h));
        
        ofxRectangle rect(ofRectangle(x,y,w,h),
                          ofColor(std::floor(ofRandom(100,255)),
                                  std::floor(ofRandom(100,255)),
                                  std::floor(ofRandom(100,255))));
                          
        // add the random rectangle
        rectangles.push_back(rect);
    }
    
    selectedRectsBoundingBox = ofxRectangle(ofRectangle(),
                                            ofColor(127,80));
    
    hAlign = OF_ALIGN_HORZ_LEFT;
    vAlign = OF_ALIGN_VERT_TOP;
    
    anchorRect = NULL;
    
    stringstream ss;
    
    ss << "Keyboard [(Spacebar) to hide]" << endl;
    ss << "W: sort by absolute width" << endl;
    ss << "A: sort by area" << endl;
    ss << "H: sort by absolute height" << endl;
    ss << "c: cascade" << endl;
    ss << "v: align vertical with current vAlign" << endl;
    ss << "h: align horizontal with current hAlign" << endl;
    ss << "x: distribute horizontal with current hAlign" << endl;
    ss << "h: distribute vertical with current vAlign" << endl;
    ss << "p: pack rectangles" << endl;

    keyboardCommands = ss.str();
    
    showKeyboardCommands = false;

}


void ofApp::update()
{
    ofPoint mouse(ofGetMouseX(),ofGetMouseY());

    
    bool foundIsOver = false;
    bool hasFirstSelection = false;

    if (draggingRectPtr == NULL) {
        selectedRects.clear();
    }
    
    for(size_t i = 0; i < rectangles.size(); ++i)
    {
        
        // if we are selecting, re-evaluate this each time
        if (isSelecting)
        {
            rectangles[i].isSelected = rectangles[i].intersects(selectionRect);
        }
        
        // grow the slection box
        if (rectangles[i].isSelected)
        {
            
            if (draggingRectPtr == NULL)
            {
            
                if (!hasFirstSelection)
                {
                    selectedRectsBoundingBox = rectangles[i];
                    hasFirstSelection = true;
                }
                else
                {
                    selectedRectsBoundingBox.growToInclude(rectangles[i]);
                }
                
                selectedRects.push_back(&rectangles[i]);
                hasFirstSelection = true;
            }
        }
        
        // check is over -- only set isOver if other things aren't happening
        if (!foundIsOver &&
           /*selectedRects.empty() &&
           !rectangles[i].isSelected && */
           (draggingRectPtr == NULL ||
            draggingRectPtr == &rectangles[i] ||
            draggingRectPtr == &selectedRectsBoundingBox) &&
           rectangles[i].inside(mouse))
           {
            rectangles[i].isOver = true;
            foundIsOver = true;
        }
        else
        {
            rectangles[i].isOver = false;
        }
    }

    
    if (isSelecting)
    {
        selectionRect.set(dragStart,mouse);
    }

}


void ofApp::draw(){

    ofBackground(0);

    ofPoint mouse(ofGetMouseX(),ofGetMouseY());

    ofFill();
    ofSetColor(255,showKeyboardCommands ? 255 : 127);
    ofDrawBitmapString(showKeyboardCommands ? keyboardCommands : "Press (Spacebar) for help.", 12,16);
    
    // draw all of our rectangles
    for (size_t i = 0; i < rectangles.size(); ++i)
    {
        ofRectangle* rect = (ofRectangle*)&rectangles[i];

        unsigned int selectionIndex = ofFind(selectedRects, rect);

        rectangles[i].draw(i,selectionIndex == selectedRects.size() ? -1 : selectionIndex);
    }

    // draw our bounding box rectangle
    if (!isSelecting && !selectedRects.empty())
    {
        ofFill();
        ofSetColor(255,20);
        ofRect(selectedRectsBoundingBox);
        ofNoFill();
        ofSetColor(255,80);
        ofRect(selectedRectsBoundingBox);
    }
    
    // draw our selection raectangle
    if (isSelecting)
    {
        ofNoFill();
        ofSetColor(255,255,0,200);
        ofRect(selectionRect);
    }

    
    string hAlignString = "";
    switch (hAlign)
    {
        case OF_ALIGN_HORZ_LEFT:
            hAlignString = "OF_ALIGN_HORZ_LEFT";
            break;
        case OF_ALIGN_HORZ_CENTER:
            hAlignString = "OF_ALIGN_HORZ_CENTER";
            break;
        case OF_ALIGN_HORZ_RIGHT:
            hAlignString = "OF_ALIGN_HORZ_RIGHT";
            break;
        case OF_ALIGN_HORZ_IGNORE:
            hAlignString = "OF_ALIGN_HORZ_IGNORE";
            break;
        default:
            hAlignString = "??";
            break;
    }
    
    string vAlignString = "";
    switch (vAlign) {
        case OF_ALIGN_VERT_TOP:
            vAlignString = "OF_ALIGN_VERT_TOP";
            break;
        case OF_ALIGN_VERT_CENTER:
            vAlignString = "OF_ALIGN_VERT_CENTER";
            break;
        case OF_ALIGN_VERT_BOTTOM:
            vAlignString = "OF_ALIGN_VERT_BOTTOM";
            break;
        case OF_ALIGN_VERT_IGNORE:
            vAlignString = "OF_ALIGN_VERT_IGNORE";
            break;
        default:
            vAlignString = "??";
            break;
    }    
    
    ofFill();
    ofSetColor(255);
    ofDrawBitmapString("Press (a) to toggle selection hAlign : " + hAlignString, 10, ofGetHeight() - 24);
    ofDrawBitmapString("Press (A) to toggle selection vAlign : " + vAlignString, 10, ofGetHeight() - 10);


    ofNoFill();
    ofSetColor(255,255,0);

    for(int i = 0; i < packedRects.size(); i++)
    {
        ofRect(packedRects[i]);
    }
}


void ofApp::keyPressed(int key)
{
//    if (key == OF_KEY_UP) {
//        for(size_t i = 0; i < selectedRects.size(); i++) {
//            selectedRects[i]->vAlign = OF_ALIGN_VERT_TOP;
//        }
//    } else if (key == OF_KEY_DOWN) {
//        for(size_t i = 0; i < selectedRects.size(); i++) {
//            selectedRects[i]->vAlign = OF_ALIGN_VERT_BOTTOM;
//        }
//    } else if (key == OF_KEY_LEFT) {
//        for(size_t i = 0; i < selectedRects.size(); i++) {
//            selectedRects[i]->hAlign = OF_ALIGN_HORZ_LEFT;
//        }
//    } else if (key == OF_KEY_RIGHT) {
//        for(size_t i = 0; i < selectedRects.size(); i++) {
//            selectedRects[i]->hAlign = OF_ALIGN_HORZ_RIGHT;
//        }
//    } else if (key == 'c') {
//        for(size_t i = 0; i < selectedRects.size(); i++) {
//            selectedRects[i]->hAlign = OF_ALIGN_HORZ_CENTER;
//        }
//    } else if (key == 'C') {
//        for(size_t i = 0; i < selectedRects.size(); i++) {
//            selectedRects[i]->vAlign = OF_ALIGN_VERT_CENTER;
//        }
//    } else if (key == 'i') {
//        for(size_t i = 0; i < selectedRects.size(); i++) {
//            selectedRects[i]->hAlign = OF_ALIGN_HORZ_IGNORE;
//        }
//    } else if (key == 'I') {
//        for(size_t i = 0; i < selectedRects.size(); i++) {
//            selectedRects[i]->vAlign = OF_ALIGN_VERT_IGNORE;
//        }
//        
    /*} else */ if (key == 'a') {
        if (hAlign == OF_ALIGN_HORZ_LEFT) {
            hAlign = OF_ALIGN_HORZ_CENTER;
        } else if (hAlign == OF_ALIGN_HORZ_CENTER) {
            hAlign = OF_ALIGN_HORZ_RIGHT;
        } else if (hAlign == OF_ALIGN_HORZ_RIGHT) {
            hAlign = OF_ALIGN_HORZ_IGNORE;
        } else if (hAlign == OF_ALIGN_HORZ_IGNORE) {
            hAlign = OF_ALIGN_HORZ_LEFT;
        }
    } else if (key == 'A') {
        if (vAlign == OF_ALIGN_VERT_TOP) {
            vAlign = OF_ALIGN_VERT_CENTER;
        } else if (vAlign == OF_ALIGN_VERT_CENTER) {
            vAlign = OF_ALIGN_VERT_BOTTOM;
        } else if (vAlign == OF_ALIGN_VERT_BOTTOM) {
            vAlign = OF_ALIGN_VERT_IGNORE;
        } else if (vAlign == OF_ALIGN_VERT_IGNORE) {
            vAlign = OF_ALIGN_VERT_TOP;
        }
    } else if (key == 'W') {
        RectangleUtils::sortByAbsWidth(selectedRects);
    } else if (key == 'A') {
        RectangleUtils::sortByArea(selectedRects);
    } else if (key == 'H') {
        RectangleUtils::sortByAbsHeight(selectedRects);
    } else if (key == 'c') {
        RectangleUtils::cascade(selectedRects,ofRectangle(0,0,ofGetWidth(),ofGetHeight()),ofPoint(30,30));
    } else if (key == 'v') {
        RectangleUtils::alignVert(selectedRects,vAlign);
    } else if (key == 'h') {
        // horizontal align selection
        RectangleUtils::alignHorz(selectedRects,hAlign);
    } else if (key == 'x') {
        // distribute in x
        RectangleUtils::distributeHorz(selectedRects,hAlign);
    } else if (key == 'y') {
        RectangleUtils::distributeVert(selectedRects,vAlign);
    } else if (key == 'p') {

//        RectangleUtils::pack(selectedRects,ofRectangle(0,
//                                                       0,
//                                                       ofGetWidth(),
//                                                       ofGetHeight()));
//

    } else if (key == ' ') {
        showKeyboardCommands = !showKeyboardCommands;
    }
}


void ofApp::keyReleased(int key)
{
}


void ofApp::mouseMoved(int x, int y )
{
}


void ofApp::mouseDragged(int x, int y, int button)
{
    if (draggingRectPtr != NULL) {
        draggingRectPtr->setPosition(ofPoint(x,y) - draggingRectPtr->dragOffset);
        
        if (draggingRectPtr == &selectedRectsBoundingBox) {
            for(size_t i = 0; i < rectangles.size(); i++) {
                if (rectangles[i].isSelected) {
                    rectangles[i].setPosition(ofPoint(x,y) - rectangles[i].dragOffset);
                }
            }
        }
        
    }
}


void ofApp::mousePressed(int x, int y, int button)
{
    
    dragStart = ofPoint(x,y);  // set a new drag start point
    
    
    if (!ofGetKeyPressed('A')) {
    
        bool foundAClickTarget = false;

        // first check to see if we are in the bounding box
        if (!selectedRects.empty() &&
           selectedRectsBoundingBox.inside(dragStart)) {
            draggingRectPtr = &selectedRectsBoundingBox;
            selectedRectsBoundingBox.dragOffset = dragStart - selectedRectsBoundingBox.getPosition();
            for(size_t i = 0; i < rectangles.size(); i++) {
                if (rectangles[i].isSelected) {
                    rectangles[i].dragOffset = dragStart - rectangles[i].getPosition();
                }
            }
            foundAClickTarget = true;
        } else {
            selectedRects.clear();
            // otherwise, go through all of the rects and see if we can drag one
            for(size_t i = 0; i < rectangles.size(); i++) {
                rectangles[i].isSelected = false; // assume none
                if (!foundAClickTarget && rectangles[i].isOver) {
                    draggingRectPtr = &rectangles[i];
                    rectangles[i].isSelected = true;
                    rectangles[i].dragOffset = dragStart - rectangles[i].getPosition();
                    foundAClickTarget = true;
                }
            }
        }
        
        isSelecting = !foundAClickTarget; // means our click did not land on an existing rect
    } else {
        if (anchorRect != NULL) {
            delete anchorRect;
            anchorRect = NULL;
        }
        
        anchorRect = new ofRectangle(dragStart,0,0);
    }
        
}


void ofApp::mouseReleased(int x, int y, int button)
{
    draggingRectPtr = NULL;
    isSelecting     = false;
}
