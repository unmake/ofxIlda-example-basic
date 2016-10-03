//
//  ball.h
//  ofxIlda example basic
//
//  Created by Halfdan Jensen on 20/05/2016.
//
//


#ifndef __ofxIlda_example_basic__ball__



#define __ofxIlda_example_basic__ball__

#include "ofMain.h"


class ball{
    
public:
    ball(int w, int h, int startX, int startY);
    void move();
    vector<ofPoint> getDrawPoints(int resolution);
    void draw();
    void changeDir(bool horizontal, bool vertical);
    int y, x;
    int width, height;
    int xSpeed, ySpeed;
};




#endif /* defined(__ofxIlda_example_basic__ball__) */

