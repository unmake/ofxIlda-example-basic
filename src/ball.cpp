//
//  ball.cpp
//  ofxIlda example basic
//
//  Created by Halfdan Jensen on 20/05/2016.
//
//

#include "ball.h"

//----------------------------------------------
ball::ball(int w, int h, int startX, int startY){
    width = w;
    height = h;
    x = startX;
    y = startY;
    xSpeed = 4;
    ySpeed = 4;
}

//----------------------------------------------
void ball::move(){
    x += xSpeed;
    y += ySpeed;
}

//----------------------------------------------
vector <ofPoint> ball::getDrawPoints(int resolution){
    vector<ofPoint> points;
    int radius = width/2;
    for (int i = 0; i < 360; i+=resolution){
        float edgePointX = radius*cos(ofDegToRad(i)) + x; // xCoord on circle: r * cos(angelInRadians) + centerXCoord
        float edgePointY = radius*sin(ofDegToRad(i)) + y; // yCoord on circle: r * sin(angelInRadians) + centerYCoord
        points.push_back(ofPoint(edgePointX, edgePointY));
    }
    points.push_back(points[0]); // close the circle by adding last point again
    return points;
}

//-----------------------------------------------
void ball::draw(){
    ofEllipse(x, y, width, height);
}

//-----------------------------------------------
void ball::changeDir(bool horizontal, bool vertical){
    if (horizontal) xSpeed = -xSpeed;
    if (vertical) ySpeed = -ySpeed;
}



