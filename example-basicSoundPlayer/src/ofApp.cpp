#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetLogLevel(OF_LOG_VERBOSE);
  
        soundStream.printDeviceList();
        
        ofSoundStreamSettings settings;
        
        // if you want to set the device id to be different than the default:
        //
        //	auto devices = soundStream.getDeviceList();
        //	settings.setOutDevice(devices[3]);
        
        // you can also get devices for an specific api:
        //
        //	auto devices = soundStream.getDeviceList(ofSoundDevice::Api::PULSE);
        //	settings.setOutDevice(devices[0]);
        
        // or get the default device for an specific api:
        //
        // settings.api = ofSoundDevice::Api::PULSE;
        
        // or by name:
        //
        //	auto devices = soundStream.getMatchingDevices("default");
        //	if(!devices.empty()){
        //		settings.setOutDevice(devices[0]);
        //	}
        
#ifdef TARGET_LINUX
        // Latest linux versions default to the HDMI output
        // this usually fixes that. Also check the list of available
        // devices if sound doesn't work
        auto devices = soundStream.getMatchingDevices("default");
        if(!devices.empty()){
            settings.setOutDevice(devices[0]);
        }
#else
        auto devices = soundStream.getDeviceList();
        settings.setOutDevice(devices[1]);
#endif
        
        
        settings.setOutListener(this);
        settings.sampleRate = 44100;
        settings.numOutputChannels = 2;
        settings.numInputChannels = 0;
        settings.bufferSize = 512;
        soundStream.setup(settings);
        
    
        player.load("sounds/lasers.wav");
        

    
        gui.setup();
        gui.add(pan.set("PAN", 0, -1,1));
        pan.addListener(this, &ofApp::panChanged);
        gui.add(speed.set("SPEED", 1, -2,2));
        speed.addListener(this, &ofApp::speedChanged);
        ofBackground(0);
 
    player.play();
    player.setLoop(1);
}
//--------------------------------------------------------------
void ofApp::speedChanged(float&f){
    
    player.setSpeed(speed);
}
//--------------------------------------------------------------
void ofApp::panChanged(float&f){
    
    player.setPan(pan);
}
//--------------------------------------------------------------
void ofApp::update(){

 

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
}
//--------------------------------------------------------------

void ofApp::audioOut(ofSoundBuffer & output){
    
        player.audioOut(output);
    
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
