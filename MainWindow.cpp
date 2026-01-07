#include "MainWindow.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QVBoxLayout>

MainWindow::MainWindow(bool isDarkMode, QWidget *parent)
    : QMainWindow(parent), m_isDarkMode(isDarkMode),
      m_textColor(m_isDarkMode ? "white" : "black") {
  setWindowTitle("QtHelloWorld");
  setGeometry(0, 0, 800, 800);

  // Top of app
  QMenuBar *menuBar = CreateMenuBar();
  setMenuBar(menuBar);

  // App content
  // Central widget to encapsulate a verticalLayout which contains the title,
  // subtitle, and image
  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QLabel *title = CreateTitle();
  QLabel *subtitle = CreateSubtitle();
  QLabel *image = CreateCenterImage();

  QVBoxLayout *verticalLayout = new QVBoxLayout(centralWidget);
  verticalLayout->setAlignment(Qt::AlignCenter);
  verticalLayout->addStretch();
  verticalLayout->addWidget(title);
  verticalLayout->addWidget(image);
  verticalLayout->addWidget(subtitle);
  verticalLayout->addStretch();

  // Bottom of app
  QStatusBar *statusBar = new QStatusBar(this);
  statusBar->showMessage(QString("Dark Mode: %1").arg(m_isDarkMode), 0);
  setStatusBar(statusBar);
}

QMenuBar *MainWindow::CreateMenuBar() {
  // QT behaves differently on Mac than on Windows/Linux when it comes to menu
  // bars. Toggle setNativeMenuBar depending on OS.
  QMenuBar *menuBar = new QMenuBar(this);
  QMenu *fileMenu = menuBar->addMenu("File");
  fileMenu->addAction("Exit", this, &QMainWindow::close);
  menuBar->setNativeMenuBar(false);
  return menuBar;
}

QLabel *MainWindow::CreateTitle() {
  QLabel *title = new QLabel("Hello World!", this);
  title->setAlignment(Qt::AlignCenter);
  title->setStyleSheet(QString("QLabel {"
                               "  font-size: 28px;"
                               "  font-weight: bold;"
                               "  color: %1;"
                               "}")
                           .arg(m_textColor));
  return title;
}

QLabel *MainWindow::CreateSubtitle() {
  QLabel *subtitle = new QLabel("Est. 2026", this);
  subtitle->setAlignment(Qt::AlignCenter);
  subtitle->setStyleSheet(QString("QLabel {"
                                  "  font-size: 11px;"
                                  "  font-weight: normal;"
                                  "  color: %1;"
                                  "}")
                              .arg(m_textColor));
  return subtitle;
}

QLabel *MainWindow::CreateCenterImage() {
  QLabel *image = new QLabel(this);
  QPixmap pixmap(":/images/globe.png");
  pixmap =
      pixmap.scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  image->setPixmap(pixmap);
  image->setFixedSize(250, 250);
  return image;
}
