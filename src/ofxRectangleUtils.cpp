// =============================================================================
//
// Copyright (c) 2009-2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================

#include "ofxRectangleUtils.h"

bool sortByX(         ofRectangle* r0, ofRectangle* r1) { return (r0->getX() < r1->getX()); }
bool sortByY(         ofRectangle* r0, ofRectangle* r1) { return (r0->getY() < r1->getY()); }
bool sortByLeft(      ofRectangle* r0, ofRectangle* r1) { return (r0->getMinX() < r1->getMinX()); }
bool sortByTop(       ofRectangle* r0, ofRectangle* r1) { return (r0->getMinY() < r1->getMinY()); }
bool sortByRight(     ofRectangle* r0, ofRectangle* r1) { return (r0->getMaxX() < r1->getMaxX()); }
bool sortByBottom(    ofRectangle* r0, ofRectangle* r1) { return (r0->getMaxY() < r1->getMaxY()); }
bool sortByHorzCenter(ofRectangle* r0, ofRectangle* r1) { return (r0->getCenter().x > r1->getCenter().x); }
bool sortByVertCenter(ofRectangle* r0, ofRectangle* r1) { return (r0->getCenter().y < r1->getCenter().y); }
bool sortByWidth(     ofRectangle* r0, ofRectangle* r1) { return (r0->getWidth()  < r1->getWidth() ); }
bool sortByHeight(    ofRectangle* r0, ofRectangle* r1) { return (r0->getHeight() < r1->getHeight()); }
bool sortByAbsWidth(  ofRectangle* r0, ofRectangle* r1) { return (fabs(r0->getWidth())  < fabs(r1->getWidth()) ); }
bool sortByAbsHeight( ofRectangle* r0, ofRectangle* r1) { return (fabs(r0->getHeight()) < fabs(r1->getHeight())); }
bool sortByArea(      ofRectangle* r0, ofRectangle* r1) { return (r0->getArea()) < (r1->getArea()); }
bool sortByPerimeter( ofRectangle* r0, ofRectangle* r1) { return (r0->getPerimeter() < r1->getPerimeter()); }

//------------------------------------------------------------------------------
void ofCanonicalize(vector<ofRectangle*>& rects) {
    for(size_t i = 0; i < rects.size(); i++) {
        rects[i]->standardize();
    }
}

//------------------------------------------------------------------------------
void ofSortByHorzAnchor(vector<ofRectangle*>& rects,
                        const ofAlignHorz& horzAnchor) {
    
    switch(horzAnchor) {
        case OF_ALIGN_HORZ_IGNORE:
            ofLogVerbose("ofSortByHorzAnchor") << "horzAnchor = OF_ALIGN_HORZ_IGNORE.  Skipping sort.";
            break;
        case OF_ALIGN_HORZ_LEFT:
            ofSortByLeft(rects);
            break;
        case OF_ALIGN_HORZ_RIGHT:
            ofSortByRight(rects);
            break;
        case OF_ALIGN_HORZ_CENTER:
            ofSortByHorzCenter(rects);
            break;
        default:
            ofLogError("ofSortByHorzAnchor") << "Unknown ofAlignHorz value.";
    }
}

//------------------------------------------------------------------------------
void ofSortByVertAnchor(vector<ofRectangle*>& rects,
                        const ofAlignVert& vertAnchor) {

    switch(vertAnchor) {
        case OF_ALIGN_VERT_IGNORE:
            ofLogVerbose("ofSortByHorzAnchor") << "horzAnchor = OF_ALIGN_HORZ_IGNORE.  Skipping sort.";
            break;
        case OF_ALIGN_VERT_TOP:
            ofSortByTop(rects);
            break;
        case OF_ALIGN_VERT_BOTTOM:
            ofSortByBottom(rects);
            break;
        case OF_ALIGN_VERT_CENTER:
            ofSortByVertCenter(rects);
            break;
        default:
            ofLogError("ofSortByVertAnchor") << "Unknown ofAlignVert value.";
    }
}


//------------------------------------------------------------------------------
void ofSortByX(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByX);
}

//------------------------------------------------------------------------------
void ofSortByY(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByY);
}

//------------------------------------------------------------------------------
void ofSortByLeft(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByLeft);
}

//------------------------------------------------------------------------------
void ofSortByTop(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByTop);
}

//------------------------------------------------------------------------------
void ofSortByRight(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByRight);
}

//------------------------------------------------------------------------------
void ofSortByBottom(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByBottom);
}

//------------------------------------------------------------------------------
void ofSortByHorzCenter(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByHorzCenter);
}

//------------------------------------------------------------------------------
void ofSortByVertCenter(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByVertCenter);
}

