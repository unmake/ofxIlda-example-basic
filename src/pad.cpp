//
//  pad.cpp
//  ofxIlda example basic
//
//  Created by Halfdan Jensen on 20/05/2016.
//
//

#include "pad.h"

//---------------------------------------------------------------
pad::pad(int xStart, int yStart, int w, int h, int xIntersectLimit, int boardZeroY, int boardH){
    x = xStart;
    y = yStart;
    width = w;
    height = h;
    ySpeed = 5;
    this->xIntersectLimit = xIntersectLimit;
    boardHeight = boardH;
    boardZero_Y = boardZeroY;
}

//---------------------------------------------------------------
void pad::move(){
    if (moveUp && y > boardZero_Y) y -= ySpeed;
    else if (moveDown && y < boardZero_Y+boardHeight - height) y +=ySpeed;
}

//---------------------------------------------------------------
void pad::draw(){
    ofSetColor(ofColor(255, 0, 0));
    ofRect(x, y, width, height);
}

//---------------------------------------------------------------
vector <ofPoint> pad::getDrawPoints(){
    vector<ofPoint> points;
    points.push_back(ofPoint(x, y));
    //points.push_back(ofPoint(x+width, y));
    //points.push_back(ofPoint(x+width, y+height));
    points.push_back(ofPoint(x, y+height));
    //points.push_back(ofPoint(x, y));
    return points;
}

//---------------------------------------------------------------
bool pad::intersect(int ballX, int ballY){
    if (xIntersectLimit > x){ // limit is on the right side
        if (ballX < xIntersectLimit && ballY > y && ballY < y+height){
            return true;
        }
    }
    else { // limit is on the left side
        if (ballX > xIntersectLimit && ballY > y && ballY < y+height){
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------
bool pad::behindXIntersectLimit(int ballX){
    if (x < xIntersectLimit){ // limit is on the left side
        if (ballX < xIntersectLimit) return true;
    }
    else { // limit is on the left side
        if (ballX > xIntersectLimit) return true;
    }
    return false;
}


