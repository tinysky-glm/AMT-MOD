/*
 * \file main.cc
 * \desc The gui main entry
 */
#include <QApplication>
#include <iostream>
#include "mod/gui/frame.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    mod::Frame frame;
    frame.show();
    return app.exec();
}