//------------------------------------------------------------------------------
void ofSortByWidth(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByWidth);
}

//------------------------------------------------------------------------------
void ofSortByHeight(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByHeight);
}

//------------------------------------------------------------------------------
void ofSortByAbsWidth(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByAbsWidth);
}

//------------------------------------------------------------------------------
void ofSortByAbsHeight(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByAbsHeight);
}

//------------------------------------------------------------------------------
void ofSortByArea(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByArea);
}

//------------------------------------------------------------------------------
void ofSortByPerimeter(vector<ofRectangle*>& rects) {
    sort(rects.begin(), rects.end(), sortByPerimeter);
}

//------------------------------------------------------------------------------
ofRectangle ofGetBoundingBox(vector<ofRectangle*>& rects) {
    ofRectangle result;
    
    for(size_t i = 0; i < rects.size(); i++) {
        if(i == 0) {
            result.set(*rects[i]);
        } else {
            result.growToInclude(*rects[i]);
        }
    }
    
    return result;
}


//------------------------------------------------------------------------------
void ofAlign(vector<ofRectangle*>& rects,
             const ofAlignHorz& horzAnchor,
             const ofAlignVert& vertAnchor) {
    
    ofAlignHorizontal(rects, horzAnchor);
    ofAlignVertical(rects,vertAnchor);
}

//------------------------------------------------------------------------------
void ofAlignHorizontal(vector<ofRectangle*>& rects,
                       const ofAlignHorz& horzAnchor) {

    if(horzAnchor != OF_ALIGN_HORZ_IGNORE) {
        float xAlign = 0.0f;
        ofSortByHorzAnchor(rects, horzAnchor);
        for(size_t i = 0; i < rects.size(); i++) {
            if(i == 0) {
                xAlign = rects[i]->getHorzAnchor(horzAnchor);
            } else {
                rects[i]->translateX(xAlign - rects[i]->getHorzAnchor(horzAnchor));
            }
        }
    } else {
        ofLogVerbose("ofAlignHorizontal") << "OF_ALIGN_HORZ_IGNORE align requested, ignoring.";
    }

}

//------------------------------------------------------------------------------
void ofAlignVertical(vector<ofRectangle*>& rects,
                     const ofAlignVert& vertAnchor) {
    
    if(vertAnchor != OF_ALIGN_VERT_IGNORE) {
        float yAlign = 0.0f;
        ofSortByVertAnchor(rects, vertAnchor);
        for(size_t i = 0; i < rects.size(); i++) {
            if(i == 0) {
                yAlign = rects[i]->getVertAnchor(vertAnchor);
            } else {
                rects[i]->translateY(yAlign - rects[i]->getVertAnchor(vertAnchor));
            }
        }
    } else {
        ofLogVerbose("ofAlignVertical") << "OF_ALIGN_VERT_IGNORE align requested, ignoring.";
    }
    
}

void ofDistributeHorizontal(vector<ofRectangle*>& rects,
                            const ofRectangle& boundingRect,
                            const ofAlignHorz& horzAnchor) {

    if(rects.size() >= 3 && horzAnchor != OF_ALIGN_HORZ_IGNORE) {
        ofSortByHorzAnchor(rects,horzAnchor);
        float nPos = rects.size() - 1;

        // adjust to bounding bounding rect.  if bounding rect is based on the group, nothing will change
        rects[0]->translateX(boundingRect.getLeft() - rects[0]->getLeft());
        rects[nPos]->translateX(boundingRect.getRight() - rects[nPos]->getRight());
        
        float leftX   = rects[0]->getHorzAnchor(horzAnchor);
        float rightX  = rects[nPos]->getHorzAnchor(horzAnchor);
        
        float span = ( rightX - leftX ) / ( nPos );
        for(size_t i = 1; i < nPos; i++) {
            rects[i]->translateX((leftX - rects[i]->getHorzAnchor(horzAnchor)) + i * span);
        }
        
    } else {
        if(horzAnchor == OF_ALIGN_HORZ_IGNORE) {
            ofLogVerbose("ofDistributeHorizontal") << "OF_ALIGN_HORZ_IGNORE distribute requested, ignoring.";
        } else {
            ofLogWarning("ofDistributeHorizontal") << "Not enough rectangles to distribute.";
        }
    }
}

//------------------------------------------------------------------------------
void ofDistributeHorizontal(vector<ofRectangle*>& rects,
                            const ofAlignHorz& horzAnchor) {
    
    ofDistributeHorizontal(rects,
                           ofGetBoundingBox(rects),
                           horzAnchor);

}

