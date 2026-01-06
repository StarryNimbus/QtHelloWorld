#include "MainWindow.h"
#include <QLabel>
#include <QMenuBar>
#include <QStatusBar>
#include <QVBoxLayout>

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

  // Example "Hello World" label
  QLabel *label = new QLabel("Hello World!", this);
  label->setAlignment(Qt::AlignCenter);

  // Example "Hello World" sublabel
  QLabel *subLabel = new QLabel("Est. 2026", this);
  subLabel->setAlignment(Qt::AlignCenter);

  // Example "Hello World" image
  QLabel *image = new QLabel(this);
  QPixmap pixmap(":/images/globe.png");
  pixmap =
      pixmap.scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  image->setPixmap(pixmap);
  image->setFixedSize(250, 250);

  // Central widget to encapsulate the verticalLayout
  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QVBoxLayout *verticalLayout = new QVBoxLayout(centralWidget);
  verticalLayout->setAlignment(Qt::AlignCenter);
  verticalLayout->addStretch();
  verticalLayout->addWidget(label);
  verticalLayout->addWidget(image);
  verticalLayout->addWidget(subLabel);
  verticalLayout->addStretch();

  // Example status bar
  QStatusBar *statusBar = new QStatusBar(this);
  statusBar->showMessage("Ready");
  setStatusBar(statusBar);
}
