# QtHelloWorld
A minimal **Qt 6 “Hello World” application** created as a clean, public starting point for my portfolio.

This project is intentionally simple. Its goal is not to demonstrate advanced features, but to show a correct, modern Qt setup using **CMake**, **Qt 6**, and both **QWidget** and **QML** frontends.

---

## What this project demonstrates

- Modern **Qt 6 + CMake** project structure
- Ability to build and run a Qt application from source
- Support for **both QWidget and QML UIs**
- Proper use of resources (icons, images)
- Clean, minimal code intended to be easy to read and extend

This repository serves as a **baseline reference project**, not a feature showcase.

---

## Technologies used

- C++17
- CMake
- Qt 6
    - Qt Widgets
    - Qt Quick / QML
    - Qt Resource System (QRC)

---

## Screenshots

### QWidget (Light Mode)
![QWidget Light](screenshots/qwidgetLight.png)

### QWidget (Dark Mode)
![QWidget Dark](screenshots/qwidgetDark.png)

### Qml (Light Mode)
![QWidget Light](screenshots/qmlLight.png)

### Qml (Dark Mode)
![QWidget Dark](screenshots/qmlDark.png)
---

## Build requirements

- **Qt 6.x**
- **CMake 3.16+**
- A C++17-compatible compiler

Tested with:
- macOS
- Qt 6.x
- Apple Clang

---

## Building the project

```bash
# From the project root directory, run:
cmake -S . -B build -G "Ninja"
ninja -C build
```

## Additional Notes
### Including MainWindow.h when registing files with target
Best practice for Qt projects: always list headers that contain Q_OBJECT.
Q_OBJECT must be processed by the MOC. If the MOC does not run, we'll see linker
errors. CMake’s AUTOMOC cannot process what it does not see.
