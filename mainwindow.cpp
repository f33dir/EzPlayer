#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "mp3manager.h"
#include "mp3filemanager.h"
#include "taglib/taglib/tag.h"
#include "bass/bass.h"
#include <string>
#include "mp3player.h"
#include <thread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_saveButton_clicked()
{
    fManager.saveAll(manager);
}

void MainWindow::on_loadButton_clicked()
{
    ui->songList->clear();
    fManager.loadFilepaths(manager);
    fManager.loadSongs(manager);
    updateList();
}

void MainWindow::on_addPathButton_clicked()
{
    string path =  ui->pathLine->text().toStdString();
    vector<string>* filepathes = manager.getFilepathContainer();
    bool g=true;
    for(int i = 0;i<filepathes->size();i++){
        if(path == (*(filepathes))[i]){
            g = false;
        }
    };
    if(g){
        manager.addDirectory(path);}
    manager.rescanDirectories();
    updateList();
}
void MainWindow::on_songList_doubleClicked(const QModelIndex &index){
    player.playSong(currentSongs[index.row()]);
}
void MainWindow::updateList(){
    ui->songList->clear();
    currentSongs = manager.getAll();
    for (int i = 0;i<currentSongs.size();i++){
        ui->songList->addItem(QString::fromStdString(currentSongs[i].getName()));
    }
}

void MainWindow::on_searchButton_clicked()
{
    string year = ui->yearLine->text().toStdString();
    string name = ui->nameLine->text().toStdString();
    string album = ui->albumLine->text().toStdString();
    string artist = ui->artistLine->text().toStdString();
    string genre = ui->genreLine->text().toStdString();
    vector<song>* output = manager.getDatabase();
    vector<song> temp = manager.search(name,"",year,genre, artist ,album);
    *manager.getDatabase() = temp;
    updateList();
}

void MainWindow::on_playButton_clicked()
{
    player.playPause();
}