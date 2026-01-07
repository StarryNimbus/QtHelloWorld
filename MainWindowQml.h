#ifndef MAINWINDOWQML_H
#define MAINWINDOWQML_H

#include <QObject>
#include <QQuickView>

class MainWindowQml : public QObject {
  Q_OBJECT

public:
  MainWindowQml(bool isDarkMode);
  void show() const;

private:
  QQuickView *Build() const;

  QQuickView *m_view;
  bool m_isDarkMode;
};

#endif // MAINWINDOWQML_H
