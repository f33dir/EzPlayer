#include <iostream>
#include "mp3manager.h"
#include "mp3filemanager.h"
#include "taglib/taglib/tag.h"
#include "bass/bass.h"
#include <string>
#include "mp3player.h"
using namespace std;
int main(){
    BASS_Init(-1,44100,0,0,0);
    mp3Manager a;
    mp3Player b;
    a.addDirectory("/home/f33dir/build-template-Desktop-u041fu043e u0443u043cu043eu043bu0447u0430u043du0438u044e/mp3folder/");
    a.rescanDirectories();
    mp3FileManager::saveAll(a);
    a.clearData();
    mp3FileManager::loadFilepaths(a);
    mp3FileManager::loadSongs(a);
    cout<<a.getAll()[0].getFilename();
    b.initialize();
    b.importSong(a.getAll()[0]);
    b.startPlaying();
}
