#include "testApp.h"
#include "ofxIldaFrame.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(100);
    myfont.loadFont("mono.ttf", 32);
    ofSetFrameRate(30);
    etherdream.setup();
    etherdream.setPPS(30000);
    ildaFrame.polyProcessor.params.targetPointCount = NR_OF_ILDA_POINTS;
    // flip to project like screen view
    ildaFrame.params.output.transform.scale.set(-OUTPUT_SCALING, -OUTPUT_SCALING);
    
    ofNoFill();
    
    padOneScorePos = ofPoint(WIDTH/5*4-40, 50);
    padTwoScorePos = ofPoint(WIDTH/5-40, 50);
    
    // DEFINE POINTS FOR TOP AND BOTTOM
    top.push_back(ildaTranslate(ofPoint(ZERO_X,ZERO_Y)));
    top.push_back(ildaTranslate(ofPoint(ZERO_X+WIDTH,ZERO_Y)));
    bottom.push_back(ildaTranslate(ofPoint(ZERO_X,ZERO_Y+HEIGHT)));
    bottom.push_back(ildaTranslate(ofPoint(ZERO_X+WIDTH,ZERO_Y+HEIGHT)));
    
    // DEFINE POINTS FOR ALL USED LETTER
    // A
    a.push_back(ofPoint(0, 6));
    a.push_back(ofPoint(0, 1));
    a.push_back(ofPoint(1, 0));
    a.push_back(ofPoint(3, 0));
    a.push_back(ofPoint(4, 1));
    a.push_back(ofPoint(4, 6));
    a.push_back(ofPoint(4, 3));
    a.push_back(ofPoint(2, 3));
    a.push_back(ofPoint(0, 3));
    a=scaleLetter(a, LETTER_SCALE_FACTOR);
    
    // B
    b.push_back(ofPoint(0, 0));
    b.push_back(ofPoint(4, 0));
    b.push_back(ofPoint(4, 3));
    b.push_back(ofPoint(0, 3));
    b.push_back(ofPoint(4, 3));
    b.push_back(ofPoint(4, 6));
    b.push_back(ofPoint(0, 6));
    b.push_back(ofPoint(0, 0));
    b=scaleLetter(b, LETTER_SCALE_FACTOR);
    
    // C
    c.push_back(ofPoint(4, 6));
    c.push_back(ofPoint(1, 6));
    c.push_back(ofPoint(0, 5));
    c.push_back(ofPoint(0, 1));
    c.push_back(ofPoint(1, 0));
    c.push_back(ofPoint(4, 0));
    c=scaleLetter(c, LETTER_SCALE_FACTOR);
    
    // P
    p.push_back(ofPoint(0, 6));
    p.push_back(ofPoint(0, 0));
    p.push_back(ofPoint(3, 0));
    p.push_back(ofPoint(4, 1));
    p.push_back(ofPoint(4, 2));
    p.push_back(ofPoint(3, 3));
    p.push_back(ofPoint(0, 3));
    p=scaleLetter(p, LETTER_SCALE_FACTOR);
    
    // R
    r.push_back(ofPoint(0, 6));
    r.push_back(ofPoint(0, 0));
    r.push_back(ofPoint(3, 0));
    r.push_back(ofPoint(4, 1));
    r.push_back(ofPoint(4, 2));
    r.push_back(ofPoint(3, 3));
    r.push_back(ofPoint(0, 3));
    r.push_back(ofPoint(2, 3));
    r.push_back(ofPoint(4, 6));
    r=scaleLetter(r, LETTER_SCALE_FACTOR);
    
    // E
    e.push_back(ofPoint(4, 0));
    e.push_back(ofPoint(0, 0));
    e.push_back(ofPoint(0, 3));
    e.push_back(ofPoint(3, 3));
    e.push_back(ofPoint(0, 3));
    e.push_back(ofPoint(0, 6));
    e.push_back(ofPoint(4, 6));
    e=scaleLetter(e, LETTER_SCALE_FACTOR);
    
    // S
    s.push_back(ofPoint(4, 0));
    s.push_back(ofPoint(1, 0));
    s.push_back(ofPoint(0, 1));
    s.push_back(ofPoint(0, 2));
    s.push_back(ofPoint(1, 3));
    s.push_back(ofPoint(3, 3));
    s.push_back(ofPoint(4, 4));
    s.push_back(ofPoint(4, 5));
    s.push_back(ofPoint(3, 6));
    s.push_back(ofPoint(0, 6));
    s=scaleLetter(s, LETTER_SCALE_FACTOR);
    
    // U
    u.push_back(ofPoint(0, 0));
    u.push_back(ofPoint(0, 5));
    u.push_back(ofPoint(1, 6));
    u.push_back(ofPoint(3, 6));
    u.push_back(ofPoint(4, 5));
    u.push_back(ofPoint(4, 0));
    u=scaleLetter(u, LETTER_SCALE_FACTOR);
    
    // T
    t.push_back(ofPoint(2, 6));
    t.push_back(ofPoint(2, 0));
    t.push_back(ofPoint(0, 0));
    t.push_back(ofPoint(4, 0));
    t=scaleLetter(t, LETTER_SCALE_FACTOR);
    
    
    // O
    o.push_back(ofPoint(1, 0));
    o.push_back(ofPoint(3, 0));
    o.push_back(ofPoint(4, 1));
    o.push_back(ofPoint(4, 5));
    o.push_back(ofPoint(3, 6));
    o.push_back(ofPoint(1, 6));
    o.push_back(ofPoint(0, 5));
    o.push_back(ofPoint(0, 1));
    o.push_back(ofPoint(1, 0));
    o=scaleLetter(o, LETTER_SCALE_FACTOR);
    
    // N
    n.push_back(ofPoint(0, 6));
    n.push_back(ofPoint(0, 0));
    n.push_back(ofPoint(4, 6));
    n.push_back(ofPoint(4, 0));
    n=scaleLetter(n, LETTER_SCALE_FACTOR);
    
    // W
    w.push_back(ofPoint(0, 0));
    w.push_back(ofPoint(0, 6));
    w.push_back(ofPoint(2, 3));
    w.push_back(ofPoint(4, 6));
    w.push_back(ofPoint(4, 0));
    w=scaleLetter(w, LETTER_SCALE_FACTOR);
    
    // I
    i.push_back(ofPoint(2, 0));
    i.push_back(ofPoint(2, 6));
    i=scaleLetter(i, LETTER_SCALE_FACTOR);
    
    // L
    l.push_back(ofPoint(0, 0));
    l.push_back(ofPoint(0, 6));
    l.push_back(ofPoint(4, 6));
    l=scaleLetter(l, LETTER_SCALE_FACTOR);
    
    // 0
    zero.push_back(ofPoint(0, 0));
    zero.push_back(ofPoint(0, 6));
    zero.push_back(ofPoint(4, 6));
    zero.push_back(ofPoint(4, 0));
    zero.push_back(ofPoint(0, 0));
    zero=scaleLetter(zero, NUMBER_SCALE_FACTOR);
    
    // 1
    one.push_back(ofPoint(3, 0));
    one.push_back(ofPoint(3, 6));
    one=scaleLetter(one, NUMBER_SCALE_FACTOR);
    
    // 2
    two.push_back(ofPoint(0, 0));
    two.push_back(ofPoint(4, 0));
    two.push_back(ofPoint(4, 3));
    two.push_back(ofPoint(0, 3));
    two.push_back(ofPoint(0, 6));
    two.push_back(ofPoint(4, 6));
    two=scaleLetter(two, NUMBER_SCALE_FACTOR);
    
    // 3
    three.push_back(ofPoint(0, 0));
    three.push_back(ofPoint(4, 0));
    three.push_back(ofPoint(4, 3));
    three.push_back(ofPoint(0, 3));
    three.push_back(ofPoint(4, 3));
    three.push_back(ofPoint(4, 6));
    three.push_back(ofPoint(0, 6));
    three=scaleLetter(three, NUMBER_SCALE_FACTOR);
    
    // 4
    four.push_back(ofPoint(0, 0));
    four.push_back(ofPoint(0, 3));
    four.push_back(ofPoint(4, 3));
    four.push_back(ofPoint(4, 6));
    four.push_back(ofPoint(4, 0));
    four=scaleLetter(four, NUMBER_SCALE_FACTOR);
    
    // 5
    five.push_back(ofPoint(0, 6));
    five.push_back(ofPoint(4, 6));
    five.push_back(ofPoint(4, 3));
    five.push_back(ofPoint(0, 3));
    five.push_back(ofPoint(0, 0));
    five.push_back(ofPoint(6, 0));
    five=scaleLetter(five, NUMBER_SCALE_FACTOR);
}

