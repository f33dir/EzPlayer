#include "mp3player.h"
#include "bass/bass.h"
#include <thread>
#include <chrono>
mp3Player::~mp3Player(){
    this->stopStream();
    if(_thr.joinable()){
        _thr.join();
    };
    BASS_Free();
}
bool mp3Player::initializeEngine(){
    return BASS_Init(-1,44100,0,0,0);
}
void mp3Player::playSong(song input){
    this->stopStream();
    if (_thr.joinable()){
        _thr.join();
    }
    _stream =  BASS_StreamCreateFile(false,input.getFilename().c_str(),0,0,0);
    _current = input;
    startThread();
}
void mp3Player::initStream(){
    BASS_ChannelPlay(_stream,TRUE);
    while (BASS_ChannelIsActive(_stream) != BASS_ACTIVE_STOPPED){
        this_thread::sleep_for(std::chrono::milliseconds(99));
    };
}
void mp3Player::startThread(){
    this->_thr = thread(&mp3Player::initStream,this);
}
void mp3Player::pauseStream(){
    BASS_ChannelPause(_stream);
}
void mp3Player::resumeStream(){
    BASS_ChannelPlay(_stream,false);
}
void mp3Player::restart(){
    BASS_ChannelPlay(_stream,true);
}
void mp3Player::stopStream(){
    BASS_ChannelStop(_stream);
}
void mp3Player::playPause(){
    if(BASS_ChannelIsActive(_stream) == BASS_ACTIVE_PLAYING){
        pauseStream();
    }
    else if(BASS_ChannelIsActive(_stream) == BASS_ACTIVE_PAUSED){
        resumeStream();
    }
}
mp3Player::mp3Player(){
    initializeEngine();
}
