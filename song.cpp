#include "song.h"
void song::dummyUpdateSongClass(string path){
    ifstream file(path);
    this->_filename = path;
    getline(file,this->_name);
    getline(file,this->_genre);
    getline(file,this->_year);
    getline(file,this->_artist);
    getline(file,this->_album);
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