//--------------------------------------------------------------
void testApp::update(){
    
    switch (mode) {
        
        case 0:
            gamePadOne.score = 0;
            gamePadTwo.score = 0;
            if (ofGetElapsedTimeMillis() > textTimer+TEXT_TIMER_INTERVAL) {
                textTimer=ofGetElapsedTimeMillis();
                textState++;
                if (textState==4) textState=0;
            }
            break;
            
        case 1:
            // game running
            gameBall.move();
            gamePadOne.move();
            gamePadTwo.move();
            
            // game logic: pads and ball intersection, ball direction and score
            if (!looseState && (gamePadOne.intersect(gameBall.x, gameBall.y) || gamePadTwo.intersect(gameBall.x, gameBall.y))){
                gameBall.changeDir(true, false);
            }
            else if (!looseState && (gamePadOne.behindXIntersectLimit(gameBall.x) || gamePadTwo.behindXIntersectLimit(gameBall.x))) looseState = true;
            else if (looseState) { // chect if there is a point
                if (gameBall.x > ZERO_X+WIDTH){ // pad two scores
                    gameBall.x = ZERO_X+50;
                    looseState = false;
                    gamePadTwo.score++;
                    time = ofGetElapsedTimeMillis();
                    mode=2;
                }
                else if (gameBall.x < ZERO_X){ // pad one scores
                    gameBall.x = ZERO_X+WIDTH-50;
                    looseState = false;
                    gamePadOne.score++;
                    time = ofGetElapsedTimeMillis();
                    mode=2;
                }
                if (gamePadOne.score >= 5 || gamePadTwo.score >= 5) {
                    // reset game and change mode
                    // write reset game code here
                    time = ofGetElapsedTimeMillis();
                    mode=3;
                }
            }
            // y-axis boundry
            if (gameBall.y-gameBall.height/2 < ZERO_Y || gameBall.y+gameBall.height/2 > ZERO_Y+HEIGHT) gameBall.changeDir(false, true);
            break;
        
        case 2:
            // changes back to 1 after 3 seconds, unless game id done, then changes to 3
            if (ofGetElapsedTimeMillis() > time+3000) mode=1;
            break;
        case 3:
            // change to 0 after 5 seconds
            
            if (ofGetElapsedTimeMillis() > time+5000) mode=0;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::draw() {
    
    
    switch (mode) {
        case 0: // draw start screen
            {
                // mode changes to 1 in keyReleased method
                
                // add letters to ilda frame
                switch (textState) {
                    case 0:
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(p, 6*LETTER_SPACING, 100)), color);
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(r, 7*LETTER_SPACING, 100)), color);
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(e, 8*LETTER_SPACING, 100)), color);
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(s, 9*LETTER_SPACING, 100)), color);
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(s, 10*LETTER_SPACING, 100)), color);
                        break;
                    case 1:
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(a, 8*LETTER_SPACING, 100)), color);
                        break;
                    case 2:
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(b, 6*LETTER_SPACING, 100)), color);
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(u, 7*LETTER_SPACING, 100)), color);
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(t, 8*LETTER_SPACING, 100)), color);
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(t, 9*LETTER_SPACING, 100)), color);
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(o, 10*LETTER_SPACING, 100)), color);
                        ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(n, 11*LETTER_SPACING, 100)), color);
                        break;
                }
                
                 // do your thang
                ildaFrame.update();
                
                // draw to the screen
                ildaFrame.draw(0, 0, ofGetWidth(), ofGetHeight());
                
                // send points to the etherdream
                etherdream.setPoints(ildaFrame);
                ildaFrame.clear();
                break;
            }
        case 1: // draw game
            {
                
                // mode changes to 2 when game is won
                
                // add game elements to ilda frame
                ildaFrame.addPoly(ildaTranslate(gameBall.getDrawPoints(BALL_RESOLUTION)), color);
                ildaFrame.addPoly(ildaTranslate(gamePadTwo.getDrawPoints()), color);
                ildaFrame.addPoly(ildaTranslate(gamePadOne.getDrawPoints()), color);
                
                // add top and bottom lines to ilda frames
                ildaFrame.addPoly(top, color);
                ildaFrame.addPoly(bottom, color);
                
                // do your thang
                ildaFrame.update();
                
                // draw to the screen
                ildaFrame.draw(0, 0, ofGetWidth(), ofGetHeight());
                
                // send points to the etherdream
                etherdream.setPoints(ildaFrame);
                ildaFrame.clear();
                
                // draw non laser info to screen
                ofSetColor(0);
                myfont.drawString(ofToString(gamePadOne.score), ofGetWidth()-100, 100);
                myfont.drawString(ofToString(gamePadTwo.score), 100, 100);
                if (!etherdream.stateIsFound()) myfont.drawString("DAC not found", 10, ofGetHeight());
                break;
            }
        case 2:
            
            /*
            // SCORE AS LINES
            for (int i = 0; i < 5; i++){
                vector<ofPoint> points;
                points.push_back(ofPoint(10+i*10, 10));
                points.push_back(ofPoint(10+i*10, 100));
                if (i >= gamePadTwo.score) ildaFrame.addPoly(ildaTranslate(points), colorWhite);
                else ildaFrame.addPoly(ildaTranslate(points), color);
            }
            
            for (int i = 5; i > 0; i--){
                vector<ofPoint> points;
                points.push_back(ofPoint(WIDTH-5-i*10, 10));
                points.push_back(ofPoint(WIDTH-5-i*10, 100));
                if (i > gamePadOne.score) ildaFrame.addPoly(ildaTranslate(points), colorWhite);
                else ildaFrame.addPoly(ildaTranslate(points), color);
            }
            */
            
            // SCORE AS REAL NUMBERS
            ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(getScoreVector(gamePadOne.score), padOneScorePos.x, padOneScorePos.y)), color);
            ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(getScoreVector(gamePadTwo.score), padTwoScorePos.x, padTwoScorePos.y)), color);

            
            // do your thang
            ildaFrame.update();
            
            // draw to the screen
            ildaFrame.draw(0, 0, ofGetWidth(), ofGetHeight());
            
            // send points to the etherdream
            etherdream.setPoints(ildaFrame);
            ildaFrame.clear();
            break;
        case 3:
            {
                // DRAW GAME DONE SCREEN
                // set win and loose x-pos
                int winPos, loosePos;
                if (gamePadOne.score > gamePadTwo.score){
                    winPos = 14;
                    loosePos = 0;
                }
                else {
                    winPos = 0;
                    loosePos = 12;
                }
                // add win and loose letters to ilda frame
                ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(w, winPos*LETTER_SPACING, 100)), color);
                ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(i, (winPos+1)*LETTER_SPACING, 100)), color);
                ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(n, (winPos+2)*LETTER_SPACING, 100)), color);
                
                ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(l, loosePos*LETTER_SPACING, 100)), color);
                ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(o, (loosePos+1)*LETTER_SPACING, 100)), color);
                ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(o, (loosePos+2)*LETTER_SPACING, 100)), color);
                ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(s, (loosePos+3)*LETTER_SPACING, 100)), color);
                ildaFrame.addPoly(ildaTranslate(getLetterDrawPoints(e, (loosePos+4)*LETTER_SPACING, 100)), color);
                
                // do your thang
                ildaFrame.update();
                
                // draw to the screen
                ildaFrame.draw(0, 0, ofGetWidth(), ofGetHeight());
                
                // send points to the etherdream
                etherdream.setPoints(ildaFrame);
                ildaFrame.clear();
                break;
            }
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    if (y < ofGetHeight()-gamePadOne.height && y > 0){
        gamePadOne.y = y;
        gamePadTwo.y = y;
    }
}

