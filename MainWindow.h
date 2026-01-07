#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QString>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(bool isDarkMode, QWidget *parent = nullptr);

private:
  QMenuBar *CreateMenuBar();
  QLabel *CreateTitle();
  QLabel *CreateSubtitle();
  QLabel *CreateCenterImage();

  bool m_isDarkMode;
  QString m_textColor; // based on m_isDarkMode
  QString m_titleText;
};

#endif // MAINWINDOW_H
