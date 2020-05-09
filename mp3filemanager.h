#ifndef MP3FILEMANAGER_H
#define MP3FILEMANAGER_H
#include "song.h"
#include "mp3manager.h"
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
class mp3FileManager{
public:
    static void loadFilepaths(mp3Manager& path);//+
    static vector<song> getSongs(vector<string>);
    static void saveAll(mp3Manager&);//+
    static void loadSongs(mp3Manager&);//+
};
#endif // MP3FILEMANAGER_H
