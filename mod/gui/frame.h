/*
 * \file frame.h
 * \desc The gui frame for AMT-MOD
 */
#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QWebEngineView>

namespace mod {

class Frame : public QMainWindow {
  Q_OBJECT

 public:
  Frame();

 protected:
  void CreateMenus();
  void CreateMapCanvas();
  void Txt2Shp();

  QMenu *file_menu_;
  QAction *open_act_;

  QMenu *tool_menu_;
  QAction *txt2shp_act_;

  QWebEngineView *web_view_;
};

}  // namespace mod
