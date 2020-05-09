#include "mp3player.h"
#include "bass/bass.h"
#include <thread>
#include <chrono>
mp3Player::~mp3Player(){
    BASS_Free();
}
bool mp3Player::initialize(){
    return BASS_Init(-1,44100,0,0,0);

}
void mp3Player::importSong(song input){
    _stream =  BASS_StreamCreateFile(false,input.getFilename().c_str(),0,0,0);
    _current = input;
}
DWORD mp3Player::startPlaying(){
    BASS_ChannelPlay(_stream,TRUE);
//    while (BASS_ChannelIsActive(_stream) != BASS_ACTIVE_STOPPED) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(200));
//    };
}
///
