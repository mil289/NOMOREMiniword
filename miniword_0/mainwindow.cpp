#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
{
  this->resize(600, 600);
  /*
   * auto htextedit = new HTextEdit(this);
  mHTextEdit = htextedit;
  setCentralWidget(mHTextEdit);
  */
  setupMenuBar();
}

void
MainWindow::setupMenuBar()
{
    /*



    */
  QMenu* menu = menuBar()->addMenu(tr("&File"));
  //这句话的功能：创建MenuBar（返回menuBar）,在其上创建menu（file）（返回menuAction
  menu->addAction(tr("Save "), this, &MainWindow::save);
  menu->addAction(tr("Load ..."), this, &MainWindow::load);
  menu->addSeparator();
  menu->addAction(tr("&Quit"), this, &QWidget::close);
  //为何有些带&
  //多一条下划线
}
MainWindow::~MainWindow()
{
}
void
MainWindow::save()
{
}
void
MainWindow::load()
{

}

