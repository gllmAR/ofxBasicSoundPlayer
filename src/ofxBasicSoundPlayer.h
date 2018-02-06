/*
 * ofxBasicSoundPlayer.h
 *
 *  Created on: 25/07/2012
 *      Author: arturo
 */

#pragma once
#include "ofSoundPlayer.h"
#include "ofBaseTypes.h"
#include "ofConstants.h"
#include "ofSoundBuffer.h"
#include "ofThread.h"

#include "ofSoundStream.h"
#include "ofEvents.h"
#include "ofxSoundFile.h"

class ofxBasicSoundPlayer: public ofBaseSoundPlayer {//public ofBaseSoundOutput {
public:
	ofxBasicSoundPlayer();
	virtual ~ofxBasicSoundPlayer();
	bool load(const std::filesystem::path& filePath, bool stream = false) override;
	void unload() override;
	void play() override;
	void stop() override;

	void setVolume(float vol) override;
	void setPan(float vol) override; // -1 = left, 1 = right
	void setSpeed(float spd) override;
	void setPaused(bool bP)override;
	void setLoop(bool bLp) override;
	void setMultiPlay(bool bMp) override;
	void setPosition(float pct) override; // 0 = start, 1 = end;
	void setPositionMS(int ms) override;
	
	float getPosition() const override;
	int getPositionMS() const override;
	bool isPlaying() const override;
	float getSpeed() const override;
	float getPan() const override;
	bool isLoaded() const override;
	float getVolume() const override;
	bool getIsLooping() const;
	unsigned long getDurationMS();

    //looping selection function
    void set_loop_selection(bool b);
    bool loop_selection;
    void set_loop_in(float f);
    float loop_in=0;
    void set_loop_out(float f);
    float loop_out=1;
    
	ofSoundBuffer & getCurrentBuffer();

	static void setMaxSoundsTotal(int max);
	static void setMaxSoundsPerPlayer(int max);
	void setMaxSounds(int max);

	ofEvent<ofSoundBuffer> newBufferE;

    const ofxSoundFile& getSoundFile() const {return soundFile;}

	void audioOut(ofSoundBuffer& outputBuffer);
private:
	void audioOutBuffersChanged( int nFrames, int nChannels, int sampleRate );
	void updatePositions(int numFrames);
	
	int playerSampleRate, playerNumFrames, playerNumChannels;
	
	static int maxSoundsTotal;
	static int maxSoundsPerPlayer;
	int maxSounds;
	float volume;
	ofSoundBuffer buffer, resampledBuffer;
	ofxSoundFile soundFile;
	bool streaming;
	bool bIsPlaying;
	bool multiplay;
	bool bIsLoaded;
	bool loop;
	float speed;
	float pan;
	std::vector<float> relativeSpeed;
	std::vector<unsigned int> positions;
	std::vector<float> volumesLeft;
	std::vector<float> volumesRight;
	std::mutex mtx;
};


