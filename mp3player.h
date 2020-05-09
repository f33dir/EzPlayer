#ifndef MP3PLAYER_H
#define MP3PLAYER_H
#include "song.h"
#include "bass/bass.h"
#include <thread>
class mp3Player{
    song _current;
    HSTREAM _stream;
    thread _thr;
public:
    ~mp3Player();
    bool initialize();
    void importSong(song);
    song isPlaying();
    void switchPlaying();
    void setPosition();
    void startPlaying();
    void play();
    void stop();
};
#endif // MP3PLAYER_H
