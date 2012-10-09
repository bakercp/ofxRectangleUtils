/*==============================================================================
 
 Copyright (c) 2009-2012 Christopher Baker <http://christopherbaker.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ==============================================================================*/

#pragma once

#include "ofMain.h"
#include "ofConstants.h"

//#include "ofxMaxRectsBinPack.h"

enum ofRectangleSortType {
    
};

void ofSortByHorzAnchor(vector<ofRectangle*>& rects,
                        const ofAlignHorz& horzAnchor);

void ofSortByVertAnchor(vector<ofRectangle*>& rects,
                        const ofAlignVert& vertAnchor);

void ofSortByX(vector<ofRectangle*>& rects);
void ofSortByY(vector<ofRectangle*>& rects);
void ofSortByLeft(vector<ofRectangle*>& rects);
void ofSortByTop(vector<ofRectangle*>& rects);
void ofSortByRight(vector<ofRectangle*>& rects);
void ofSortByBottom(vector<ofRectangle*>& rects);
void ofSortByHorzCenter(vector<ofRectangle*>& rects);
void ofSortByVertCenter(vector<ofRectangle*>& rects);
void ofSortByWidth(vector<ofRectangle*>& rects);
void ofSortByHeight(vector<ofRectangle*>& rects);
void ofSortByAbsWidth(vector<ofRectangle*>& rects);
void ofSortByAbsHeight(vector<ofRectangle*>& rects);
void ofSortByArea(vector<ofRectangle*>& rects);
void ofSortByPerimeter(vector<ofRectangle*>& rects);

void ofCanonicalize(vector<ofRectangle*>& rects);

ofRectangle ofGetBoundingBox(vector<ofRectangle*>& rects);

void ofAlign(vector<ofRectangle*>& rects,
             const ofAlignHorz& horzAnchor,
             const ofAlignVert& vertAnchor);

void ofAlignHorizontal(vector<ofRectangle*>& rects,
                       const ofAlignHorz& horzAnchor);

void ofAlignVertical(vector<ofRectangle*>& rects,
                     const ofAlignVert& vertAnchor);

void ofDistributeHorizontal(vector<ofRectangle*>& rects,
                            const ofRectangle& boundingRect,
                            const ofAlignHorz& horzAnchor);

void ofDistributeHorizontal(vector<ofRectangle*>& rects,
                            const ofAlignHorz& horzAnchor);

void ofDistributeVertical(vector<ofRectangle*>& rects,
                          const ofRectangle& boundingRect,
                          const ofAlignVert& vertAnchor);

void ofDistributeVertical(vector<ofRectangle*>& rects,
                          const ofAlignVert& vertAnchor);

void ofDistribute(vector<ofRectangle*>& rects,
                  const ofRectangle& boundingRect,
                  const ofAlignHorz& horzAnchor,
                  const ofAlignVert& vertAnchor);

void ofDistribute(vector<ofRectangle*>& rects,
                  const ofAlignHorz& horzAnchor,
                  const ofAlignVert& vertAnchor);

void ofStackHorzizontal(vector<ofRectangle*>& rects, float startX = 0);
void ofStackVertical(vector<ofRectangle*>& rects, float startY = 0);

void ofCascade(vector<ofRectangle*>& rects,
               const ofRectangle& boundingRect,
               const ofPoint& offset);



bool ofPack(vector<ofRectangle*>& rects,
            const ofRectangle& boundingRect);




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
//    /*
//     // TODO:
//     // https://github.com/jakesgordon/bin-packing/
//
//    static void pack(vector<ofRectangles*>& rects,
//                     ofRectangle& boundingBox);
//    */
//    
//    // statistical utilities
//    
////
////    
////    static void selectRectangles(vector<ofRectangle*>& toTest, 
////                                 vector<ofRectangle*>& selected, 
////                                 const ofRectangle boundingBox, 
////                                 bool enclosed=true);
////    
////    static void selectRectangles(vector<ofRectangle*>& toTest, 
////                                 vector<ofRectangle*>& selected, 
////                                 const ofPoint pnt, 
////                                 bool findAll = false);
//
