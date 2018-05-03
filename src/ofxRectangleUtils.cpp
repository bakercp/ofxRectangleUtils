//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofxRectangleUtils.h"
#include "ofLog.h"
#include <cmath>


namespace ofx {


void RectangleUtils::standardize(RectanglePointers& rects)
{
    for(RectanglePointersIter iter = rects.begin(); iter != rects.end(); ++iter)
    {
        (*iter)->standardize();
    }
}


//bool RectangleUtils::isInside(const ofRectangle& r0, const ofRectangle& r1)
//{
//    return  isInside(r0,r1.x, r1.y) &&
//            isInside(r0,(r1.x + r1.width), (r1.y+ r1.height));
//}


//bool RectangleUtils::isInside(const ofRectangle& r0, const float& px, const float& py)
//{
//    return px > r0.x &&
//           py > r0.y &&
//           px < (r0.x + r0.width) &&
//           py < (r0.y + r0.height);
//}


bool RectangleUtils::compareByX(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getX() < r1->getX();
}


bool RectangleUtils::compareByY(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getY() < r1->getY();
}


bool RectangleUtils::compareByLeft(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getMinX() < r1->getMinX();
}


bool RectangleUtils::compareByTop(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getMinY() < r1->getMinY();
}


bool RectangleUtils::compareByRight(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getMaxX() < r1->getMaxX();
}


bool RectangleUtils::compareByBottom(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getMaxY() < r1->getMaxY();
}


bool RectangleUtils::compareByHorzCenter(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getCenter().x > r1->getCenter().x;
}


bool RectangleUtils::compareByVertCenter(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getCenter().y < r1->getCenter().y;
}


bool RectangleUtils::compareByWidth(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getWidth() < r1->getWidth();
}


bool RectangleUtils::compareByHeight(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getHeight() < r1->getHeight();
}


bool RectangleUtils::compareByAbsWidth(ofRectangle* r0, ofRectangle* r1)
{
    return std::fabs(r0->getWidth()) < std::fabs(r1->getWidth());
}


bool RectangleUtils::compareByAbsHeight(ofRectangle* r0, ofRectangle* r1)
{
    return std::fabs(r0->getHeight()) < std::fabs(r1->getHeight());
}


bool RectangleUtils::compareByArea(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getArea() < r1->getArea();
}
    

bool RectangleUtils::compareByPerimeter(ofRectangle* r0, ofRectangle* r1)
{
    return r0->getPerimeter() < r1->getPerimeter();
}


void RectangleUtils::sortByHorzAnchor(RectanglePointers& rects,
                                      ofAlignHorz horzAnchor)
{    
    switch(horzAnchor) {
        case OF_ALIGN_HORZ_IGNORE:
            ofLogVerbose("ofSortByHorzAnchor") << "horzAnchor = OF_ALIGN_HORZ_IGNORE.  Skipping sort.";
            break;
        case OF_ALIGN_HORZ_LEFT:
            sortByLeft(rects);
            break;
        case OF_ALIGN_HORZ_RIGHT:
            sortByRight(rects);
            break;
        case OF_ALIGN_HORZ_CENTER:
            sortByHorzCenter(rects);
            break;
    }
}


void RectangleUtils::sortByVertAnchor(RectanglePointers& rects,
                                      ofAlignVert vertAnchor)
{
    switch(vertAnchor) {
        case OF_ALIGN_VERT_IGNORE:
            ofLogVerbose("ofSortByHorzAnchor") << "horzAnchor = OF_ALIGN_HORZ_IGNORE.  Skipping sort.";
            break;
        case OF_ALIGN_VERT_TOP:
            sortByTop(rects);
            break;
        case OF_ALIGN_VERT_BOTTOM:
            sortByBottom(rects);
            break;
        case OF_ALIGN_VERT_CENTER:
            sortByVertCenter(rects);
            break;
    }
}



void RectangleUtils::sortByX(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByX);
}


void RectangleUtils::sortByY(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByY);
}


void RectangleUtils::sortByLeft(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByLeft);
}


void RectangleUtils::sortByTop(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByTop);
}


void RectangleUtils::sortByRight(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByRight);
}


void RectangleUtils::sortByBottom(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByBottom);
}


void RectangleUtils::sortByHorzCenter(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByHorzCenter);
}


void RectangleUtils::sortByVertCenter(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByVertCenter);
}


void RectangleUtils::sortByWidth(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByWidth);
}


void RectangleUtils::sortByHeight(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByHeight);
}


void RectangleUtils::sortByAbsWidth(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByAbsWidth);
}


void RectangleUtils::sortByAbsHeight(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByAbsHeight);
}


void RectangleUtils::sortByArea(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByArea);
}


