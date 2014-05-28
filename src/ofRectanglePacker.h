// =============================================================================
//
// Copyright (c) 2009-2014 Christopher Baker <http://christopherbaker.net>
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
//
//  This source is based on the texture-atlas rectangle packing class from
//  the https://github.com/rougier/freetype-gl project.
//
//  Their texture atlas source is based on  the article by Jukka Jylänki :
//  "A Thousand Ways to Pack the Bin - A Practical Approach to
//  Two-Dimensional Rectangle Bin Packing", February 27, 2010.
//
//  More precisely, this is an implementation of the Skyline Bottom-Left
//  algorithm based on C++ sources provided by Jukka Jylänki at:
//  http://clb.demon.fi/files/RectangleBinPack/
//
//  ============================================================================


#pragma once


#include "ofBaseOnlineRectanglePacker.h"


class ofRectanglePacker: public ofBaseOnlineRectanglePacker_<float>
{
public:
    ofRectanglePacker(const ofRectangle& bounds):
        _bounds(bounds)
    {
    }

    virtual ~ofRectanglePacker()
    {
    }

    bool pack(ofRectangle& rect)
    {
        ofOrientation orient;

        return ofBaseOnlineRectanglePacker_<float>::pack(rect.getWidth(),
                                                         rect.getHeight(),
                                                         rect.x,
                                                         rect.y,
                                                         rect.width,
                                                         rect.height,
                                                         orient);
    }

    float getWidth() const
    {
        return _bounds.getWidth();
    }

    float getHeight() const
    {
        return _bounds.getHeight();
    }


protected:
    ofRectangle _bounds;

};


