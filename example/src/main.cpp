//
// Copyright (c) 2009 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


int main()
{
    ofSetupOpenGL(1100, 768, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}