//---------------------------------------------------------------
void testApp::keyReleased(int key){
    switch (mode) {
        case 0:
            mode = 1;
            break;
        case 1:
            if (key == 's'){
                gamePadTwo.moveUp = true;
                gamePadTwo.moveDown = false;
            }
            else if (key == 'f') {
                gamePadTwo.moveDown = true;
                gamePadTwo.moveUp = false;
            }
            else if (key == 'g'){
                gamePadOne.moveUp = true;
                gamePadOne.moveDown = false;
            }
            else if (key == 'd') {
                gamePadOne.moveDown = true;
                gamePadOne.moveUp = false;
            }
            break;
        default:
            break;
    }
}

//----------------------------------------------------------------
ofPoint testApp::ildaTranslate(ofPoint point){
    float mappingFactor = 0.05;
    float margin = (HEIGHT-point.y)*mappingFactor;
    float interval = WIDTH - margin*2;
    point.x = ofMap(point.x, 0, WIDTH, margin, interval+margin);
    
    //offsets
    point.x = point.x + X_OFFSET;
    point.y = point.y + Y_OFFSET;
    return ofPoint((float) point.x / (float) ofGetWidth(), (float) point.y / (float) ofGetHeight());
}

//----------------------------------------------------------------
vector <ofPoint> testApp::ildaTranslate(vector <ofPoint> points){
    
    float mappingFactor = 0.05;
    for (int i = 0; i < points.size(); i++){
        float margin = (HEIGHT-points[i].y)*mappingFactor;
        float interval = WIDTH - margin*2;
        points[i].x = ofMap(points[i].x, 0, WIDTH, margin, interval+margin);
        
        //offsets
        points[i].x = points[i].x + X_OFFSET;
        points[i].y = points[i].y + Y_OFFSET;
        
        points[i].x = points[i].x / (float) ofGetWidth();
        points[i].y = points[i].y / (float) ofGetHeight();
    }
    return points;
}

// ---------------------------------------------------------------
vector<ofPoint> testApp::getLetterDrawPoints(vector<ofPoint> letter, int xMove, int yMove){
    vector<ofPoint> movedLetter;
    for (int i = 0; i < letter.size(); i++){
        movedLetter.push_back(ofPoint(letter[i].x+xMove, letter[i].y+yMove));
    }
    return movedLetter;
}

// ---------------------------------------------------------------
vector<ofPoint> testApp::scaleLetter(vector<ofPoint> letter, int scaleFactor){
    for (int i = 0; i < letter.size(); i++){
        letter[i].x = letter[i].x*scaleFactor;
        letter[i].y = letter[i].y*scaleFactor;
    }
    return letter;
}

// ---------------------------------------------------------------
vector<ofPoint> testApp::getScoreVector(int score){
    
    // SCORE AS REAL NUMBERS
    if (score == 0) return zero;
    else if (score == 1) return one;
    else if (score == 2) return two;
    else if (score == 3) return three;
    else if (score == 4) return four;
    else if (score == 5) return five;
}

