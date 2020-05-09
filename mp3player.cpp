#include "mp3player.h"
#include "bass/bass.h"
#include <thread>
#include <chrono>
mp3Player::~mp3Player(){
    if(_thr.joinable()){};
    BASS_Free();
}
bool mp3Player::initialize(){
    return BASS_Init(-1,44100,0,0,0);
}
void mp3Player::importSong(song input){
    _stream =  BASS_StreamCreateFile(false,input.getFilename().c_str(),0,0,0);
    _current = input;
}
void mp3Player::startPlaying(){
    BASS_ChannelPlay(_stream,TRUE);
    while (BASS_ChannelIsActive(_stream) != BASS_ACTIVE_STOPPED){
        this_thread::sleep_for(std::chrono::milliseconds(200));
    };
}
void mp3Player::startThread(){
    this->_thr = thread(&mp3Player::startPlaying,this);
}
void mp3Player::stopThread(){
    _thr.join();
}
void mp3Player::pause(){
    BASS_ChannelPause(_stream);
}
void mp3Player::resume(){
    BASS_ChannelPlay(_stream,false);
}
void mp3Player::restart(){
    BASS_ChannelPlay(_stream,true);
}
void mp3Player::stop(){
    BASS_ChannelStop(_stream);
}
