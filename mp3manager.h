#ifndef MP3MANAGER_H
#define MP3MANAGER_H
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include "song.h"
using namespace std;
class mp3Manager{
    vector<song> _database;
    vector<string> _filepathContainer;

public:
    vector<song> getArtistList(vector<song>,string artist);//+
    vector<song> getNameList(vector<song>, string name);//+
    vector<song> getFilenameList(vector<song>, string filename);//+
    vector<song> getGenreList(vector<song>,string genre);//+
    vector<song> getYearList(vector<song>, string year);//+
    vector<song> getAlbumList(vector<song>,string album);//+
    mp3Manager();
    vector<song>* getDatabase(){return &_database;}//+
    vector<string>* getFilepathContainer(){return &_filepathContainer;}//+
    vector<song> getAll();//+
    void addDirectory(string);//+
    void rescanDirectories();//+
    vector<song> search(string,string,string,string,string,string);
};

#endif // MP3MANAGER_H
