#include "mp3manager.h"
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include "mp3filemanager.h"
using namespace std;
mp3Manager::mp3Manager(){
};
//
vector<song> mp3Manager::getAll(){
    return  _database;
}
//
vector<song> mp3Manager::getArtistList(vector<song> input, string artist){
    vector<song> output;
    for(int i = 0;i<input.size();i++){
        if(input[i].getArtist()== artist){
            output.push_back(input[i]);
        }
    };
    return output;
}
//
vector<song> mp3Manager::getAlbumList(vector<song> input, string album){
    vector<song> output;
    for(int i = 0;i<input.size();i++){
        if(input[i].getAlbum()== album){
            output.push_back(input[i]);
        }
    };
    return output;
}
//
vector<song> mp3Manager::getGenreList(vector<song> input, string genre){
    vector<song> output;
    for(int i = 0;i<input.size();i++){
        if(input[i].getGenre()== genre){
            output.push_back(input[i]);
        }
    };
    return output;
}
//
vector<song> mp3Manager::getYearList(vector<song> input, string year){
    vector<song> output;
    for(int i = 0;i<input.size();i++){
        if(input[i].getYear()== year){
            output.push_back(input[i]);
        }
    };
    return output;
}
//
vector<song> mp3Manager::getFilenameList(vector<song> input, string Filename){
    vector<song> output;
    for(int i = 0;i<input.size();i++){
        if(input[i].getFilename()== Filename){
            output.push_back(input[i]);
        }
    };
    return output;
}
//
vector<song> mp3Manager::getNameList(vector<song> input, string name){
    vector<song> output;
    for(int i = 0;i<input.size();i++){
        if(input[i].getName()== name){
            output.push_back(input[i]);
        }
    };
    return output;
}




