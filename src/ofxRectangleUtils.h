//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include <vector>
#include "ofConstants.h"
#include "ofRectangle.h"
#include "ofRectanglePacker.h"
#include "ofVec2f.h"
#include "ofVec3f.h"


namespace ofx {


class RectangleUtils {
public:
    typedef std::vector<ofRectangle*> RectanglePointers;
    typedef std::vector<ofRectangle*>::iterator RectanglePointersIter;

    // comparisons
    static bool compareByX(            ofRectangle* r0, ofRectangle* r1);
    static bool compareByY(            ofRectangle* r0, ofRectangle* r1);
    static bool compareByLeft(         ofRectangle* r0, ofRectangle* r1);
    static bool compareByTop(          ofRectangle* r0, ofRectangle* r1);
    static bool compareByRight(        ofRectangle* r0, ofRectangle* r1);
    static bool compareByBottom(       ofRectangle* r0, ofRectangle* r1);
    static bool compareByHorzCenter(   ofRectangle* r0, ofRectangle* r1);
    static bool compareByVertCenter(   ofRectangle* r0, ofRectangle* r1);
    static bool compareByWidth(        ofRectangle* r0, ofRectangle* r1);
    static bool compareByHeight(       ofRectangle* r0, ofRectangle* r1);
    static bool compareByAbsWidth(     ofRectangle* r0, ofRectangle* r1);
    static bool compareByAbsHeight(    ofRectangle* r0, ofRectangle* r1);
    static bool compareByArea(         ofRectangle* r0, ofRectangle* r1);
    static bool compareByPerimeter(    ofRectangle* r0, ofRectangle* r1);

    // standardization
    static void standardize(RectanglePointers& rects);

//    static bool isInside(const ofRectangle& r0, const ofRectangle& r1);
//    static bool isInside(const ofRectangle& r0, const float& px, const float& py);

    // metrics
    static ofRectangle getBoundingBox(RectanglePointers& rects);


    // sorting
    static void sortByHorzAnchor(RectanglePointers& rects, ofAlignHorz horzAnchor);
    static void sortByVertAnchor(RectanglePointers& rects, ofAlignVert vertAnchor);

    static void sortByX(           RectanglePointers& rects);
    static void sortByY(           RectanglePointers& rects);
    static void sortByLeft(        RectanglePointers& rects);
    static void sortByTop(         RectanglePointers& rects);
    static void sortByRight(       RectanglePointers& rects);
    static void sortByBottom(      RectanglePointers& rects);
    static void sortByHorzCenter(  RectanglePointers& rects);
    static void sortByVertCenter(  RectanglePointers& rects);
    static void sortByWidth(       RectanglePointers& rects);
    static void sortByHeight(      RectanglePointers& rects);
    static void sortByAbsWidth(    RectanglePointers& rects);
    static void sortByAbsHeight(   RectanglePointers& rects);
    static void sortByArea(        RectanglePointers& rects);
    static void sortByPerimeter(   RectanglePointers& rects);



    // alignment

    static void align(RectanglePointers& rects,
                      ofAlignHorz horzAnchor,
                      ofAlignVert vertAnchor);

    static void alignHorz(RectanglePointers& rects,
                          ofAlignHorz horzAnchor);

    static void alignVert(RectanglePointers& rects,
                          ofAlignVert vertAnchor);


    // distribution
    static void distributeHorz(RectanglePointers& rects,
                               const ofRectangle& boundingRect,
                               ofAlignHorz horzAnchor);

    static void distributeHorz(RectanglePointers& rects,
                               ofAlignHorz horzAnchor);

    static void distributeVert(RectanglePointers& rects,
                               const ofRectangle& boundingRect,
                               ofAlignVert vertAnchor);

    static void distributeVert(RectanglePointers& rects,
                               ofAlignVert vertAnchor);

    static void distribute(RectanglePointers& rects,
                           const ofRectangle& boundingRect,
                           ofAlignHorz horzAnchor,
                           ofAlignVert vertAnchor);

    static void distribute(RectanglePointers& rects,
                           ofAlignHorz horzAnchor,
                           ofAlignVert vertAnchor);

    // stacking
    static void stackHorz(RectanglePointers& rects, float offsetX = 0);
    static void stackVert(RectanglePointers& rects, float offsetY = 0);

    // cascading
    static void cascade(RectanglePointers& rects,
                        const ofRectangle& boundingRect,
                        const ofVec2f& offset = ofVec2f(0,0));
    
    // packing
    static void pack(RectanglePointers& rects,
                     const ofRectangle& boundingRect);

    static void pack(RectanglePointers& rects);


private:
    RectangleUtils();
    ~RectangleUtils();

};


} // namespace ofx


////    static void stack(vector<ofRectangle*>& rects,
////                      ofxMuiAlign selfAlign = ALIGN_LEFT,
////                      ofxMuiAlign hGroupAlign = ALIGN_LEFT, 
////                      ofxMuiAlign vGroupAlign = ALIGN_TOP,
////                      float spacing = 0,
////                      ofPoint anchor = ofPoint(0,0),
////                      bool reverseStackOrder = false);
////    
////    
////    static void wrap(vector<ofRectangle*>& rects,
////                     ofRectangle& boundingBox,
////                     float horizontalSpace = 0,
////                     float verticalSpace = 0,
////                     ofxMuiAlign hAlign = ALIGN_LEFT,
////                     ofxMuiAlign vLineAlign = ALIGN_TOP,
////                     float lineHeight = 0);
////    
//    /*
//    static void tile(vector<ofRectangle*>& rects, 
//                     ofRectangle& boundingBox);
//    */
//    
////    static void cascade(vector<ofRectangle*>& rects, 
////                        ofRectangle& boundingBox, 
////                        ofPoint offset = ofPoint(25,50));
////    
