cmake_minimum_required(VERSION 3.5)

project(car VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate and configure Qt
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    n.h
    n.cpp
    car.h
    car.cpp
    scen.h
    scen.cpp
)

# Specify the path to the resource file
set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/images)
set(PROJECT_RESOURCES ${RESOURCES_DIR}/car.qrc)

# Use Qt's rcc tool to compile the resource file
qt5_add_resources(PROJECT_RESOURCES_RCC ${PROJECT_RESOURCES})

add_executable(car
    ${PROJECT_SOURCES}
    ${PROJECT_RESOURCES_RCC}
)

target_link_libraries(car PRIVATE Qt5::Widgets)

set_target_properties(car PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS car
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
