//
//  pad.h
//  ofxIlda example basic
//
//  Created by Halfdan Jensen on 20/05/2016.
//
//

#ifndef __ofxIlda_example_basic__pad__
#define __ofxIlda_example_basic__pad__
#include "ofMain.h"

class pad{
    
    public:
        int x, y;
        int xIntersectLimit;
        int ySpeed;
        bool moveUp, moveDown;
        int width, height;
        int boardHeight;
        int boardZero_Y;
        int score;
    
        bool intersect(int ballX, int ballY);
        bool behindXIntersectLimit(int x);
        pad(int xStart, int yStart, int w, int h, int xIntersectLimit, int boardZeroY, int boardH);
        void move();
        void draw();
        vector <ofPoint> getDrawPoints();
    private:
    
};

#endif /* defined(__ofxIlda_example_basic__pad__) */
