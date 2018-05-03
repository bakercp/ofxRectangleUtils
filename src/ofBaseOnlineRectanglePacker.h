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


#include <limits>
#include "ofAbstractRectanglePacker.h"


template<typename T>
class ofBaseOnlineRectanglePacker_: public ofAbstractRectanglePacker_<T>
{
public:
    ofBaseOnlineRectanglePacker_(T padding = 0);

    virtual ~ofBaseOnlineRectanglePacker_();

    float getOccupancy() const override;

    void reset() override;

    /// \returns the padding specified around each rectangle.
    T getPadding() const;

    /// \returns the area used.
    T getAreaUsed() const;

protected:
    virtual bool pack(T width,
                      T height,
                      T& packedX,
                      T& packedY,
                      T& packedWidth,
                      T& packedHeight,
                      ofOrientation& packedOrientation) override;

    int fit(std::size_t index, T width, T height);

    void merge();

    struct Node
    {
        T x;
        T y;
        T width;
    };

    std::vector<Node> _nodes;

    T _padding;
    T _areaUsed;

};


template<typename T>
ofBaseOnlineRectanglePacker_<T>::ofBaseOnlineRectanglePacker_(T padding):
    _padding(padding),
    _areaUsed(0)
{
}


template<typename T>
ofBaseOnlineRectanglePacker_<T>::~ofBaseOnlineRectanglePacker_()
{
}


template<typename T>
bool ofBaseOnlineRectanglePacker_<T>::pack(T width,
                                           T height,
                                           T& packedX,
                                           T& packedY,
                                           T& packedWidth,
                                           T& packedHeight,
                                           ofOrientation& packedOrientation)
{
    if (_nodes.empty())
    {
        // Create an initial dummy node.
        // If padding is included, this will enforce the top / left padding.
        Node _node;
        _node.x = _padding;
        _node.y = _padding;
        _node.width = this->getWidth() - 2 * _padding;
        _nodes.push_back(_node);
    }

    bool foundIndex = false;
    std::size_t best_index = 0;

    T best_height = std::numeric_limits<T>::max();
    T best_width = std::numeric_limits<T>::max();

    // At least one node must be present to begin.
    // The fist node is added in the constructor.
    for (std::size_t i = 0; i < _nodes.size(); ++i)
    {
        T y = fit(i, width + _padding, height + _padding);

        if (y >= 0)
        {
            T nextY = y + height + _padding;

            // Verify the rectangle fits at this Y.
            if ((nextY < best_height ) || ((nextY == best_height) && (_nodes[i].width < best_width)))
            {
                best_height = nextY;
                best_index = i;
                foundIndex = true;
                best_width = _nodes[i].width;

                // Set the output.
                packedX = _nodes[i].x;
                packedY = y;
                packedWidth = width;
                packedHeight = height;
                packedOrientation = OF_ORIENTATION_DEFAULT;
            }
        }
    }

    // Unable to find a fit.
    if (!foundIndex)
    {
		// Lets not spoil the provided rect
        // packedX = 0;
        // packedY = 0;
        // packedWidth = 0;
        // packedHeight = 0;
        packedOrientation = OF_ORIENTATION_DEFAULT;
        return false;
    }

    // Create a new node with the succesful location.
    Node _node;

    _node.x = packedX;
    _node.y = packedY + height + _padding;
    _node.width = width + _padding;

    // Add the node at the correct index.
    _nodes.insert(_nodes.begin() + best_index, _node);

    // Adjust the current nodes, shrinking as needed.
    for (std::size_t i = best_index + 1; i < _nodes.size(); ++i)
    {
        // The last X edge
        T lastX = _nodes[i - 1].x + _nodes[i - 1].width;

        if (_nodes[i].x < lastX)
        {
            // Shrink factor.
            T shrink = lastX - _nodes[i].x;

            // Expand node
            _nodes[i].x += shrink;
            _nodes[i].width -= shrink;

            // If the remaining node width disappears, then erase that node.
            if (_nodes[i].width <= 0)
            {
                _nodes.erase(_nodes.begin() + i);
                --i;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    // Merge the existing nodes if possible.
    merge();

    // Here we use "this" because we must be explicit with templates.
    this->_areaUsed += (width * height);

    // Return success.
    return true;
}


template<typename T>
float ofBaseOnlineRectanglePacker_<T>::getOccupancy() const
{
    // Here we use "this" because we must be explicit with templates.
    return static_cast<float>(this->_areaUsed) / (this->getWidth() * this->getHeight());
}


template<typename T>
void ofBaseOnlineRectanglePacker_<T>::reset()
{
    _nodes.clear();
    _areaUsed = 0;
}


template<typename T>
T ofBaseOnlineRectanglePacker_<T>::getPadding() const
{
    return this->_padding;
}


template<typename T>
T ofBaseOnlineRectanglePacker_<T>::getAreaUsed() const
{
    return this->_areaUsed;
}


template<typename T>
int ofBaseOnlineRectanglePacker_<T>::fit(std::size_t i,
                                         T width,
                                         T height)
{
    T x = _nodes[i].x; // initial x
    T y = _nodes[i].y; // initial y
    T width_left = width; // initial width

    // Check to see if the left node position + the
    // proposed width is greater than the size.
    if ((x + width) > (this->getWidth()))
    {
        return -1;
    }

    // Keep moving to find a place to find a vertical fit.
    while (width_left > 0 && i < _nodes.size())
    {
        if (_nodes[i].y > y)
        {
            y = _nodes[i].y;
        }

        if ((y + height) > (this->getHeight() ))
        {
            return -1;
        }

        width_left -= _nodes[i].width;

        ++i;
    }

    return y;
}


template<typename T>
void ofBaseOnlineRectanglePacker_<T>::merge()
{
    // Attempt to merge nodes by cycling through
    // and looking for equal vertical boundaries.
    for (std::size_t i = 0; i < _nodes.size() - 1; ++i)
    {
        if (_nodes[i].y == _nodes[i + 1].y)
        {
            // We found an equal node, so merge them.
            _nodes[i].width += _nodes[i + 1].width;
            _nodes.erase(_nodes.begin() + i + 1);
            --i; // step back and try i - 1 again.
        }
    }
}
