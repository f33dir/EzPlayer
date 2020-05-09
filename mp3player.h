#ifndef MP3PLAYER_H
#define MP3PLAYER_H
#include "song.h"
#include "bass/bass.h"
class mp3Player{
    song _current;
    HSTREAM _stream;
public:
    ~mp3Player();
    bool initialize();
    void importSong(song);
    song isPlaying();
    void switchPlaying();
    void setPosition();
    DWORD startPlaying();
};
#endif // MP3PLAYER_H
