#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <iostream>
#include "mp3manager.h"
#include "mp3filemanager.h"
#include "taglib/taglib/tag.h"
#include "bass/bass.h"
#include <string>
#include "mp3player.h"
#include <thread>
#include <vector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_playButton_clicked();

private slots:
    void on_searchButton_clicked();

private slots:
    void on_songList_doubleClicked(const QModelIndex &index);

private slots:
    void on_addPathButton_clicked();

private slots:
    void on_loadButton_clicked();

private slots:
    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    mp3FileManager fManager;
    mp3Manager manager;
    mp3Player player;
    void updateList();
    vector<song> currentSongs;
    QTimer *timer;
    void slotTimerAlarm();
};
#endif // MAINWINDOW_H