//------------------------------------------------------------------------------
void ofDistributeVertical(vector<ofRectangle*>& rects,
                          const ofRectangle& boundingRect,
                          const ofAlignVert& vertAnchor) {

    if(rects.size() >= 3 && vertAnchor != OF_ALIGN_VERT_IGNORE) {
        ofSortByVertAnchor(rects,vertAnchor);
        float nPos    = rects.size() - 1;

        // adjust to bounding bounding rect.  if bounding rect is based on the group, nothing will change
        rects[0]->translateY(boundingRect.getTop() - rects[0]->getTop());
        rects[nPos]->translateY(boundingRect.getBottom() - rects[nPos]->getBottom());
        
        float topY    = rects[0]->getVertAnchor(vertAnchor);
        float bottomY = rects[nPos]->getVertAnchor(vertAnchor);
        float span = ( bottomY - topY ) / ( nPos );
        for(size_t i = 1; i < nPos; i++) {
            rects[i]->translateY((topY - rects[i]->getVertAnchor(vertAnchor)) + i * span);
        }
    } else {
        if(vertAnchor == OF_ALIGN_VERT_IGNORE) {
            ofLogVerbose("ofDistributeVertical") << "OF_ALIGN_VERT_IGNORE distribute requested, ignoring.";
        } else {
            ofLogWarning("ofDistributeVertical") << "Not enough rectangles to distribute.";
        }
    }
}

//------------------------------------------------------------------------------
void ofDistributeVertical(vector<ofRectangle*>& rects,
                          const ofAlignVert& vertAnchor) {
   
    ofDistributeVertical(rects,
                         ofGetBoundingBox(rects),
                         vertAnchor);
}

//------------------------------------------------------------------------------
void ofDistribute(vector<ofRectangle*>& rects,
                  const ofRectangle& boundingRect,
                  const ofAlignHorz& horzAnchor,
                  const ofAlignVert& vertAnchor) {
    
    ofDistributeHorizontal(rects,
                           boundingRect,
                           horzAnchor);
    ofDistributeVertical(rects,
                         boundingRect,
                         vertAnchor);
}
//------------------------------------------------------------------------------
void ofDistribute(vector<ofRectangle*>& rects,
                  const ofAlignHorz& horzAnchor,
                  const ofAlignVert& vertAnchor) {
    
    ofRectangle boundingRect = ofGetBoundingBox(rects);

    ofDistribute(rects,
                 boundingRect,
                 horzAnchor,
                 vertAnchor);
}

//------------------------------------------------------------------------------
void ofCascade(vector<ofRectangle*>& rects,
               const ofRectangle& boundingRect,
               const ofPoint& offset) {
    
    ofRectangle bb = boundingRect.getStandardized();
    
    ofPoint currentPosition = bb.getTopLeft();
    
    int currentRow = 0;
    int currentColumn = 0;
    
    for(size_t i = 0; i < rects.size(); i++) {
        ofRectangle* r = rects[i]; // get the pointer
        
        r->standardize();
        
        if((currentPosition.y + r->height) > (bb.getBottom())) {
            // new row, new column
            currentColumn++;
            currentPosition.x = currentColumn * offset.x + bb.x;
            currentRow = 0;
            currentPosition.y = bb.y;
        }
        
        r->setPosition(currentPosition);
        currentPosition += offset;
    }
    
}


//------------------------------------------------------------------------------
void ofStackHorzizontal(vector<ofRectangle*>& rects, float startX) {
    for(size_t i = 0; i < rects.size(); i++) {
        rects[i]->standardize(); // make sure
        if(i == 0) {
            rects[i]->setX(startX);
        } else {
            rects[i]->setX(rects[i-1]->getRight());
        }
    }    
}

//------------------------------------------------------------------------------
void ofStackVertical(vector<ofRectangle*>& rects, float startY) {
    for(size_t i = 0; i < rects.size(); i++) {
        rects[i]->standardize(); // make sure
        if(i == 0) {
            rects[i]->setY(startY);
        } else {
            rects[i]->setY(rects[i-1]->getBottom());
        }
    }
}


bool ofPack(vector<ofRectangle*>& rects,
            const ofRectangle& boundingRect) {

//    ofxMaxRectsBinPack packer(boundingRect.width,
//                              boundingRect.height);
//    
//    vector<ofRectangle*> original = rects;
//    rects.clear();
//    
//    packer.Insert(rects, rects, ofxMaxRectsBinPack::RectBestShortSideFit);
//    
    return true;
}

