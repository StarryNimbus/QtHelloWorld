# QtHelloWorld
Simple QT app to print "Hello World".


## To build:
1. cmake -S . -B build
2. cmake --build build

## Including MainWindow.h when registing files with target
Best practice for Qt projects: always list headers that contain Q_OBJECT.
Q_OBJECT must be processed by the MOC. If the MOC does not run, we'll see linker
errors. CMake’s AUTOMOC cannot process what it does not see.
