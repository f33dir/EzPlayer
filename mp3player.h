#ifndef MP3PLAYER_H
#define MP3PLAYER_H
#include "song.h"
#include "bass/bass.h"
#include <thread>
class mp3Player{
    song _current;
    HSTREAM _stream;
    thread _thr;
    int songNumber;
    vector<song> queue;
    void resumeStream();
    void pauseStream();
    bool initializeEngine();
    void stopStream();
    void initStream();
    void startThread();
public:
    ~mp3Player();
    mp3Player();
    void playSong(song);
    song isPlaying();
    void setPosition(int);
    void restart();
    void playPause();
    int getCurrentTime();
    int getTotalTime();
    bool isActive();
    void setVolume(int);
};
#endif // MP3PLAYER_H
