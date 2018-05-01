//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


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
//  http://clb.demon.fi/files/RectangleBinPack/ and
//  https://github.com/juj/RectangleBinPack
//


#pragma once


#include "ofBaseOnlineRectanglePacker.h"
#include "ofWindowSettings.h"


class ofRectanglePacker: public ofBaseOnlineRectanglePacker_<float>
{
public:
    ofRectanglePacker(const ofRectangle& bounds, float padding):
        _bounds(bounds)
    {
		_padding = padding;
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

    float getWidth() const override
    {
        return _bounds.getWidth();
    }

    float getHeight() const override
    {
        return _bounds.getHeight();
    }

protected:
    ofRectangle _bounds;

};


