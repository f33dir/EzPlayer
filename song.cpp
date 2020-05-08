#include "song.h"
#include "taglib/taglib/tag.h"
#include <tag.h>
#include <fileref.h>
#include <tpropertymap.h>
void song::dummyUpdateSongClass(string path){
    ifstream file(path);
    this->_filename = path;
    getline(file,this->_name);
    getline(file,this->_genre);
    getline(file,this->_year);
    getline(file,this->_artist);
    getline(file,this->_album);
}
void song::updateSongClass(string path){
    TagLib::FileRef f(path.c_str());
    if(!f.isNull()&& f.tag()){
    _filename = path;
    TagLib::Tag *file = f.tag();
    this->_artist = string(file->artist().toCString());
    this->_album = string(file->album().toCString());
    this->_genre = string(file->genre().toCString());
    this->_name = string(file->title().toCString());
    this->_year = to_string(file->year());
}
}
song::song(){

}
string song::serialize(){
    return _filename+'\n'+
           _name+'\n'+
           _genre+'\n'+
           _year+'\n'+
           _artist+'\n'+
           _album+'\n';
}
void song::deserialize(ifstream & file){
    getline(file,this->_filename);
    getline(file,this->_name);
    getline(file,this->_genre);
    getline(file,this->_year);
    getline(file,this->_artist);
    getline(file,this->_album);
}
