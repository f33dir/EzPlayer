#ifndef SONG_H
#define SONG_H
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <tag.h>
using namespace std;
class song{
public:
    string _filename;
    string _name;
    string _genre;
    string _year;
    string _artist;
    string _album;
    song(string,string,string,int,string,string);
    song(string);
    song();
    string getGenre(){return _genre;}
    string getName(){return _name;}
    string getArtist(){return _artist;}
    string getYear(){return _year;}
    string getFilename(){return _filename;}
    string getAlbum(){return _album;}
    string serialize();//+
    void deserialize(ifstream&);//+
    void dummyUpdateSongClass(string);//+
    void updateSongClass(string);//+
};
#endif // SONG_H
