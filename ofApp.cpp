#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofBackground(255, 255, 255);
    
    box2d.init();
    box2d.setGravity(0, 20);
    box2d.createBounds();
    box2d.setFPS(60.0);
    ofSetCircleResolution(64);
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetLineWidth(2.0);
    
    ofSetColor(255, 216, 112);
    for(int i = 0; i < circles.size(); i++){
        circles[i].get()->draw();
    }
    
    ofSetColor(178, 247, 150);
    for(int i = 0; i < boxes.size(); i++){
        boxes[i].get()->draw();
    }
    
    ofNoFill();
    ofSetLineWidth(20.0);
    ofSetColor(237, 161, 175);
    for(int i = 0; i < edges.size(); i++){
        edges[i].get()->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c'){
        float r = ofRandom(15, 40);
        circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(9.0, 0.93, 0.5);
        circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r);
    }
    if(key == 'b'){
        float w = ofRandom(10, 50);
        float h = ofRandom(10, 50);
        boxes.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
        boxes.back().get()->setPhysics(9.0, 0.93, 0.5);
        boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    lines.back().addVertex(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    lines.push_back(ofPolyline());
    lines.back().addVertex(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    shared_ptr<ofxBox2dEdge> edge = shared_ptr<ofxBox2dEdge>(new ofxBox2dEdge);
    lines.back().simplify();
    for(int i = 0; i < lines.back().size(); i++){
        edge.get()->addVertex(lines.back()[i]);
    }
    edge.get()->create(box2d.getWorld());
    edges.push_back(edge);
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
