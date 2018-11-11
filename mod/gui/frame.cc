/*
 * \file frame.cc
 * \desc The gui frame for AMT-MOD
 */
#include "mod/gui/frame.h"

#include <sstream>

#include <QDialog>
#include <QFileDialog>

namespace {
// The map canvas width
int kMapCanvasWidth = 1024;
// The map canva height
int kMapCanvasHeight = 768;
// The AMT-MOD Frame width
int kFrameWidth = 1200;
// The AMT-MOD Frame height
int kFrameHeight = 768;
// The map api url, AMT-MOD use Baidu Map API
std::string kMapApiUrl = "http://api.map.baidu.com/staticimage?";
// The map max zoom level
int kMaxZoom = 18;
// The map min zoom level
int kMinZoom = 11;
// The map move span
double kMapMoveSpan = 0.1;
}  // namespace

namespace mod {

Frame::Frame() : zoom_level_(12), center_lon_(-122.49), center_lat_(48.50) {
  main_layout_ = new QBoxLayout(QBoxLayout::LeftToRight, this);
  setLayout(main_layout_);

  // create map canvas
  CreateMapCanvas();
  // create menu
  CreateMenus();

  setMinimumSize(kFrameWidth, kFrameHeight);
  setWindowTitle(tr("AMT-MOD BJUT"));

  // update display
  Update();
}

void Frame::CreateMapCanvas() {
  web_view_ = new QWebEngineView(this);
  web_view_->setMinimumSize(kMapCanvasWidth, kMapCanvasHeight);
  web_view_->setMaximumSize(kMapCanvasWidth, kMapCanvasHeight);
  main_layout_->addWidget(web_view_);
}


void Frame::CreateMenus() {
  // file menu
  file_menu_ = menuBar()->addMenu(tr("&File"));
  open_act_ = new QAction(tr("&Open Layer..."), this);
  file_menu_->addAction(open_act_);
  connect(open_act_, &QAction::triggered, this, &Frame::OpenLayer);

  // view menu
  view_menu_ = menuBar()->addMenu(tr("&View"));
  left_act_ = new QAction(tr("Left"), this);
  connect(left_act_, &QAction::triggered, this, &Frame::MoveLeft);

  view_menu_->addAction(left_act_);
  right_act_ = new QAction(tr("Right"), this);
  connect(right_act_, &QAction::triggered, this, &Frame::MoveRight);

  view_menu_->addAction(right_act_);
  up_act_ = new QAction(tr("Up"), this);
  connect(up_act_, &QAction::triggered, this, &Frame::MoveUp);

  view_menu_->addAction(up_act_);
  down_act_ = new QAction(tr("Down"), this);
  connect(down_act_, &QAction::triggered, this, &Frame::MoveDown);

  view_menu_->addAction(down_act_);
  zoomin_act_ = new QAction(tr("ZoomIn"), this);
  connect(zoomin_act_, &QAction::triggered, this, &Frame::ZoomIn);

  view_menu_->addAction(zoomin_act_);
  zoomout_act_ = new QAction(tr("ZoomOut"), this);
  view_menu_->addAction(zoomout_act_);
  connect(zoomout_act_, &QAction::triggered, this, &Frame::ZoomOut);


  // tool menu
  tool_menu_ = menuBar()->addMenu(tr("&Tool"));
  txt2shp_act_ = new QAction(tr("&Txt2Shp..."), this);
  tool_menu_->addAction(txt2shp_act_);
  connect(txt2shp_act_, &QAction::triggered, this, &Frame::Txt2Shp);
}

void Frame::OpenLayer() {
  auto fileName = QFileDialog::getOpenFileName(
              this,
              tr("Open Layer"),
              "/",
              tr("Shp Files (*.shp)"));
}

void Frame::MoveLeft() {
  this->center_lon_ -= kMapMoveSpan;
  Update();
}

void Frame::MoveRight() {
  this->center_lon_ += kMapMoveSpan;
  Update();
}

void Frame::MoveUp() {
  this->center_lat_ += kMapMoveSpan;
  Update();
}

void Frame::MoveDown() {
  this->center_lat_ -= kMapMoveSpan;
  Update();
}

void Frame::ZoomIn() {
  if (zoom_level_ >= kMaxZoom) return;
  zoom_level_++;
  Update();
}

void Frame::ZoomOut() {
  if (zoom_level_ <= kMinZoom) return;
  zoom_level_--;
  Update();
}

void Frame::Txt2Shp() {
}

void Frame::Update() {
  // Step1: update map canvas
  std::stringstream ss;
  ss << kMapApiUrl
     << "width=" << kMapCanvasWidth
     << "&height=" << kMapCanvasHeight
     << "&zoom=" << zoom_level_
     << "&center=" << center_lon_ << "," << center_lat_;
  web_view_->load(QUrl(ss.str().c_str()));

  // Step2: update POD/Roads

  // Step3: update trajectories
}

}  // namespace mod
