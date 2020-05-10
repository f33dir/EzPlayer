#include <iostream>
#include "mp3manager.h"
#include "mp3filemanager.h"
#include "taglib/taglib/tag.h"
#include "bass/bass.h"
#include <string>
#include "mp3player.h"
#include <thread>
#include <QGuiApplication>
#include <QApplication>
#include "mainwindow.h"
using namespace std;
int main(int argc, char *argv[]){
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
