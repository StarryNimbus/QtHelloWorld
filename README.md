# QtHelloWorld
Simple QT app to print "Hello World".


## To build:
1. cmake -S . -B build
2. cmake --build build

## Including MainWindow.h when registing files with target
It is probably safe to exclude MainWindow.h from the CMakeLists.txt because the
header will be discovered through dependency scanning and run MOC on it.
However, this depends on the CMake version, whether the header is reachable via
include paths, and whether Q_OBJECT is only in the header (not the cpp).

Q_OBJECT must be processed by the MOC. If the MOC does not run, we'll see linker
errors.

CMake’s AUTOMOC cannot process what it does not see.

Explicitly listing the header:
- Removes ambiguity
- Guarantees moc runs
- Makes the build deterministic

Best practice for Qt projects: always list headers that contain Q_OBJECT.
