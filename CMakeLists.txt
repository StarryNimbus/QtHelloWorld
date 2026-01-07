cmake_minimum_required(VERSION 3.16) # Qt6 needs CMake 3.16+
project(QtHelloWorld VERSION 0.1 DESCRIPTION HelloWorld LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automatic handling of moc, uic, rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF) # currently not using .ui files
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Widgets)

add_executable(QtHelloWorld
    resources.qrc
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindowQml.cpp
    MainWindowQml.h
)

target_link_libraries(QtHelloWorld PRIVATE Qt6::Core Qt6::Gui Qt6::Quick Qt6::Widgets)