//// like distribute, but doesn't rely on the max and min places to fit
//void ofxMuiRectUtils::stack(vector<ofRectangle*>& rects, 
//                            ofxMuiAlign selfAlign,
//                            ofxMuiAlign hGroupAlign, 
//                            ofxMuiAlign vGroupAlign,
//                            float spacing,
//                            ofPoint anchor,
//                            bool reverseStackOrder) {
//
//    ofRectangle bb = ofRectangle(anchor,0,0);
//
//    bool isSelfAlignHorizontal = !isHorizontalAlignment(selfAlign); // opposite
//    
//    // self align the rects
//    ofxMuiRectUtils::align(rects,selfAlign,ALIGN_LEFT,ALIGN_TO_BOUNDING_BOX,bb);
//
//    int numElements = rects.size() - 1;
//    float currentPos = 0;
//    float totalSpan = 0;
//    float increment = 0;
//    
//    if(isSelfAlignHorizontal) {
//        currentPos = anchor.x;
//    } else {
//        currentPos = anchor.y;
//    }
//    
//    // make a local copy that is ordered in reverse
//    vector<ofRectangle*> selected = rects;
//    if(reverseStackOrder) {
//        reverse(selected.begin(), selected.end());
//    }
//    
//    for(vector<ofRectangle*>::iterator it = selected.begin(); it != selected.end(); ++it) {
//        ofRectangle* r = (*it); // get the pointer
//        
//        if(isSelfAlignHorizontal) {
//            r->x = currentPos;
//            increment = r->width + spacing;
//            currentPos += increment;
//        } else {
//            r->y = currentPos;
//            increment = r->height + spacing;
//            currentPos += increment;                
//        }
//    }
//
//    // now do group alignment
//    ofRectangle groupBox;
//    getBoundingBox(selected, groupBox);
//    
//    // do final vert and horz group adjustments and short circuit if needed
//        for(vector<ofRectangle*>::iterator it = selected.begin(); it != selected.end(); ++it) {
//            ofRectangle* r = (*it); // get the pointer
//
//            // move everything to a common
//            // vAlign TOP, hAlign LEFT situation
//            if(selfAlign == ALIGN_BOTTOM) {
//                r->y += groupBox.height;
//            } else if(selfAlign == ALIGN_RIGHT) {
//                r->x += groupBox.width;
//            } else if(selfAlign == ALIGN_CENTER_X) {
//                r->x += groupBox.width / 2.0f;
//            } else if(selfAlign == ALIGN_CENTER_Y) {
//                r->y += groupBox.height / 2.0f;
//            }
//            
//            // now make group corrections
//            if(hGroupAlign == ALIGN_RIGHT) {
//                r->x -= groupBox.width;
//            } else if(hGroupAlign == ALIGN_CENTER_X) {
//                r->x -= groupBox.width / 2.0f;
//            }
//            
//            if(vGroupAlign == ALIGN_TOP) {
//                r->y -= groupBox.height;
//            } else if(vGroupAlign == ALIGN_CENTER_Y) {
//                r->y -= groupBox.height / 2.0f;
//            }
//        }
//}
//
//
////------------------------------------------------------------------------------
//void ofxMuiRectUtils::wrap(vector<ofRectangle*>& rects, 
//                           ofRectangle& boundingBox,
//                           float horizontalSpace,
//                           float verticalSpace,
//                           ofxMuiAlign hAlign,
//                           ofxMuiAlign vLineAlign,
//                           float lineHeight) {
//    
//    // a grid of rects.  each inner rect group represents a "line"
//    vector< vector<ofRectangle*> > rows;
//    vector<ofRectangle*>* currentLineRef;
//
//    bool firstTime = true;
//    float currentX = 0;
//    float currentY = 0;
//    
//    // first pass is to go through and make lines of the appropriate length
//    for(vector<ofRectangle*>::iterator it = rects.begin(); it != rects.end(); ++it) {
//        ofRectangle* r = (*it); // get the pointer
//        
//        if(firstTime || (currentX + r->width) > boundingBox.width) {
//            if(firstTime) {
//                firstTime = false;
//            } else {
//                cout << "\tNUM COLS=" << currentLineRef->size() << endl;
//            }
//            
//
//            
//            vector<ofRectangle*> newLine;
//            rows.push_back(newLine);
//            currentLineRef = &newLine;
//            
//        }
//        
//        currentLineRef->push_back(r);
//        currentX += (r->width + horizontalSpace);
//    }
//    
//    
//    cout << "NUM ROWS=" << rows.size() << endl;
//    
//    // second pass horizontal alignment
//    
//    
//    // third pass vertical alignment
//    
//    
//}
///*
////------------------------------------------------------------------------------
//void ofxMuiRectUtils::tile(vector<ofRectangle*>& rects, ofRectangle& boundingBox) {
//}
// */
