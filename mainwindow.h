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
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void slotTimerAlarm();
private slots:
    void on_volumeSlider_valueChanged(int value);

private slots:
    void on_positionSlider_sliderMoved(int position);

private slots:
    void on_positionSlider_valueChanged(int value);

private slots:
    void on_positionSlider_sliderReleased();

private slots:
    void on_positionSlider_sliderPressed();

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
    void updateList(vector<song>);
    vector<song> currentSongs;
    QTimer *timer;
    void mySliderValueChanged(int newPos);
};
#endif // MAINWINDOW_H
