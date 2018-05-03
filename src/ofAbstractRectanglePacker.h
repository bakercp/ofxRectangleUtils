//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofConstants.h"
#include "ofWindowSettings.h"


/// \brief Defines an abstract rectangle packer.
template<typename T>
class ofAbstractRectanglePacker_
{
public:
    /// \brief Create a default ofAbstractRectanglePacker_.
    ofAbstractRectanglePacker_();

    /// \brief Destroy the ofAbstractRectanglePacker_.
    virtual ~ofAbstractRectanglePacker_();

    /// \returns the occupancy (ratio of area packed with rectangles, to empty space).
    virtual float getOccupancy() const = 0;

    /// \returns the width of the rectangle packer.
    virtual T getWidth() const = 0;

    /// \returns the height of the rectangle packer.
    virtual T getHeight() const = 0;

    /// \brief Remove all packed rectangles.
    virtual void reset() = 0;
    
protected:
    /// \brief Pack a rectangle.
    /// \param width The width of the rectangle to pack.
    /// \param height The height of the rectangle to pack.
    /// \param packedX The x-position of the packed rectangle within the packer.
    /// \param packedY The y-position of the packed rectangle within the packer.
    /// \param packedWidth The width of the packed rectangle within the packer.
    /// \param packedHeight The height of the packed rectangle within the packer.
    /// \param packedOrientation The resulting orientation of the rectangle within the packer.
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
