/*
 * \file frame.cc
 * \desc The gui frame for AMT-MOD
 */
#include "mod/gui/frame.h"

namespace mod {

Frame::Frame() {
  CreateMapCanvas();
  CreateMenus();
  setWindowTitle(tr("AMT-MOD"));
}

void Frame::CreateMapCanvas() {
  web_view_ = new QWebEngineView();
  setCentralWidget(web_view_);
  //web_view_->load(QUrl("http://api.map.baidu.com/staticimage?center=116.38,39.90&zoom=12&width=1024&height=768"));
  web_view_->load(QUrl("http://api.map.baidu.com/staticimage?center=-122.49,48.50&zoom=11&width=1024&height=768"));
}

void Frame::CreateMenus() {
  file_menu_ = menuBar()->addMenu(tr("&File"));
  open_act_ = new QAction(tr("&Open..."), this);
  file_menu_->addAction(open_act_);

  tool_menu_ = menuBar()->addMenu(tr("&Tool"));
  txt2shp_act_ = new QAction(tr("&Txt2Shp..."), this);
  tool_menu_->addAction(txt2shp_act_);
  connect(txt2shp_act_, &QAction::triggered, this, &Frame::Txt2Shp);
}

void Frame::Txt2Shp() {
}

}  // namespace mod
