#include "MainWindowQml.h"
#include <QQmlEngine>
#include <Qt>

MainWindowQml::MainWindowQml(bool isDarkMode)
    : QObject(nullptr), m_view(nullptr), m_isDarkMode(isDarkMode) {
  m_view = Build();
  m_view->setSource(QUrl("qrc:///Qml/Main.qml"));
  m_view->setGeometry(0, 0, 800, 800);
}

void MainWindowQml::show() const { m_view->show(); }

QQuickView *MainWindowQml::Build() const {
  QQuickView *view = new QQuickView(nullptr, nullptr);
  QQmlEngine *engine = view->engine();

  // For importing QML modules directly from QRC
  // see https://stackoverflow.com/a/49326965
  engine->addImportPath(QString("qrc:///"));

  view->setColor(Qt::transparent);
  view->setFlags(Qt::Widget);
  view->setResizeMode(QQuickView::SizeRootObjectToView);
  view->setPosition(0, 0);

  return view;
}