void RectangleUtils::sortByPerimeter(RectanglePointers& rects)
{
    std::sort(rects.begin(), rects.end(), compareByPerimeter);
}


ofRectangle RectangleUtils::getBoundingBox(RectanglePointers& rects)
{
    ofRectangle result;

    for(RectanglePointersIter iter = rects.begin(); iter != rects.end(); ++iter)
    {
        // on the first rect, set result equal
        // so the NULL result isn't
        // treated like a valid rectangle.
        if(iter == rects.begin())
        {
            result.set(*(*iter));
        }
        else
        {
            result.growToInclude(*(*iter));
        }
    }
    
    return result;
}


void RectangleUtils::align(RectanglePointers& rects,
                           ofAlignHorz horzAnchor,
                           ofAlignVert vertAnchor)
{    
    alignHorz(rects,horzAnchor);
    alignVert(rects,vertAnchor);
}


void RectangleUtils::alignHorz(RectanglePointers& rects, ofAlignHorz horzAnchor)
{
    if (horzAnchor != OF_ALIGN_HORZ_IGNORE)
    {
        float xAlign = 0.0f;

        sortByHorzAnchor(rects, horzAnchor);

        for (RectanglePointersIter iter = rects.begin(); iter != rects.end(); ++iter)
        {
            if (iter == rects.begin())
            {
                xAlign = (*iter)->getHorzAnchor(horzAnchor);
            }
            else
            {
                (*iter)->translateX(xAlign - (*iter)->getHorzAnchor(horzAnchor));
            }
        }
    }
    else
    {
        ofLogVerbose("ofAlignHorizontal") << "OF_ALIGN_HORZ_IGNORE align requested, ignoring.";
    }
}


void RectangleUtils::alignVert(RectanglePointers& rects,
                               ofAlignVert vertAnchor)
{

    std::cout << "here" << std::endl;
    if(vertAnchor != OF_ALIGN_VERT_IGNORE)
    {
        float yAlign = 0.0f;
        sortByVertAnchor(rects, vertAnchor);
        for(RectanglePointersIter iter = rects.begin(); iter != rects.end(); ++iter)
        {
            if(iter == rects.begin()) {
                yAlign = (*iter)->getVertAnchor(vertAnchor);
            } else {
                (*iter)->translateY(yAlign - (*iter)->getVertAnchor(vertAnchor));
            }
        }
    } else {
        ofLogVerbose("ofAlignVertical") << "OF_ALIGN_VERT_IGNORE align requested, ignoring.";
    }
}


void RectangleUtils::distributeHorz(RectanglePointers& rects,
                                    const ofRectangle& boundingRect,
                                    ofAlignHorz horzAnchor)
{
    
    if(rects.size() >= 3 && horzAnchor != OF_ALIGN_HORZ_IGNORE) {
        sortByHorzAnchor(rects,horzAnchor);
        
        if (!rects.empty())
        {
                std::size_t nPos = rects.size() - 1;

                // adjust to bounding bounding rect.  if bounding rect is based on the group, nothing will change
                rects[0]->translateX(boundingRect.getLeft() - rects[0]->getLeft());
                rects[nPos]->translateX(boundingRect.getRight() - rects[nPos]->getRight());

                float leftX   = rects[0]->getHorzAnchor(horzAnchor);
                float rightX  = rects[nPos]->getHorzAnchor(horzAnchor);

                float span = ( rightX - leftX ) / ( nPos );
                for (size_t i = 1; i < nPos; i++)
                {
                    rects[i]->translateX((leftX - rects[i]->getHorzAnchor(horzAnchor)) + i * span);
                }
        }
    }
    else
    {
        if (horzAnchor == OF_ALIGN_HORZ_IGNORE) {
            ofLogVerbose("ofDistributeHorizontal") << "OF_ALIGN_HORZ_IGNORE distribute requested, ignoring.";
        } else {
            ofLogWarning("ofDistributeHorizontal") << "Not enough rectangles to distribute.";
        }
    }
}


void RectangleUtils::distributeHorz(RectanglePointers& rects,
                                    ofAlignHorz horzAnchor)
{
    distributeHorz(rects,getBoundingBox(rects),horzAnchor);
}


