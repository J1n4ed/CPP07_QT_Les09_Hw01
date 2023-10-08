cmake_minimum_required(VERSION 3.5)

project(PreUDPsocket VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 COMPONENTS Widgets REQUIRED Network Concurrent)


set(PROJECT_SOURCES
        ${CMAKE_SOURCE_DIR}/source/main.cpp
        ${CMAKE_SOURCE_DIR}/source/mainwindow.cpp
        ${CMAKE_SOURCE_DIR}/headers/mainwindow.h
        ${CMAKE_SOURCE_DIR}/source/mainwindow.ui
        ${CMAKE_SOURCE_DIR}/headers/udpworker.h
        ${CMAKE_SOURCE_DIR}/source/udpworker.cpp
        ${CMAKE_SOURCE_DIR}/headers/about.h
        ${CMAKE_SOURCE_DIR}/source/about.cpp
        ${CMAKE_SOURCE_DIR}/source/about.ui
        ${CMAKE_SOURCE_DIR}/resources/resources.qrc
)


qt_add_executable(PreUDPsocket
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)


target_link_libraries(PreUDPsocket PRIVATE Qt6::Widgets Qt6::Network Qt6::Concurrent)



qt_finalize_executable(PreUDPsocket)
