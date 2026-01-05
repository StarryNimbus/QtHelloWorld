#include "MainWindow.h"
#include <QLabel>
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("QtHelloWorld");
  setGeometry(0, 0, 800, 800);

  // Example menu bar
  // QT behaves differently on Mac than on Windows/Linux when it comes to menu
  // bars. Toggle setNativeMenuBar depending on OS.
  QMenuBar *menuBar = new QMenuBar(this);
  QMenu *fileMenu = menuBar->addMenu("File");
  fileMenu->addAction("Exit", this, &QMainWindow::close);
  menuBar->setNativeMenuBar(false);
  setMenuBar(menuBar);

  // Example central widget
  QLabel *label = new QLabel("Hello World!", this);
  label->setAlignment(Qt::AlignCenter);
  setCentralWidget(label);

  // Example status bar
  QStatusBar *statusBar = new QStatusBar(this);
  statusBar->showMessage("Ready");
  setStatusBar(statusBar);
}
