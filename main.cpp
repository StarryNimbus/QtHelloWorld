#include "MainWindow.h"
#include "MainWindowQml.h"
#include <QApplication>
#include <QColor>
#include <QPalette>

bool isDarkMode(QApplication &app) {
  const QPalette palette = app.palette();
  QColor windowColor = palette.color(QPalette::Window);

  // Perceptual lightness (0–255)
  // Lightness is 0 (black) .. 255 (white)
  // Convention: <128 is dark mode, >=128 is light mode
  int lightness = windowColor.lightness();
  return lightness < 128;
}

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  bool darkMode = isDarkMode(app) ? true : false;
  qDebug() << "Dark Mode: " << darkMode;

  MainWindow mainWindow(darkMode);
  MainWindowQml mainWindowQml(darkMode);

  if (argc > 1) {
    QString arg = QString(argv[1]).toLower();
    if (arg == "qml") {
      mainWindowQml.show();
    } else if (arg == "qwidget") {
      mainWindow.show();
    } else {
      qWarning("Unknown argument: %s. Falling back to QWidgets",
               arg.toUtf8().constData());
      mainWindow.show();
    }
  } else {
    qWarning("No argument passed in. Falling back to QWidgets");
    mainWindow.show();
  }

  return app.exec();
}