void RectangleUtils::distributeVert(RectanglePointers& rects,
                                    const ofRectangle& boundingRect,
                                    ofAlignVert vertAnchor)
{

    if(rects.size() >= 3 && vertAnchor != OF_ALIGN_VERT_IGNORE) {
        sortByVertAnchor(rects,vertAnchor);

        if (!rects.empty())
        {
            std::size_t nPos = rects.size() - 1;

            // adjust to bounding bounding rect.  if bounding rect is based on the group, nothing will change
            rects[0]->translateY(boundingRect.getTop() - rects[0]->getTop());
            rects[nPos]->translateY(boundingRect.getBottom() - rects[nPos]->getBottom());

            float topY    = rects[0]->getVertAnchor(vertAnchor);
            float bottomY = rects[nPos]->getVertAnchor(vertAnchor);
            float span = ( bottomY - topY ) / ( nPos );
            for (std::size_t i = 1; i < nPos; i++) {
                rects[i]->translateY((topY - rects[i]->getVertAnchor(vertAnchor)) + i * span);
            }
        }
    } else {
        if(vertAnchor == OF_ALIGN_VERT_IGNORE) {
            ofLogVerbose("ofDistributeVertical") << "OF_ALIGN_VERT_IGNORE distribute requested, ignoring.";
        } else {
            ofLogWarning("ofDistributeVertical") << "Not enough rectangles to distribute.";
        }
    }
}


void RectangleUtils::distributeVert(RectanglePointers& rects,
                                    ofAlignVert vertAnchor)
{
    distributeVert(rects,getBoundingBox(rects),vertAnchor);
}


void RectangleUtils::distribute(RectanglePointers& rects,
                                const ofRectangle& boundingRect,
                                ofAlignHorz horzAnchor,
                                ofAlignVert vertAnchor)
{    
    distributeHorz(rects,boundingRect,horzAnchor);
    distributeVert(rects,boundingRect,vertAnchor);
}


void RectangleUtils::distribute(RectanglePointers& rects,
                                ofAlignHorz horzAnchor,
                                ofAlignVert vertAnchor)
{
    ofRectangle boundingRect = getBoundingBox(rects);
    distribute(rects,boundingRect,horzAnchor,vertAnchor);
}


void RectangleUtils::cascade(RectanglePointers& rects,
                             const ofRectangle& boundingRect,
                             const glm::vec2& offset) {
    
    ofRectangle bb = boundingRect.getStandardized();
    glm::vec3 currentPosition = bb.getTopLeft();
    
    int currentRow = 0;
    int currentColumn = 0;
    
    for (size_t i = 0; i < rects.size(); i++)
    {
        ofRectangle* r = rects[i]; // get the pointer
        
        r->standardize();
        
        if ((currentPosition.y + r->height) > (bb.getBottom())) {
            // new row, new column
            currentColumn++;
            currentPosition.x = currentColumn * offset.x + bb.x;
            currentRow = 0;
            currentPosition.y = bb.y;
        }
        
        r->setPosition(glm::vec3(currentPosition));
        currentPosition += glm::vec3(offset.x, offset.y, 0);
    }
    
}



void RectangleUtils::stackHorz(RectanglePointers& rects, float offsetX)
{
    for (size_t i = 0; i < rects.size(); i++) {
        rects[i]->standardize(); // make sure
        if(i == 0) {
            rects[i]->setX(offsetX);
        } else {
            rects[i]->setX(rects[i-1]->getRight());
        }
    }    
}


void RectangleUtils::stackVert(RectanglePointers& rects, float offsetY)
{
    for(size_t i = 0; i < rects.size(); i++) {
        rects[i]->standardize(); // make sure
        if(i == 0) {
            rects[i]->setY(offsetY);
        } else {
            rects[i]->setY(rects[i-1]->getBottom());
        }
    }
}


void RectangleUtils::pack(RectanglePointers& rects,
                          const ofRectangle& boundingRect)
{
    ofRectanglePacker packer(boundingRect, 0);

    for(size_t i = 0; i < rects.size(); i++)
    {
        if (!packer.pack(*rects[i])) return;
    }
}

void RectangleUtils::pack(RectanglePointers& rects)
{
    return pack(rects, getBoundingBox(rects));
}


//bool ofPack(RectanglePointers& rects,
//            const ofRectangle& boundingRect) {
//
////    ofxofRectanglePacker packer(boundingRect.width,
////                              boundingRect.height);
////    
////    vector<ofRectangle*> original = rects;
////    rects.clear();
////    
////    packer.Insert(rects, rects, ofxofRectanglePacker::RectBestShortSideFit);
////    
//    return true;
//}

//// like distribute, but doesn't rely on the max and min places to fit
//void ofxMuiRectUtils::stack(RectanglePointers& rects, 
//                            ofxMuiAlign selfAlign,
//                            ofxMuiAlign hGroupAlign, 
//                            ofxMuiAlign vGroupAlign,
//                            float spacing,
//                            glm::vec2 anchor,
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
//
//void ofxMuiRectUtils::wrap(RectanglePointers& rects, 
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
//
//void ofxMuiRectUtils::tile(RectanglePointers& rects, ofRectangle& boundingBox) {
//}
// */


} // namespace ofx

