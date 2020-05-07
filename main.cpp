#include <iostream>
#include "mp3manager.h"
#include "mp3filemanager.h"
using namespace std;

int main(){
    mp3Manager a;
    a.addDirectory("/home/f33dir/build-template-Desktop-u041fu043e u0443u043cu043eu043bu0447u0430u043du0438u044e/mp3folder/");
    a.rescanDirectories();
    cout<<a.getAll()[0].getFilename();
}
