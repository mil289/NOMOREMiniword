#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QMenu* mainWindowMenu;
    QMenu* dockWidgetMenu;
    void setupMenuBar();
    void save();
    void load();
    //HTextEdit* mHTextEdit;
    //void resizeEvent(QResizeEvent* event) { mHTextEdit->resize(event->size()); }
};

#endif // MAINWINDOW_H
