cmake_minimum_required(VERSION 3.16)
project(qtapp LANGUAGES CXX)
include(../qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ../../../bin)

qt_standard_project_setup()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
    Core
    Gui
    Widgets
    WebEngineWidgets
    WebSockets
)

file(GLOB PROJECT_SOURCES
    ./*.cpp
    ./*.h
    ./*.ui
    ./http-server/*.cpp
    ./http-server/*.h
)

qt_add_executable(qtapp ${PROJECT_SOURCES})

set_target_properties(qtapp
    PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(qtapp
    PUBLIC
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::WebEngineWidgets
    Qt5::WebSockets
)
