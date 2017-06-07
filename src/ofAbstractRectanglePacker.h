//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofConstants.h"


/// \brief Defines an abstract rectangle packer.
template<typename T>
class ofAbstractRectanglePacker_
{
public:
    ofAbstractRectanglePacker_();

    virtual ~ofAbstractRectanglePacker_();

    virtual float getOccupancy() const = 0;
    virtual T getWidth() const = 0;
    virtual T getHeight() const = 0;

protected:
    virtual bool pack(T width,
                      T height,
                      T& packedX,
                      T& packedY,
                      T& packedWidth,
                      T& packedHeight,
                      ofOrientation& packedOrientation) = 0;


};


template<typename T>
ofAbstractRectanglePacker_<T>::ofAbstractRectanglePacker_()
{
}


template<typename T>
ofAbstractRectanglePacker_<T>::~ofAbstractRectanglePacker_()
{
}
