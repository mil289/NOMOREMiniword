#ifndef HTEXTCURSOR_H
#define HTEXTCURSOR_H

#include "hrendercontroller.h"
#include <QObject>
#include <QWidget>
class HTextCursor : public QWidget
{
  Q_OBJECT
private:
  QWidget* mParent;
  QTimer* BlinkTimer;
  void blink();
  void Closeblink();
  HRenderController* mController;
  QColor mColor1 = QColor(128, 128, 255, 128);
  QColor mColor2 = QColor(128, 128, 255, 0);
  QColor mColor3 = QColor(198, 40, 40, 128);
  QColor mCurColor;
  void paintEvent(QPaintEvent* event) override;
  //!将靠后的设置为主游标
  void setCursor(int row1, int column1, int row2, int column2);

  QList<QRect> renderAera;
  QPair<int, int> priCursor;
  QPair<int, int> altCursor;

public:
  HTextCursor(QWidget* parent, HRenderController* controller);
  void setFirstPos(int row, int column);
  void setSecondPos(int row, int column);
  void setPos(int row1, int column1, int row2, int column2);
  void setPos(int row1, int column1);
  QPair<int, int> getPriCursor() { return priCursor; }
  QPair<int, int> getAltCursor() { return altCursor; }

public slots:
  void toggleBlink();
};

#endif // HTEXTCURSOR_H

