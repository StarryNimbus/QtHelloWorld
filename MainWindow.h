#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(bool isDarkMode, QWidget *parent = nullptr);

private:
  bool m_isDarkMode{false};
};

#endif // MAINWINDOW_H
