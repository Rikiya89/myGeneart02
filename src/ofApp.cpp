#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0); // Set background color to black
    ofSetFrameRate(30); // Set frame rate to 30
    ofEnableSmoothing(); // Enable smoothing
    ofEnableAlphaBlending(); // Enable alpha blending for smooth transitions between colors
    ofSetLineWidth(0.8); // Set line width
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef(); // Get elapsed time
    int numPoints = 400; // Number of points in the pattern
    float maxDistance = 100; // Maximum distance for connecting lines

    for (int i = 0; i < numPoints; i++) {
        // Calculate position using Perlin noise
        float x = ofGetWidth() / 2 + ofSignedNoise(time * 0.1, i * 0.04) * 400;
        float y = ofGetHeight() / 2 + ofSignedNoise(time * 0.15, i * 0.07) * 400;

        // Draw each point
        ofColor pointColor = ofColor::fromHsb(i * 0.3 + time * 10, 255, 255);
        ofSetColor(pointColor);
        ofDrawCircle(x, y, 3);

        // Draw lines connecting close points
        for (int j = i + 1; j < numPoints; j++) {
            float x2 = ofGetWidth() / 2 + ofSignedNoise(time * 0.1, j * 0.04) * 400;
            float y2 = ofGetHeight() / 2 + ofSignedNoise(time * 0.15, j * 0.07) * 400;
            
            float distance = ofDist(x, y, x2, y2);
            if (distance < maxDistance) {
                ofColor lineColor = ofColor::fromHsb(180 + i * 0.3 + time * 10, 255, 255, ofMap(distance, 0, maxDistance, 255, 0));
                ofSetColor(lineColor);
                ofDrawLine(x, y, x2, y2);
            }
        }
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
