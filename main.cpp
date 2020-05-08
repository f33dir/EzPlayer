#include <iostream>
#include "mp3manager.h"
#include "mp3filemanager.h"
#include "taglib/taglib/tag.h"
#include "bass/bass.h"
#include <string>
using namespace std;
int main(){
    BASS_Init(-1,44100,0,0,NULL);
    mp3Manager a;
    a.addDirectory("/home/f33dir/build-template-Desktop-u041fu043e u0443u043cu043eu043bu0447u0430u043du0438u044e/mp3folder/");
    a.rescanDirectories();
    cout<<a.getAll()[0].getFilename();
    BASS_StreamCreateFile(false,a.getAll()[0].getFilename().c_str(),0,0,NULL);
    BASS_Free();
}
