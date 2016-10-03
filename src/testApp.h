#pragma once

#include "ball.h"
#include "pad.h"
#include "ofMain.h"
#include "ofxEtherdream.h"

class testApp : public ofBaseApp{
    
public:
    
    // --- METHODS ---
    void setup();
    void update();
    void draw();
    ofPoint ildaTranslate(ofPoint point);
    vector <ofPoint> ildaTranslate(vector <ofPoint>);
    void mouseMoved(int x, int y);
    void keyReleased(int key);
    vector<ofPoint> getLetterDrawPoints(vector<ofPoint> letter, int xMove, int yMove);
    vector<ofPoint> scaleLetter(vector<ofPoint> letter, int scaleFactor);
    vector<ofPoint> getScoreVector(int score);
    
    // --- ATTRIBUTES ---
    ofxIlda::Frame ildaFrame;   // stores and manages ILDA frame drawings
    ofxEtherdream etherdream;   // interface to the etherdream device

    #define ZERO_X 0
    #define ZERO_Y 0
    #define WIDTH 500
    #define HEIGHT 200
    #define X_OFFSET 100
    #define Y_OFFSET 150
    #define NR_OF_ILDA_POINTS 400
    #define BALL_RESOLUTION 40
    #define LETTER_SCALE_FACTOR 5
    #define LETTER_SPACING 30
    #define OUTPUT_SCALING 0.8 // for scaling the whole projection to adjust on site
    #define TEXT_TIMER_INTERVAL 500
    #define NUMBER_SCALE_FACTOR 15
    
    ofPoint padOneScorePos, padTwoScorePos;
    
    bool looseState;
    
    // variables for normal text
    ofTrueTypeFont myfont;
    ofFloatColor color = ofFloatColor(0,1,0);
    ofFloatColor colorWhite = ofFloatColor(1,1,1);
    
    // game element objects
    ball gameBall = ball(10, 10, ZERO_X+WIDTH/2, ZERO_Y+HEIGHT/2);
    pad gamePadOne = pad(ZERO_X+WIDTH-30, 100, 10, 50, ZERO_X+WIDTH-40, ZERO_Y, HEIGHT);
    pad gamePadTwo = pad(ZERO_X+20, 100, 10, 50, ZERO_X+30, ZERO_Y, HEIGHT);
    
    // vector for storing points for top and bottom lines
    vector<ofPoint> top;
    vector <ofPoint> bottom;
    
    int mode = 0; // 0: Start screen 1: game running 2: game finished
    long int time = 0; // timer variavle for mode control
    long int textTimer = 0; // timer variable for text on start screen
    int textState = 0;
    
    
    
    // alphabet letter vector variables
    vector<ofPoint> a;
    vector<ofPoint> b;
    vector<ofPoint> c;
    vector<ofPoint> d;
    vector<ofPoint> e;
    vector<ofPoint> f;
    vector<ofPoint> g;
    vector<ofPoint> h;
    vector<ofPoint> i;
    vector<ofPoint> j;
    vector<ofPoint> k;
    vector<ofPoint> l;
    vector<ofPoint> m;
    vector<ofPoint> n;
    vector<ofPoint> o;
    vector<ofPoint> p;
    vector<ofPoint> q;
    vector<ofPoint> r;
    vector<ofPoint> s;
    vector<ofPoint> t;
    vector<ofPoint> u;
    vector<ofPoint> v;
    vector<ofPoint> w;
    vector<ofPoint> x;
    vector<ofPoint> y;
    vector<ofPoint> z;
    
    vector<ofPoint> zero;
    vector<ofPoint> one;
    vector<ofPoint> two;
    vector<ofPoint> three;
    vector<ofPoint> four;
    vector<ofPoint> five;
    
};
