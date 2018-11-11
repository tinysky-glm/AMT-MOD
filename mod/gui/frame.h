/*
 * \file frame.h
 * \desc The gui frame for AMT-MOD
 */
#pragma once

#include <QBoxLayout>
#include <QMainWindow>
#include <QMenuBar>
#include <QWebEngineView>

namespace mod {

class Frame : public QMainWindow {
  Q_OBJECT

 public:
  Frame();

 protected:
  void CreateMapCanvas();
  void CreateMenus();

  void OpenLayer();
  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void MoveDown();
  void ZoomIn();
  void ZoomOut();

  void Txt2Shp();

  void Update();

  // The layout
  QBoxLayout *main_layout_;

  // The file menu
  QMenu *file_menu_;
  QAction *open_act_;

  // The view menu
  QMenu *view_menu_;
  QAction *left_act_, *right_act_, *up_act_, *down_act_, *zoomin_act_, *zoomout_act_;

  // The tool menu
  QMenu *tool_menu_;
  QAction *txt2shp_act_;

  // The map canvas
  QWebEngineView *web_view_;
  int zoom_level_;
  double center_lon_, center_lat_;
};

}  // namespace mod
